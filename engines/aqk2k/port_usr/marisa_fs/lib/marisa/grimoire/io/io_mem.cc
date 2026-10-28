#include <string.h>
#include "marisa/grimoire/io/mapper.h"
#include "marisa/grimoire/io/reader.h"
#include "marisa/grimoire/io/writer.h"

namespace marisa { namespace grimoire { namespace io {

Mapper::Mapper() : ptr_(0), size_(0), pos_(0) {}
Mapper::~Mapper() {}
void Mapper::open(const void *ptr, std::size_t size) {
  MARISA_THROW_IF((ptr == 0) && (size != 0), MARISA_NULL_ERROR);
  ptr_ = ptr; size_ = size; pos_ = 0;
}
void Mapper::seek(std::size_t size) {
  MARISA_THROW_IF(!is_open(), MARISA_STATE_ERROR);
  MARISA_THROW_IF(size > size_ - pos_, MARISA_IO_ERROR);
  pos_ += size;
}
bool Mapper::is_open() const { return ptr_ != 0 || size_ == 0; }
void Mapper::clear() { ptr_ = 0; size_ = pos_ = 0; }
void Mapper::swap(Mapper &rhs) {
  marisa::swap(ptr_, rhs.ptr_); marisa::swap(size_, rhs.size_); marisa::swap(pos_, rhs.pos_);
}
const void *Mapper::map_data(std::size_t size) {
  MARISA_THROW_IF(!is_open(), MARISA_STATE_ERROR);
  MARISA_THROW_IF(size > size_ - pos_, MARISA_IO_ERROR);
  const void *p = static_cast<const unsigned char *>(ptr_) + pos_;
  pos_ += size;
  return p;
}

Reader::Reader() : ptr_(0), size_(0), pos_(0) {}
Reader::~Reader() {}
void Reader::open(const void *ptr, std::size_t size) {
  MARISA_THROW_IF((ptr == 0) && (size != 0), MARISA_NULL_ERROR);
  ptr_ = static_cast<const unsigned char *>(ptr); size_ = size; pos_ = 0;
}
void Reader::seek(std::size_t size) {
  MARISA_THROW_IF(!is_open(), MARISA_STATE_ERROR);
  MARISA_THROW_IF(size > size_ - pos_, MARISA_IO_ERROR);
  pos_ += size;
}
bool Reader::is_open() const { return ptr_ != 0 || size_ == 0; }
void Reader::clear() { ptr_ = 0; size_ = pos_ = 0; }
void Reader::swap(Reader &rhs) {
  marisa::swap(ptr_, rhs.ptr_); marisa::swap(size_, rhs.size_); marisa::swap(pos_, rhs.pos_);
}
void Reader::read_data(void *buf, std::size_t size) {
  MARISA_THROW_IF(!is_open(), MARISA_STATE_ERROR);
  MARISA_THROW_IF(size > size_ - pos_, MARISA_IO_ERROR);
  if (size) memcpy(buf, ptr_ + pos_, size);
  pos_ += size;
}

Writer::Writer() : buf_(0), size_(0), pos_(0) {}
Writer::~Writer() {}
void Writer::open(void *buf, std::size_t size) {
  MARISA_THROW_IF((buf == 0) && (size != 0), MARISA_NULL_ERROR);
  buf_ = static_cast<unsigned char *>(buf); size_ = size; pos_ = 0;
}
void Writer::seek(std::size_t size) {
  MARISA_THROW_IF(!is_open(), MARISA_STATE_ERROR);
  MARISA_THROW_IF(size > size_ - pos_, MARISA_IO_ERROR);
  if (size) memset(buf_ + pos_, 0, size);
  pos_ += size;
}
bool Writer::is_open() const { return buf_ != 0 || size_ == 0; }
void Writer::clear() { buf_ = 0; size_ = pos_ = 0; }
void Writer::swap(Writer &rhs) {
  marisa::swap(buf_, rhs.buf_); marisa::swap(size_, rhs.size_); marisa::swap(pos_, rhs.pos_);
}
void Writer::write_data(const void *data, std::size_t size) {
  MARISA_THROW_IF(!is_open(), MARISA_STATE_ERROR);
  MARISA_THROW_IF(size > size_ - pos_, MARISA_IO_ERROR);
  if (size) memcpy(buf_ + pos_, data, size);
  pos_ += size;
}

}}}
