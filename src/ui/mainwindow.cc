#include "ui/mainwindow.h"
#include "qlogging.h"
#include "qobject.h"



using namespace nork::ui;


MainWindow::MainWindow(QObject* parent) : QObject(parent){}


void MainWindow::handleLeft(){
  qDebug() << "Left Clicked " << this << Qt::endl;
}
void MainWindow::handleRight(){
  qDebug() << "Right Clicked " << this << Qt::endl;
}
