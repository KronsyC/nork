#include "item/duck.h"
#include "location/location.h"
#include "loader.h"
#include <iostream>
using nork::LocationStore;
using nork::Location;
using nork::Loader;
using json = nlohmann::json;

template<>
nork::DucksAndLocations Loader<nork::DucksAndLocations>::load(){
  LocationStore locs;
  DuckInstanceDatabase didb;
  for(auto item : this->data.items()){
    std::string lname = item.key();
    json value = item.value();

    std::string scene = value["scene"];
    json items = value["items"];
    Location l(lname, scene);
    if(!items.is_null()){
      for(auto item : items.items()){
        json data = item.value();

        std::string kind = data["kind"];

        if(kind == "Duck"){
          std::string duck_class = data["class"];
          json position = data["pos"];
          uint16_t x = position["x"];
          uint16_t y = position["y"];

          std::string instance_id = nork::next_duckinstance_id();

          DuckInstance duck_instance(duck_class, instance_id);
          DuckInstancePlacement instance_placement(x, y, instance_id);

          Item duck(instance_placement);

          l.items.push_back(duck);
          didb.add(duck_instance);
        }
        else if(kind == "Encounter"){

        }

        else{
          // Nothing
        }
      }
    }

    locs.add(l);
  }


  return nork::DucksAndLocations{
    locs, didb
  };
}

