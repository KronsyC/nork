#include "location/location.h"


using namespace nork;



Location::Location(std::string name, std::string scene){
  this->name = name;
  this->scene = scene;
}


std::string Location::get_name(){
  return this->name;
}


std::string Location::get_scene(){
  return this->scene;
}
