#ifndef NORK_LOCATION_H
#define NORK_LOCATION_H

#include "database/database.tcc"
#include "item/duck.h"
#include "item/item.h"
#include <string>
#include <vector>
namespace nork {
class Location {
  public:
    Location(std::string name, std::string scene_path);

    std::string get_name();
    std::string get_scene();

    std::string getId() { return this->name; }

    std::vector<Item> items = std::vector<Item>();

  private:
    std::string name;
    std::string scene;
};

using LocationStore = Database<Location>;


struct DucksAndLocations{
  LocationStore locations;
  DuckInstanceDatabase ducks;
};

} // namespace nork



#endif // !NORK_LOCATION_H
