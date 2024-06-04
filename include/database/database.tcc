#ifndef NORK_DATABASE_H
#define NORK_DATABASE_H

#include "indexable.h"
#include <unordered_map>

namespace nork {

///
/// Generic database class for tracking id'd types
///
template <Indexable T> class Database {
  private:
    using Items = std::unordered_map<std::string, T>;

  public:
    Database() { this->items = Database::Items(); }

    void add(T element) {

        std::string id = element.getId();

        this->items.insert({id, element});
    }

    bool remove(std::string key) {
        auto erased = this->items.erase(key);
        return erased == 1;
    }

    T* get(std::string key) {

        auto found = this->items.find(key);

        if (found == this->items.end()) {
            return nullptr;
        }
        return &found->second;
    }

  private:
    Items items;
};
} // namespace nork

#endif // !NORK_DATABASE_H
