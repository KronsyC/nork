#include "ui/display.h"
#include "item/duck.h"
#include "loader.h"
#include "location/location_change_pub.h"
#include "qlogging.h"
#include "qobject.h"
#include <iostream>
#include <memory>
#include "pubsub/publisher.h"
#include "qtmetamacros.h"

using namespace nork;


void ui::DisplayController::on_event(LocationChangeEvent& event){
  std::cout << "Display update " << event.new_location_id << std::endl;
  this->current_location = load_resources().locations.get(event.new_location_id);
  auto& duck_classes = load_resources().ducks;

  for(auto duck : m_ducks){
    delete duck;
  }
  m_ducks.clear();
  for(auto& item : current_location->items){
    if(DuckInstance* duck = item.duck()){
      auto dc = duck_classes.get(duck->class_id);
      auto id = QString::fromStdString(dc->id);
      auto name = QString::fromStdString(dc->name);
      auto desc = QString::fromStdString(dc->description);
      auto tp = QString::fromStdString(dc->texture_path);
      auto x_pos = duck->x_pos;
      auto y_pos = duck->y_pos;

      qDebug() << tp;
      std::cout << "DUCK <"<<duck->x_pos << ", " << duck->y_pos << ">" << std::endl;
      std::cout << dc->name << std::endl;
      ui::DuckData* display = new ui::DuckData(id, name, desc, tp, x_pos, y_pos, duck->uid, this);
      this->m_ducks.push_back(display);
    } 
  }
  emit ducksChanged();
  emit locationUpdate(QString::fromStdString(event.new_location_id));
  emit sceneURLChanged();
}


ui::DisplayController::DisplayController(QObject* parent) : QObject(parent) {
  LocationChangePublisher::get().register_listener(this);
  LocationChangeEvent e("loc.south_wing");
  this->on_event(e);
}


ui::DisplayController::~DisplayController(){
  LocationChangePublisher::get().remove_listener(this);
}
