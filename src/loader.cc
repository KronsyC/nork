#include "loader.h"
#include "item/duck.h"
#include "item/encounter.h"
#include "location/location.h"
#include <QByteArray>
#include<QFile>
using namespace nork;

const char* DUCKS_SPEC = ":/ducks/spec.json";
const char* LOCATIONS_SPEC = ":/locations/spec.json";
const char* ENCOUNTERS_SPEC = ":/encounters/spec.json";


QByteArray read_file(const char* path){
  QFile file = QFile(path);
  file.open(QIODevice::ReadOnly);

  QByteArray file_data = file.readAll();

  return file_data;

}


#define LOAD( SPECFILE, TYPE ) \
  ([]() { \
    QByteArray data = read_file(SPECFILE); \
    json jdata = json::parse(data); \
    Loader<TYPE> loader(jdata); \
    TYPE loaded = loader.load(); \
    return loaded; \
  })()

LoadedResources& nork::load_resources() {

  static bool resources_loaded = false;


  if(!resources_loaded){
    auto locations = LOAD(LOCATIONS_SPEC, LocationStore);
    auto ducks = LOAD(DUCKS_SPEC, DuckDatabase);
    auto encounters = LOAD(ENCOUNTERS_SPEC, EncounterDatabase);



    nork::LOADED_RESOURCES = LoadedResources{
      ducks,
      encounters,
      locations,
    };
    resources_loaded = true;
  }

  return nork::LOADED_RESOURCES;
}
