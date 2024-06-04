#ifndef NORK_UI_DISPLAY_H
#define NORK_UI_DISPLAY_H

#include <QObject>
#include "location/location.h"
#include "events.h"
#include "pubsub/subscriber.h"
#include "qcontainerfwd.h"
#include "qqmllist.h"
#include "ui/duck.h"
#include<QQmlListProperty>
#include<QVector>
namespace nork::ui {


class DisplayController : public QObject, public Subscriber<LocationChangeEvent>, public Subscriber<DuckClaimEvent> {
    Q_OBJECT


    Q_PROPERTY( QString scene_url READ getSceneUrl NOTIFY sceneURLChanged)
    Q_PROPERTY(QQmlListProperty<nork::ui::DuckData> ducks READ ducks NOTIFY ducksChanged)
  public:
    explicit DisplayController(QObject* parent = nullptr);
    ~DisplayController();

    virtual void on_event(LocationChangeEvent& event) override;
    virtual void on_event(DuckClaimEvent& event) override;

    QString getSceneUrl(){
      return QString::fromStdString(current_location->get_scene());
    }

  QQmlListProperty<nork::ui::DuckData> ducks(){
    return QQmlListProperty<nork::ui::DuckData>(this, &m_ducks);
  }

    Location* current_location;

  signals:
    void locationUpdate(QString lname);
    void sceneURLChanged();
    void ducksChanged();


  private:
    QVector<nork::ui::DuckData*> m_ducks = QVector<nork::ui::DuckData*>();



    void redraw_ducks();

};
} // namespace nork::ui

#endif
