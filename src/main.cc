#include "qguiapplication.h"
#include <iostream>

#include<QGuiApplication>
#include<QQmlApplicationEngine>

int main(int argc, char **argv) {

    QGuiApplication app(argc, argv);


    QQmlApplicationEngine engine;


    engine.load(QUrl(QStringLiteral("qrc:/mainscreen.qml")));


    if(engine.rootObjects().isEmpty()){
      return -1;
    }

    return app.exec();
    return 0;
}
