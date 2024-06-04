#include "item/duck.h"



uint16_t nork::next_duckinstance_id(){
  static uint16_t current_instance = 1;
  return current_instance++;
}
