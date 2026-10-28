#ifndef MARISA_GRIMOIRE_IO_WRITER_H_
#define MARISA_GRIMOIRE_IO_WRITER_H_
#include "marisa/base.h"
namespace marisa { namespace grimoire { namespace io {
class Writer {
 public:
  Writer();
  ~Writer();
  void open(void *buf, std::size_t size);
  template <typename T> void write(const T &obj) { write_data(&obj, sizeof(T)); }
  template <typename T> void write(const T *objs, std::size_t num_objs) {
    MARISA_THROW_IF((objs == NULL) && (num_objs != 0), MARISA_NULL_ERROR);
    MARISA_THROW_IF(num_objs > (MARISA_SIZE_MAX / sizeof(T)), MARISA_SIZE_ERROR);
    write_data(objs, sizeof(T) * num_objs);
  }
  void seek(std::size_t size);
  bool is_open() const;
  std::size_t pos() const { return pos_; }
  void clear();
  void swap(Writer &rhs);
 private:
  unsigned char *buf_;
  std::size_t size_, pos_;
  void write_data(const void *data, std::size_t size);
  Writer(const Writer &);
  Writer &operator=(const Writer &);
};
}}}
#endif
