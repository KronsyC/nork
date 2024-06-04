#include "ui/duck.h"
#include "loader.h"
#include "events.h"
#include<QDebug>
#include <string>
using namespace nork;



ui::DuckController::DuckController(QObject* parent) : QObject(parent){

}



void ui::DuckController::handleClaim(){
  DuckInstance* claimed_duck = load_resources().duck_instances.get(std::to_string(this->instance_id));

  claimed_duck->claimed = true;
  DuckClaimPublisher::get().publish(DuckClaimEvent{this->instance_id}); 
}
