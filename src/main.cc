#include<QGuiApplication>
#include<QQmlApplicationEngine>
#include<QQmlContext>
#include "register.h"

int main(int argc, char **argv) {

    QGuiApplication app(argc, argv);


    QQmlApplicationEngine engine;

    ise::nork::register_types("ise.nork", 0, 1);
    
    engine.load(QUrl(QStringLiteral("qrc:/mainwindow.qml")));

    if(engine.rootObjects().isEmpty()){
      return -1;
    }

    return app.exec();
    return 0;
}
