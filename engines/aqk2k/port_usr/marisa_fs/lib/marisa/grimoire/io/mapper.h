#ifndef MARISA_GRIMOIRE_IO_MAPPER_H_
#define MARISA_GRIMOIRE_IO_MAPPER_H_
#include "marisa/base.h"
namespace marisa { namespace grimoire { namespace io {
class Mapper {
 public:
  Mapper();
  ~Mapper();
  void open(const void *ptr, std::size_t size);
  template <typename T> void map(T *obj) {
    MARISA_THROW_IF(obj == NULL, MARISA_NULL_ERROR);
    *obj = *static_cast<const T *>(map_data(sizeof(T)));
  }
  template <typename T> void map(const T **objs, std::size_t num_objs) {
    MARISA_THROW_IF((objs == NULL) && (num_objs != 0), MARISA_NULL_ERROR);
    MARISA_THROW_IF(num_objs > (MARISA_SIZE_MAX / sizeof(T)), MARISA_SIZE_ERROR);
    *objs = static_cast<const T *>(map_data(sizeof(T) * num_objs));
  }
  void seek(std::size_t size);
  bool is_open() const;
  void clear();
  void swap(Mapper &rhs);
 private:
  const void *ptr_;
  std::size_t size_, pos_;
  const void *map_data(std::size_t size);
  Mapper(const Mapper &);
  Mapper &operator=(const Mapper &);
};
}}}
#endif
