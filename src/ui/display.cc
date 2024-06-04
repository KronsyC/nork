#include "ui/display.h"
#include "item/duck.h"
#include "loader.h"
#include "qlogging.h"
#include "qobject.h"
#include <iostream>
#include "qtmetamacros.h"

using namespace nork;


void ui::DisplayController::redraw_ducks(){
  auto& duck_classes = load_resources().ducks;
  auto& duck_instances = load_resources().duck_instances;
  for(auto duck : m_ducks){
    delete duck;
  }
  m_ducks.clear();
  for(auto& item : current_location->items){
    if(DuckInstancePlacement* duck = item.duck()){
      auto di = duck_instances.get(duck->instance_id);

      if(di->claimed){
        // Already claimed / dont render
        continue;
      }
      auto dc = duck_classes.get(di->class_id);
      auto id = QString::fromStdString(dc->id);
      auto name = QString::fromStdString(dc->name);
      auto desc = QString::fromStdString(dc->description);
      auto tp = QString::fromStdString(dc->texture_path);
      auto x_pos = duck->x;
      auto y_pos = duck->y;

      ui::DuckData* display = new ui::DuckData(di, x_pos, y_pos, this);
      this->m_ducks.push_back(display);
    } 
  }
  emit ducksChanged();
}

void ui::DisplayController::on_event(DuckClaimEvent& event){
  redraw_ducks();

  emit ducksChanged();
}

void ui::DisplayController::on_event(LocationChangeEvent& event){
  std::cout << "Display update " << event.new_location_id << std::endl;
  this->current_location = load_resources().locations.get(event.new_location_id);
  redraw_ducks();
  emit locationUpdate(QString::fromStdString(event.new_location_id));
  emit sceneURLChanged();
}


ui::DisplayController::DisplayController(QObject* parent) : QObject(parent) {
  LocationChangePublisher::get().register_listener(this);
  DuckClaimPublisher::get().register_listener(this);
  LocationChangeEvent e("loc.south_wing");
  this->on_event(e);
}


ui::DisplayController::~DisplayController(){
  LocationChangePublisher::get().remove_listener(this);
  DuckClaimPublisher::get().remove_listener(this);
}
