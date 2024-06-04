#ifndef NORK_ITEM_DUCK_H
#define NORK_ITEM_DUCK_H

#include "database/database.tcc"
#include <cstdint>
#include <libintl.h>
#include <string>
namespace nork {

///
/// Catalogs a duck type, which may have many instances
///
class DuckClass {
  public:
    std::string id;
    std::string name;
    std::string description;
    std::string texture_path;

    std::string getId() { return this->id; }

    DuckClass(std::string id, std::string name, std::string description, std::string texture)
        : id(id), name(name), description(description), texture_path(texture) {}
};
std::string next_duckinstance_id();

///
/// Specific Instance of a duck class
/// keeps track of the duck via id,
/// and also keeps instance specific data such as position
///
struct DuckInstance {
    std::string class_id;
    std::string uid;
    bool claimed = false;
    std::string getId() { return this->uid; }

    DuckClass* get_class();
};


struct DuckInstancePlacement{
  uint16_t x;
  uint16_t y;
  std::string instance_id;
};


using DuckDatabase = Database<DuckClass>;
using DuckInstanceDatabase = Database<DuckInstance>;
} // namespace nork

#endif // !NORK_ITEM_DUCK_H
