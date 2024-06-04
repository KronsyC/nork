#include "item/duck.h"
#include "loader.h"



std::string nork::next_duckinstance_id(){
  static uint16_t current_instance = 1;
  return std::to_string(current_instance++);
}


nork::DuckClass* nork::DuckInstance::get_class(){
  return load_resources().ducks.get(this->class_id);
}
