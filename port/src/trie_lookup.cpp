/* trie_lookup.cpp -- surface -> dictionary-id lookup table.
 *
 * The original library searches a MARISA LOUDS trie.  For the port we
 * precompute the same mapping (surface -> record id) from the shipped
 * dictionary with tools/gen_lookup.mjs, which keeps the runtime simple and
 * avoids re-implementing the (modified) MARISA search code.
 *
 * Table format:
 *   "K2KL", u32 count, u32 reserved
 *   count x { u32 key_len_in_u16, u32 id, key_len_in_u16 * u16le key }
 */
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <unordered_map>
#include <vector>

namespace {

struct Lookup {
    std::unordered_map<std::u16string, uint32_t> map;
    size_t maxLen = 0;
    bool loaded = false;
};

Lookup &lookup()
{
    static Lookup l;
    return l;
}

} // namespace

extern "C" {

int aq_lookup_load(const char *path)
{
    if (!path)
        return 1;
    FILE *fp = fopen(path, "rb");
    if (!fp)
        return 1;
    if (fseek(fp, 0, SEEK_END) != 0) { fclose(fp); return 1; }
    long n = ftell(fp);
    if (n < 12) { fclose(fp); return 1; }
    if (fseek(fp, 0, SEEK_SET) != 0) { fclose(fp); return 1; }
    std::vector<unsigned char> buf((size_t)n);
    if (fread(buf.data(), 1, buf.size(), fp) != buf.size()) {
        fclose(fp);
        return 1;
    }
    fclose(fp);
    if (memcmp(buf.data(), "K2KL", 4) != 0)
        return 1;
    uint32_t count;
    memcpy(&count, buf.data() + 4, 4);
    Lookup &l = lookup();
    l.map.clear();
    l.map.reserve(count);
    l.maxLen = 1;
    size_t off = 12;
    for (uint32_t i = 0; i < count; i++) {
        if (off + 8 > buf.size())
            break;
        uint32_t klen, id;
        memcpy(&klen, buf.data() + off, 4);
        memcpy(&id, buf.data() + off + 4, 4);
        off += 8;
        if (off + (size_t)klen * 2 > buf.size())
            break;
        std::u16string key((const char16_t *)(buf.data() + off), klen);
        off += (size_t)klen * 2;
        l.map.emplace(std::move(key), id);
        if (klen > l.maxLen)
            l.maxLen = klen;
    }
    l.loaded = !l.map.empty();
    return l.loaded ? 0 : 1;
}

int aq_lookup_prefix(const uint16_t *key, int units, int *outLen, uint32_t *outId)
{
    Lookup &l = lookup();
    if (!l.loaded || !key || units <= 0)
        return 0;
    int cap = units;
    if ((size_t)cap > l.maxLen)
        cap = (int)l.maxLen;
    for (int len = cap; len >= 1; len--) {
        auto it = l.map.find(std::u16string((const char16_t *)key, (size_t)len));
        if (it != l.map.end()) {
            *outLen = len;
            *outId = it->second;
            return 1;
        }
    }
    return 0;
}

int aq_lookup_ready(void)
{
    return lookup().loaded ? 1 : 0;
}

} // extern "C"
