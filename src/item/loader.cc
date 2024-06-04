#include "loader.h"
#include "item/duck.h"
#include "item/encounter.h"


using namespace nork;



template<>
DuckDatabase Loader<DuckDatabase>::load(){
  DuckDatabase ddb;

  for(auto kvp : this->data.items()){
    std::string duck_id = kvp.key();
    json duck_info = kvp.value();

    std::string duck_name = duck_info["name"];
    std::string duck_description = duck_info["description"];
    std::string duck_texture = duck_info["texture"];

    DuckClass duck(duck_id, duck_name, duck_description, duck_texture);
    ddb.add(duck);
  }
  return ddb;
}


template<>
EncounterDatabase Loader<EncounterDatabase>::load(){
  EncounterDatabase edb;
  return edb;
}

