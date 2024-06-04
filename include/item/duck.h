#ifndef NORK_ITEM_DUCK_H
#define NORK_ITEM_DUCK_H

#include "database/database.tcc"
#include <cstdint>
#include <libintl.h>
#include <string>
namespace nork {


uint16_t next_duckinstance_id();

///
/// Specific Instance of a duck class
/// keeps track of the duck via id,
/// and also keeps instance specific data such as position
///
struct DuckInstance {
    std::string class_id;
    uint16_t x_pos;
    uint16_t y_pos;
    uint16_t uid;
};

///
/// Catalogs a duck type, which may have many instances
///
class DuckClass{
public:
    std::string id;
    std::string name;
    std::string description;
    std::string texture_path;

    std::string getId(){
      return this->id;
  }


  DuckClass(std::string id, std::string name, std::string description, std::string texture)
    : id(id),
      name(name), 
      description(description),
    texture_path(texture){
  }


};

using DuckDatabase = Database<DuckClass>;
} // namespace nork

#endif // !NORK_ITEM_DUCK_H
