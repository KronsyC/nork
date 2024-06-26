#ifndef NORK_UI_DUCK_H
#define NORK_UI_DUCK_H

#include "item/duck.h"
#include "qobject.h"
#include "qtmetamacros.h"
#include <QObject>
#include <QString>
#include <cstdint>

namespace nork::ui {

///
/// DuckData holds the data associated with a duck
///
class DuckData : public QObject {
    Q_OBJECT
    Q_PROPERTY(QString name READ name NOTIFY nameChanged)
    Q_PROPERTY(QString description READ description NOTIFY descriptionChanged)
    Q_PROPERTY(QString texturePath READ texturePath NOTIFY texturePathChanged)
    Q_PROPERTY(QString instance_id READ instanceId NOTIFY instanceIdChanged)
    Q_PROPERTY(int x_pos MEMBER x_pos NOTIFY positionChanged)
    Q_PROPERTY(int y_pos MEMBER y_pos NOTIFY positionChanged)

  public:
    DuckData(QObject* parent = nullptr) : QObject(parent) {}
    DuckData(DuckInstance* instance, uint16_t x, uint16_t y, QObject* parent = nullptr)
        : QObject(parent), instance(instance), x_pos(x), y_pos(y) {}

    QString name() const { return QString::fromStdString(instance->get_class()->name); }
    QString description() const { return QString::fromStdString(instance->get_class()->description); }
    QString texturePath() const { return QString::fromStdString(instance->get_class()->texture_path); }
    QString instanceId() const { return QString::fromStdString(instance->uid); }

  signals:
    void nameChanged();
    void descriptionChanged();
    void texturePathChanged();
    void positionChanged();
    void instanceIdChanged();

  private:
    DuckInstance* instance;
    int x_pos;
    int y_pos;
};

///
/// DuckController handles actions associated with ducks
///
class DuckController : public QObject {
    Q_OBJECT
    Q_PROPERTY(uint16_t instance_id MEMBER instance_id REQUIRED)

  public:
    DuckController(QObject* parent = nullptr);

  signals:

  public slots:
    void handleClaim();

  private:
    uint16_t instance_id;
};
} // namespace nork::ui
#endif // !NORK_UI_DUCK_H
