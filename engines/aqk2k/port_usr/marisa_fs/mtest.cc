#include "marisa/trie.h"
#include <string.h>

static const unsigned char k0[] = {0x27,0x59,0x5f,0x6c,0x38,0x62,0xda,0x7d}; // 大江戸線
static const unsigned char k1[] = {0x54,0x9b,0x06,0x74,0x99,0x6c};             // 魔理沙
static const unsigned char k2[] = {0x4d,0x30,0x83,0x30,0x8a,0x30,0xfc,0x30};
static const unsigned char k3[] = {0x27,0xff,0x24,0xff,0x27,0xff,0x24,0xff}; // ＧＤＧＤ

extern "C" int marisa_test_build(unsigned char *out, int cap) {
  marisa::Keyset ks;
  ks.push_back((const char *)k0, sizeof(k0));
  ks.push_back((const char *)k1, sizeof(k1));
  ks.push_back((const char *)k2, sizeof(k2));
  ks.push_back((const char *)k3, sizeof(k3));
  marisa::Trie t;
  t.build(ks);
  if ((int)t.io_size() > cap) return -1;
  t.write(out, t.io_size());
  return (int)t.io_size();
}

extern "C" int marisa_test_read(const unsigned char *p, int n) {
  marisa::Trie t;
  t.map(p, (size_t)n);
  return (int)t.num_keys();
}

static unsigned char g_out[65536];
extern "C" unsigned char *marisa_test_out() { return g_out; }
extern "C" int marisa_test_build_static() {
  return marisa_test_build(g_out, (int)sizeof(g_out));
}
