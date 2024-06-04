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
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QString description READ description WRITE setDescription NOTIFY descriptionChanged)
    Q_PROPERTY(QString texturePath READ texturePath WRITE setTexturePath NOTIFY texturePathChanged)
    Q_PROPERTY(int x_pos MEMBER x_pos NOTIFY positionChanged)
    Q_PROPERTY(int y_pos MEMBER y_pos NOTIFY positionChanged)
    Q_PROPERTY(uint16_t instance_id MEMBER instance_id NOTIFY instanceIdChanged)


  public:
    DuckData(QObject* parent = nullptr) : QObject(parent) {}
    DuckData(const QString& id, const QString& name, const QString& description, const QString& texturePath, int x_pos,
             int y_pos, uint16_t instance_id, QObject* parent = nullptr)
        : QObject(parent), m_id(name), m_name(name), m_description(description), m_texturePath(texturePath),
          x_pos(x_pos), y_pos(y_pos), instance_id(instance_id) {}

    QString name() const { return m_name; }
    void setName(const QString& name) {
        if (name != m_name) {
            m_name = name;
            emit nameChanged();
        }
    }

    QString description() const { return m_description; }
    void setDescription(const QString& description) {
        if (description != m_description) {
            m_description = description;
            emit descriptionChanged();
        }
    }

    QString texturePath() const { return m_texturePath; }
    void setTexturePath(const QString& texturePath) {
        if (texturePath != m_texturePath) {
            m_texturePath = texturePath;
            emit texturePathChanged();
        }
    }

  signals:
    void nameChanged();
    void descriptionChanged();
    void texturePathChanged();
    void positionChanged();
    void instanceIdChanged();

  private:
    QString m_id;
    QString m_name;
    QString m_description;
    QString m_texturePath;
    int x_pos;
    int y_pos;
    uint16_t instance_id;
};

///
/// DuckController handles actions associated with ducks
///
class DuckController : public QObject {
    Q_OBJECT

    Q_PROPERTY(uint16_t instance_id MEMBER instance_id)
  public:
    DuckController(QObject* parent = nullptr);


  signals:
  
  public slots:
    void handleClaim();


private:
    uint16_t instance_id = 0;
};
} // namespace nork::ui
#endif // !NORK_UI_DUCK_H
