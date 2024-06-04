#ifndef NORK_LOADER_H
#define NORK_LOADER_H 


#include "item/duck.h"
#include "item/encounter.h"
#include "location/location.h"
#include "json.hpp"

using json = nlohmann::json;

namespace nork{


  ///
  /// Resource Loader Class for JSON data 
  /// 
  /// USAGE:
  /// Provide a specialization of this class for your desired resource in a source file  
  /// and modify src/loader.cc to introduce the new loaded resource
  ///
  template<typename Loaded>
  class Loader{
  public:
    Loader(json data){
      this->data = data;
    }


    Loaded load();
    

  protected:
    json data;
  };

  struct LoadedResources{
    DuckDatabase ducks;
    EncounterDatabase encounters;
    LocationStore locations;
    DuckInstanceDatabase duck_instances;
  };



  LoadedResources& load_resources();


  static LoadedResources LOADED_RESOURCES;
}

#endif
