#include "marisa/trie.h"
#include "marisa/grimoire/trie.h"

namespace marisa {

Trie::Trie() : trie_() {}

Trie::~Trie() {}

void Trie::build(Keyset &keyset, int config_flags) {
  scoped_ptr<grimoire::LoudsTrie> temp(new (std::nothrow) grimoire::LoudsTrie);
  MARISA_THROW_IF(temp.get() == NULL, MARISA_MEMORY_ERROR);

  temp->build(keyset, config_flags);
  trie_.swap(temp);
}

void Trie::map(const void *ptr, std::size_t size) {
  MARISA_THROW_IF((ptr == NULL) && (size != 0), MARISA_NULL_ERROR);

  scoped_ptr<grimoire::LoudsTrie> temp(new (std::nothrow) grimoire::LoudsTrie);
  MARISA_THROW_IF(temp.get() == NULL, MARISA_MEMORY_ERROR);

  grimoire::Mapper mapper;
  mapper.open(ptr, size);
  temp->map(mapper);
  trie_.swap(temp);
}

void Trie::write(void *buf, std::size_t size) const {
  MARISA_THROW_IF(trie_.get() == NULL, MARISA_STATE_ERROR);
  grimoire::Writer writer;
  writer.open(buf, size);
  trie_->write(writer);
}

bool Trie::lookup(Agent &agent) const {
  MARISA_THROW_IF(trie_.get() == NULL, MARISA_STATE_ERROR);
  if (!agent.has_state()) {
    agent.init_state();
  }
  return trie_->lookup(agent);
}

void Trie::reverse_lookup(Agent &agent) const {
  MARISA_THROW_IF(trie_.get() == NULL, MARISA_STATE_ERROR);
  if (!agent.has_state()) {
    agent.init_state();
  }
  trie_->reverse_lookup(agent);
}

bool Trie::common_prefix_search(Agent &agent) const {
  MARISA_THROW_IF(trie_.get() == NULL, MARISA_STATE_ERROR);
  if (!agent.has_state()) {
    agent.init_state();
  }
  return trie_->common_prefix_search(agent);
}

bool Trie::predictive_search(Agent &agent) const {
  MARISA_THROW_IF(trie_.get() == NULL, MARISA_STATE_ERROR);
  if (!agent.has_state()) {
    agent.init_state();
  }
  return trie_->predictive_search(agent);
}

std::size_t Trie::num_tries() const {
  MARISA_THROW_IF(trie_.get() == NULL, MARISA_STATE_ERROR);
  return trie_->num_tries();
}

std::size_t Trie::num_keys() const {
  MARISA_THROW_IF(trie_.get() == NULL, MARISA_STATE_ERROR);
  return trie_->num_keys();
}

std::size_t Trie::num_nodes() const {
  MARISA_THROW_IF(trie_.get() == NULL, MARISA_STATE_ERROR);
  return trie_->num_nodes();
}

TailMode Trie::tail_mode() const {
  MARISA_THROW_IF(trie_.get() == NULL, MARISA_STATE_ERROR);
  return trie_->tail_mode();
}

NodeOrder Trie::node_order() const {
  MARISA_THROW_IF(trie_.get() == NULL, MARISA_STATE_ERROR);
  return trie_->node_order();
}

bool Trie::empty() const {
  MARISA_THROW_IF(trie_.get() == NULL, MARISA_STATE_ERROR);
  return trie_->empty();
}

std::size_t Trie::size() const {
  MARISA_THROW_IF(trie_.get() == NULL, MARISA_STATE_ERROR);
  return trie_->size();
}

std::size_t Trie::total_size() const {
  MARISA_THROW_IF(trie_.get() == NULL, MARISA_STATE_ERROR);
  return trie_->total_size();
}

std::size_t Trie::io_size() const {
  MARISA_THROW_IF(trie_.get() == NULL, MARISA_STATE_ERROR);
  return trie_->io_size();
}

void Trie::clear() {
  Trie().swap(*this);
}

void Trie::swap(Trie &rhs) {
  trie_.swap(rhs.trie_);
}

}  // namespace marisa

