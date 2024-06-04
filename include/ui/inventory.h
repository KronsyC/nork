#ifndef NORK_INVENTORY_H
#define NORK_INVENTORY_H

#include "events.h"
#include "item/duck.h"
#include "pubsub/subscriber.h"
#include "qcontainerfwd.h"
#include "qobject.h"
#include "qqmllist.h"
#include <QObject>
#include <QQmlListProperty>
#include <QVector>

namespace nork::ui {

class DuckInventoryEntry : public QObject {
    Q_OBJECT

    Q_PROPERTY(QString name READ name NOTIFY nameChanged)
    Q_PROPERTY(QString description READ description NOTIFY descriptionChanged)
    Q_PROPERTY(QString texturePath READ texturePath NOTIFY texturePathChanged)
    Q_PROPERTY(QString instance_id READ instanceId NOTIFY instanceIdChanged)
  public:
    DuckInventoryEntry(DuckInstance* instance, QObject* parent) : QObject(parent), instance(instance) {}

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
};

class InventoryController : public QObject, public Subscriber<DuckClaimEvent> {
    Q_OBJECT


    Q_PROPERTY( QQmlListProperty<DuckInventoryEntry> ducks READ ducks NOTIFY ducksChanged )

  public:
    InventoryController(QObject* parent = nullptr);
    ~InventoryController();
    virtual void on_event(DuckClaimEvent& event) override;


  QQmlListProperty<DuckInventoryEntry> ducks(){
    return QQmlListProperty<DuckInventoryEntry>(this, &entries);
  }
  signals:
    void ducksChanged();

  private:

    QVector<DuckInventoryEntry*> entries;
};

} // namespace nork::ui

#endif
