#include "item/duck.h"
#include "location/location.h"
#include "loader.h"
#include <iostream>
using nork::LocationStore;
using nork::Location;
using nork::Loader;
using json = nlohmann::json;

template<>
LocationStore Loader<LocationStore>::load(){
  LocationStore locs;
  for(auto item : this->data.items()){
    std::string lname = item.key();
    json value = item.value();

    std::string scene = value["scene"];
    json items = value["items"];
    Location l(lname, scene);
    if(!items.is_null()){
      for(auto item : items.items()){
        std::cout << item << std::endl;
        json data = item.value();

        std::string kind = data["kind"];

        if(kind == "Duck"){
          std::string duck_class = data["class"];
          json position = data["pos"];
          uint16_t x = position["x"];
          uint16_t y = position["y"];

          Item duck(DuckInstance{
            duck_class,
            x,
            y,
            nork::next_duckinstance_id()
          });

          l.items.push_back(duck);
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


  return locs;
}

