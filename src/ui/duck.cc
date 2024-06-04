#include "ui/duck.h"
#include<QDebug>
using namespace nork;



ui::DuckController::DuckController(QObject* parent) : QObject(parent){

}



void ui::DuckController::handleClaim(){
  qDebug() << "DUCK CLAIMED " << this->instance_id;
}
