#include "register.h"
#include<QGuiApplication>
#include<QQmlApplicationEngine>
#include<QQmlContext>

#include "ui/duck.h"
#include "ui/mainwindow.h"
#include "ui/minimap.h"
#include "ui/display.h"
#include "ui/inventory.h"

using namespace nork::ui;

#define REGISTER(ty) qmlRegisterType<ty>(ns, ver_minor, ver_major, #ty)

void ise::nork::register_types(const char* ns, int ver_minor, int ver_major){
    REGISTER(MainWindow);
    REGISTER(MiniMapController);
    REGISTER(DisplayController);
    REGISTER(DuckController);
    REGISTER(DuckData);
    REGISTER(InventoryController);
    REGISTER(DuckInventoryEntry);
}
