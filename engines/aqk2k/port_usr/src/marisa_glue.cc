/* C interface to the freestanding marisa-trie 0.2.6 subset. */
#include "marisa/trie.h"
#include <stdlib.h>
#include <string.h>

static marisa::Trie g_trie;
static bool g_open = false;

extern "C" int mfs_build_alloc(const void *const *keys, const unsigned *lens,
                               unsigned n, void **out, unsigned *out_len) {
  marisa::Keyset ks;
  for (unsigned i = 0; i < n; i++)
    ks.push_back((const char *)keys[i], (size_t)lens[i]);
  g_trie.clear();
  g_trie.build(ks);
  size_t sz = g_trie.io_size();
  void *buf = malloc(sz ? sz : 1);
  if (!buf) return -1;
  g_trie.write(buf, sz);
  *out = buf;
  *out_len = (unsigned)sz;
  g_open = true;
  return 0;
}

extern "C" int mfs_open(const void *data, unsigned len) {
  g_trie.clear();
  g_trie.map(data, (size_t)len);
  g_open = true;
  return 0;
}

extern "C" void mfs_close(void) {
  g_trie.clear();
  g_open = false;
}

extern "C" unsigned mfs_num_keys(void) {
  return g_open ? (unsigned)g_trie.num_keys() : 0;
}

extern "C" int mfs_lookup(const void *key, unsigned len, int *id) {
  if (!g_open) return -1;
  marisa::Agent a;
  a.set_query((const char *)key, (size_t)len);
  if (!g_trie.lookup(a)) return -1;
  *id = (int)a.key().id();
  return 0;
}

extern "C" int mfs_reverse_copy(unsigned id, void *buf, unsigned cap, unsigned *len) {
  if (!g_open || id >= g_trie.num_keys()) return -1;
  marisa::Agent a;
  a.set_query((size_t)id);
  g_trie.reverse_lookup(a);
  unsigned n = (unsigned)a.key().length();
  if (n > cap) return -2;
  if (n) memcpy(buf, a.key().ptr(), n);
  *len = n;
  return 0;
}
