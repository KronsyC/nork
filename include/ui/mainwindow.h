#ifndef NORK_UI_MAINWINDOW_H
#define NORK_UI_MAINWINDOW_H
#include <QCoreApplication>
#include <QDebug>
#include <QObject>
#include "qtmetamacros.h"

namespace nork::ui{
  class MainWindow : public QObject{
    Q_OBJECT

  public:
    explicit MainWindow(QObject* parent = nullptr);
  public slots:
    void handleLeft();
    void handleRight();
  signals:
  };
}

#endif
