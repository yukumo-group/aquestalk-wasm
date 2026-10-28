/* Memory-buffer AqUsrDic Import/Export built on marisa-trie 0.2.6. */
#include "shim.h"

extern int mfs_build_alloc(const void *const *keys, const unsigned *lens,
                           unsigned n, void **out, unsigned *out_len);
extern int mfs_open(const void *data, unsigned len);
extern void mfs_close(void);
extern unsigned mfs_num_keys(void);
extern int mfs_lookup(const void *key, unsigned len, int *id);
extern int mfs_reverse_copy(unsigned id, void *buf, unsigned cap, unsigned *len);

typedef struct { unsigned char *p; unsigned len, cap; } Buf;

static int buf_reserve(Buf *b, unsigned need) {
  if (need <= b->cap) return 0;
  unsigned cap = b->cap ? b->cap : 256;
  while (cap < need) cap += cap / 2 + 64;
  unsigned char *np = (unsigned char *)realloc(b->p, cap);
  if (!np) return -1;
  b->p = np; b->cap = cap; return 0;
}
static int buf_add(Buf *b, const void *p, unsigned n) {
  if (buf_reserve(b, b->len + n)) return -1;
  if (n) memcpy(b->p + b->len, p, n);
  b->len += n; return 0;
}
static int buf_u32(Buf *b, unsigned v) { unsigned char x[4] = {(unsigned char)v, (unsigned char)(v>>8), (unsigned char)(v>>16), (unsigned char)(v>>24)}; return buf_add(b, x, 4); }
static unsigned rd32(const unsigned char *p) { return p[0] | (p[1]<<8) | (p[2]<<16) | ((unsigned)p[3]<<24); }
static unsigned rd16(const unsigned char *p) { return p[0] | (p[1]<<8); }

/* ---- UTF-8 <-> UTF-16 ---- */
static int utf8_to_u16(const unsigned char *s, unsigned n, uint16_t **out, unsigned *outn) {
  uint16_t *d = (uint16_t *)malloc((n + 1) * 2);
  if (!d) return -1;
  unsigned i = 0, k = 0;
  while (i < n) {
    unsigned c = s[i++], cp;
    if (c < 0x80) cp = c;
    else if ((c & 0xe0) == 0xc0 && i < n) cp = ((c & 0x1f) << 6) | (s[i++] & 0x3f);
    else if ((c & 0xf0) == 0xe0 && i + 1 < n) cp = ((c & 0x0f) << 12) | ((s[i] & 0x3f) << 6) | (s[i+1] & 0x3f), i += 2;
    else if ((c & 0xf8) == 0xf0 && i + 2 < n) cp = ((c & 7) << 18) | ((s[i] & 0x3f) << 12) | ((s[i+1] & 0x3f) << 6) | (s[i+2] & 0x3f), i += 3;
    else { free(d); return -2; }
    if (cp >= 0x10000) {
      cp -= 0x10000;
      d[k++] = (uint16_t)(0xd800 + (cp >> 10));
      d[k++] = (uint16_t)(0xdc00 + (cp & 0x3ff));
    } else d[k++] = (uint16_t)cp;
  }
  d[k] = 0;
  *out = d; *outn = k;
  return 0;
}

static int u16_to_utf8(const uint16_t *s, unsigned n, char **out, unsigned *outn) {
  char *d = (char *)malloc(n * 3 + 1);
  if (!d) return -1;
  unsigned i = 0, k = 0;
  while (i < n) {
    unsigned cp = s[i++];
    if (cp >= 0xd800 && cp < 0xdc00 && i < n && s[i] >= 0xdc00 && s[i] < 0xe000)
      cp = 0x10000 + ((cp - 0xd800) << 10) + (s[i++] - 0xdc00);
    if (cp < 0x80) d[k++] = (char)cp;
    else if (cp < 0x800) { d[k++] = (char)(0xc0 | (cp >> 6)); d[k++] = (char)(0x80 | (cp & 0x3f)); }
    else if (cp < 0x10000) { d[k++] = (char)(0xe0 | (cp >> 12)); d[k++] = (char)(0x80 | ((cp >> 6) & 0x3f)); d[k++] = (char)(0x80 | (cp & 0x3f)); }
    else { d[k++] = (char)(0xf0 | (cp >> 18)); d[k++] = (char)(0x80 | ((cp >> 12) & 0x3f)); d[k++] = (char)(0x80 | ((cp >> 6) & 0x3f)); d[k++] = (char)(0x80 | (cp & 0x3f)); }
  }
  d[k] = 0;
  *out = d; *outn = k;
  return 0;
}

/* ---- kana table (original image, 298 x 16-byte entries) ---- */
static const unsigned char *kana_entry(unsigned i) { return aq_image + 0x31ae0 + i * 16; }
static const uint16_t *kana_str(unsigned i) { return (const uint16_t *)(uintptr_t)(*(const uint64_t *)(const void *)kana_entry(i)); }
static unsigned kana_code(unsigned i) { return kana_entry(i)[8]; }
static unsigned u16len(const uint16_t *s) { unsigned n = 0; while (s[n]) n++; return n; }

static int kana_lookup(const uint16_t *s, unsigned n, unsigned *used, unsigned *code) {
  for (int i = 297; i >= 0; i--) {
    const uint16_t *t = kana_str((unsigned)i);
    unsigned l = u16len(t);
    if (l && l <= n) {
      unsigned j = 0; while (j < l && s[j] == t[j]) j++;
      if (j == l) { *used = l; *code = kana_code((unsigned)i); return 1; }
    }
  }
  return 0;
}

static int encode_reading(const uint16_t *s, unsigned n, unsigned char *codes, unsigned *count, unsigned *accent) {
  unsigned i = 0, c = 0, a = 0;
  while (i < n) {
    unsigned used, code;
    if (!kana_lookup(s + i, n - i, &used, &code)) return 0x136;
    if (code == 1) a = c;
    else {
      if (c >= 31) return 0x137;
      codes[c++] = (unsigned char)code;
    }
    i += used;
  }
  if (c == 0) return 0x12f;
  *count = c; *accent = a;
  return 0;
}

static int decode_codes(const unsigned char *codes, unsigned n, unsigned accent, uint16_t *out, unsigned *outn) {
  unsigned k = 0;
  for (unsigned i = 0; i < n; i++) {
    int found = 0;
    for (unsigned e = 0; e < 298; e++) {
      if (kana_code(e) == codes[i]) { const uint16_t *t = kana_str(e); while (*t) out[k++] = *t++; found = 1; break; }
    }
    if (!found) return -1;
    if (accent && i + 1 == accent) out[k++] = '\'';
  }
  out[k] = 0; *outn = k;
  return 0;
}

/* ---- system dictionary POS table ---- */
static const unsigned char *g_sys;
static unsigned g_syslen;
static int g_pos_ok;
static int32_t g_pos[28];

static int parse_pos_table(const unsigned char *d, unsigned n) {
  unsigned off = 0;
  while (off + 8 <= n) {
    const unsigned char *p = d + off;
    unsigned sz = rd32(p + 4);
    if (off + 8 + sz > n) break;
    if (!memcmp(p, "POSD", 4)) {
      const unsigned char *q = p + 8;
      if (sz >= 0x1a && !memcmp(q, "POS1", 4)) {
        unsigned cnt = rd16(q + 0x18);
        const unsigned char *arr = q + 0x1a;
        const int32_t *want = (const int32_t *)(const void *)(aq_image + 0x27ce0);
        for (unsigned i = 0; i < 28; i++) {
          unsigned j = 1;
          while (j < cnt && arr[j] != (unsigned char)want[i]) j++;
          if (j >= cnt) return -1;
          g_pos[i] = (int32_t)j;
        }
        g_pos_ok = 1;
        return 0;
      }
    }
    off += 8 + sz;
  }
  return -1;
}

int aus_set_system_dic(const void *d, unsigned n) {
  g_sys = (const unsigned char *)d; g_syslen = n; g_pos_ok = 0;
  if (!g_sys || !n || parse_pos_table(g_sys, g_syslen)) return 0xc9;
  return 0;
}

/* ---- CSV helpers ---- */
static void skip_field(const unsigned char **pp, const unsigned char *end, const unsigned char **out, unsigned *outlen) {
  const unsigned char *p = *pp;
  if (p < end && *p == '"') {
    p++;
    const unsigned char *s = p;
    /* find closing quote, handling "" */
    unsigned char *tmp = 0; unsigned k = 0, cap = 0;
    while (p < end) {
      if (*p == '"') {
        if (p + 1 < end && p[1] == '"') { if (k + 1 > cap) { cap = cap ? cap * 2 : 32; tmp = (unsigned char *)realloc(tmp, cap); } tmp[k++] = '"'; p += 2; continue; }
        p++; break;
      }
      if (k + 1 > cap) { cap = cap ? cap * 2 : 32; tmp = (unsigned char *)realloc(tmp, cap); }
      tmp[k++] = *p++;
    }
    if (tmp) { tmp[k] = 0; *out = tmp; *outlen = k; } else { *out = s; *outlen = 0; }
    while (p < end && *p != ',') p++;
    if (p < end) p++;
  } else {
    const unsigned char *s = p;
    while (p < end && *p != ',') p++;
    *out = s; *outlen = (unsigned)(p - s);
    if (p < end) p++;
  }
  *pp = p;
}

typedef struct {
  unsigned char *key; unsigned keylen;
  uint16_t *yomi; unsigned yomilen;
  unsigned char codes[32]; unsigned count, accent;
  int pos, internal;
} Ent;

static void free_ents(Ent *e, unsigned n) {
  for (unsigned i = 0; i < n; i++) { free(e[i].key); free(e[i].yomi); }
  free(e);
}

static int parse_pos_num(const unsigned char *p, unsigned n, int *out) {
  if (!n) return -1;
  unsigned v = 0;
  for (unsigned i = 0; i < n; i++) { if (p[i] < '0' || p[i] > '9') return -1; v = v * 10 + (p[i] - '0'); if (v > 100000) return -1; }
  *out = (int)v; return 0;
}

/* ---- Import ---- */
int aus_import(const char *csv, unsigned csv_len, void *out, unsigned out_cap, unsigned *out_len) {
  if (!g_pos_ok) { FUN_00108cf0(0xc9, 0); return 0xc9; }
  const unsigned char *p = (const unsigned char *)csv, *end = p + csv_len;
  Ent *ents = 0; unsigned n = 0, cap = 0;
  int err = 0;
  while (p < end) {
    const unsigned char *line = p;
    while (p < end && *p != '\n') p++;
    const unsigned char *le = p;
    if (le > line && le[-1] == '\r') le--;
    if (p < end) p++;
    if (le == line) continue;
    const unsigned char *f[3]; unsigned fl[3];
    const unsigned char *q = line;
    for (int i = 0; i < 3; i++) skip_field(&q, le, &f[i], &fl[i]);
    int pos;
    if (parse_pos_num(f[2], fl[2], &pos) || pos < 0 || pos >= 28) { err = 0x13a; break; }
    /* fields may be heap copies for quoted input */
    uint16_t *surf16 = 0, *yom16 = 0; unsigned sn = 0, yn = 0;
    if (utf8_to_u16(f[0], fl[0], &surf16, &sn) || utf8_to_u16(f[1], fl[1], &yom16, &yn)) { free(surf16); err = 0x136; break; }
    if (sn == 0) { free(surf16); free(yom16); err = 0x12d; break; }
    if (sn >= 32) { free(surf16); free(yom16); err = 0x13b; break; }
    for (unsigned i = 0; i < sn; i++) { unsigned c = surf16[i]; if (c < 0x7f || c == 0x20 || c == 0xa5 || c == 0x203e || (unsigned short)(c + 0x9f) < 0x3f) { err = 0x138; break; } if (c == 0x3000) { err = 0x139; break; } }
    if (err) { free(surf16); free(yom16); break; }
    unsigned char codes[32]; unsigned count, accent;
    err = encode_reading(yom16, yn, codes, &count, &accent);
    if (err) { free(surf16); free(yom16); break; }
    if (n == cap) { cap = cap ? cap * 2 : 16; Ent *ne = (Ent *)realloc(ents, cap * sizeof(Ent)); if (!ne) { err = 0xc9; free(surf16); free(yom16); break; } ents = ne; }
    Ent *e = &ents[n];
    e->keylen = sn * 2; e->key = (unsigned char *)malloc(e->keylen ? e->keylen : 1);
    if (!e->key) { err = 0xc9; free(surf16); free(yom16); break; }
    for (unsigned i = 0; i < sn; i++) { e->key[i*2] = (unsigned char)(surf16[i] & 0xff); e->key[i*2+1] = (unsigned char)(surf16[i] >> 8); }
    e->yomi = yom16; e->yomilen = yn;
    memcpy(e->codes, codes, count); e->count = count; e->accent = accent;
    e->pos = pos; e->internal = g_pos[pos];
    free(surf16);
    n++;
  }
  if (err) { free_ents(ents, n); FUN_00108cf0(err, 0); return err; }
  if (n == 0) { free_ents(ents, 0); FUN_00108cf0(0x12d, 0); return 0x12d; }

  const void **keys = (const void **)malloc(n * sizeof(void *));
  unsigned *lens = (unsigned *)malloc(n * sizeof(unsigned));
  for (unsigned i = 0; i < n; i++) { keys[i] = ents[i].key; lens[i] = ents[i].keylen; }
  void *tri = 0; unsigned tril = 0;
  if (mfs_build_alloc(keys, lens, n, &tri, &tril)) { free(keys); free(lens); free_ents(ents, n); FUN_00108cf0(0x194, 0); return 0x194; }
  free(keys); free(lens);

  unsigned *map = (unsigned *)malloc(n * sizeof(unsigned));
  Ent **by_id = (Ent **)malloc(n * sizeof(Ent *));
  Buf tok = {0, 0, 0};
  for (unsigned i = 0; i < n; i++) {
    int id = -1;
    if (mfs_lookup(ents[i].key, ents[i].keylen, &id) || id < 0 || (unsigned)id >= n) { err = 0x194; break; }
    by_id[id] = &ents[i];
  }
  for (unsigned id = 0; !err && id < n; id++) {
    Ent *e = by_id[id];
    map[id] = tok.len;
    unsigned char rec[7 + 32];
    rec[0] = (unsigned char)(e->internal & 0xff);
    rec[1] = (unsigned char)((e->internal >> 8) & 0x7f);
    rec[2] = rec[3] = 0;
    rec[4] = 0x40;
    rec[5] = (unsigned char)(e->count | 0x80);
    rec[6] = (unsigned char)(e->accent | 0x80);
    memcpy(rec + 7, e->codes, e->count);
    if (buf_add(&tok, rec, 7 + e->count)) err = 0xc9;
  }
  free(by_id);
  mfs_close();
  if (err) { free(map); free(tok.p); free(tri); free_ents(ents, n); FUN_00108cf0(err, 0); return err; }

  Buf outb = {0, 0, 0};
  buf_add(&outb, "HDR1", 4); buf_u32(&outb, 80);
  unsigned char hdr[80]; memset(hdr, 0, 80);
  memcpy(hdr, "AqK2K Ver.3 user dic. AQUEST Corp.", 34);
  buf_add(&outb, hdr, 80);
  unsigned tri_pad = (4 - (tril & 3)) & 3;
  buf_add(&outb, "TRI1", 4); buf_u32(&outb, 4 + tril + tri_pad); buf_u32(&outb, tril); buf_add(&outb, tri, tril);
  for (unsigned i = 0; i < tri_pad; i++) { unsigned char z = 0; buf_add(&outb, &z, 1); }
  buf_add(&outb, "MAP1", 4); buf_u32(&outb, n * 4);
  for (unsigned i = 0; i < n; i++) buf_u32(&outb, map[i]);
  unsigned tok_pad = (4 - (tok.len & 3)) & 3;
  buf_add(&outb, "TOK1", 4); buf_u32(&outb, tok.len + tok_pad); buf_add(&outb, tok.p, tok.len);
  for (unsigned i = 0; i < tok_pad; i++) { unsigned char z = 0; buf_add(&outb, &z, 1); }
  free(map); free(tok.p); free(tri); free_ents(ents, n);
  if (outb.len > out_cap) { free(outb.p); FUN_00108cf0(0x194, 0); return 0x194; }
  memcpy(out, outb.p, outb.len);
  if (out_len) *out_len = outb.len;
  free(outb.p);
  return 0;
}

/* ---- Export ---- */
typedef struct { unsigned off; char *surface; char *yomi; int pos; } XRec;
static const unsigned char *find_sec(const unsigned char *d, unsigned n, const char *tag, unsigned *size) {
  unsigned off = 0;
  while (off + 8 <= n) {
    if (!memcmp(d + off, tag, 4)) { *size = rd32(d + off + 4); if (off + 8 + *size > n) return 0; return d + off + 8; }
    unsigned sz = rd32(d + off + 4);
    if (off + 8 + sz > n) break;
    off += 8 + sz;
  }
  return 0;
}

int aus_export(const void *dic, unsigned dic_len, char *out, unsigned out_cap, unsigned *out_len) {
  if (!g_pos_ok) { FUN_00108cf0(0xc9, 0); return 0xc9; }
  const unsigned char *d = (const unsigned char *)dic; unsigned n = dic_len;
  unsigned tris, maps, toks;
  const unsigned char *tri = find_sec(d, n, "TRI1", &tris);
  const unsigned char *map = find_sec(d, n, "MAP1", &maps);
  const unsigned char *tok = find_sec(d, n, "TOK1", &toks);
  if (!tri || !map || !tok || tris < 4) { FUN_00108cf0(0xd3, 0); return 0xd3; }
  unsigned tril = rd32(tri);
  if (tril > tris - 4) { FUN_00108cf0(0xd3, 0); return 0xd3; }
  if (mfs_open(tri + 4, tril)) { FUN_00108cf0(0xd3, 0); return 0xd3; }
  unsigned nk = mfs_num_keys();
  if (maps < nk * 4) { mfs_close(); FUN_00108cf0(0xd3, 0); return 0xd3; }
  XRec *recs = (XRec *)malloc(nk * sizeof(XRec));
  int err = 0;
  for (unsigned i = 0; i < nk; i++) {
    unsigned char kbuf[256]; unsigned kl;
    if (mfs_reverse_copy(i, kbuf, sizeof(kbuf), &kl)) { err = 0xd3; break; }
    const void *kp = kbuf;
    unsigned off = rd32(map + i * 4);
    if (off + 7 > toks) { err = 0xd3; break; }
    const unsigned char *r = tok + off;
    unsigned type = r[4], count = r[5] & 0x1f, accent = r[6] & 0x3f;
    unsigned start = 7 + ((type & 4) ? 3 : 0);
    if ((type & 0xf8) != 0x40 || start + count > toks - off) { err = 0xd3; break; }
    /* key bytes are UTF-16LE */
    unsigned kn = kl / 2;
    uint16_t *ks = (uint16_t *)malloc((kn + 1) * 2);
    for (unsigned j = 0; j < kn; j++) ks[j] = (uint16_t)(((const unsigned char *)kp)[j*2] | (((const unsigned char *)kp)[j*2+1] << 8));
    ks[kn] = 0;
    char *surf = 0; unsigned sl = 0;
    if (u16_to_utf8(ks, kn, &surf, &sl)) { free(ks); err = 0xc9; break; }
    free(ks);
    uint16_t yom[32 * 2 + 1]; unsigned yn = 0;
    if (decode_codes(r + start, count, accent, yom, &yn)) { free(surf); err = 0xd3; break; }
    char *yomi = 0; unsigned yl = 0;
    if (u16_to_utf8(yom, yn, &yomi, &yl)) { free(surf); err = 0xc9; break; }
    unsigned internal = (r[1] & 0x7f) * 256 + r[0];
    int pub = -1;
    for (int j = 0; j < 28; j++) if ((unsigned)g_pos[j] == internal) { pub = j; break; }
    if (pub < 0) { free(surf); free(yomi); err = 0xd3; break; }
    recs[i].off = off; recs[i].surface = surf; recs[i].yomi = yomi; recs[i].pos = pub;
  }
  mfs_close();
  if (err) {
    for (unsigned i = 0; i < nk; i++) { free(recs[i].surface); free(recs[i].yomi); }
    free(recs); FUN_00108cf0(err, 0); return err;
  }
  for (unsigned i = 1; i < nk; i++) {
    XRec key = recs[i];
    unsigned j = i;
    while (j > 0 && recs[j-1].off > key.off) { recs[j] = recs[j-1]; j--; }
    recs[j] = key;
  }
  Buf o = {0, 0, 0};
  for (unsigned i = 0; i < nk; i++) {
    buf_add(&o, recs[i].surface, (unsigned)strlen(recs[i].surface));
    buf_add(&o, ",", 1);
    buf_add(&o, recs[i].yomi, (unsigned)strlen(recs[i].yomi));
    buf_add(&o, ",", 1);
    char num[16]; int k = 0, v = recs[i].pos;
    if (v == 0) num[k++] = '0'; else { char t[16]; int j = 0; while (v) { t[j++] = (char)('0' + v % 10); v /= 10; } while (j) num[k++] = t[--j]; }
    buf_add(&o, num, k); buf_add(&o, "\n", 1);
    free(recs[i].surface); free(recs[i].yomi);
  }
  free(recs);
  if (o.len > out_cap) { free(o.p); FUN_00108cf0(0x194, 0); return 0x194; }
  memcpy(out, o.p, o.len);
  if (out_len) *out_len = o.len;
  free(o.p);
  return 0;
}
