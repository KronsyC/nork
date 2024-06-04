#ifndef NORK_ITEM_ENCOUNTER_H
#define NORK_ITEM_ENCOUNTER_H

#include "database/database.tcc"

namespace nork {
struct EncounterInstance {
  int a;
};

class EncounterClass {
    std::string id;

  public:
    std::string getId(){
      return this->id;
    }
};

using EncounterDatabase = Database<EncounterClass>;
} // namespace nork

#endif // !NORK_ITEM_ENCOUNTER_H
