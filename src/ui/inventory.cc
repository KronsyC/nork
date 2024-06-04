#include "ui/inventory.h"
#include "events.h"
#include "item/duck.h"
#include "loader.h"
#include "qobject.h"
#include <string>

using namespace nork;

void ui::InventoryController::on_event(DuckClaimEvent& event) {
    DuckInstance* claimed_instance = load_resources().duck_instances.get(std::to_string(event.instance_id));
    DuckInventoryEntry* e = new DuckInventoryEntry(claimed_instance, this);
    this->entries.push_back(e);

    emit ducksChanged();
}

ui::InventoryController::InventoryController(QObject* parent) : QObject(parent) {
    DuckClaimPublisher::get().register_listener(this);
}

ui::InventoryController::~InventoryController() {
    DuckClaimPublisher::get().remove_listener(this);
}
