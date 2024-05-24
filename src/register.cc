#include "register.h"
#include<QGuiApplication>
#include<QQmlApplicationEngine>
#include<QQmlContext>

#include "ui/mainwindow.h"

using namespace nork::ui;

void ise::nork::register_types(const char* ns, int ver_minor, int ver_major){
    qmlRegisterType<MainWindow>("ise.nork", 1, 0, "MainWindow");
}
