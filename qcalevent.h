#ifndef QCALEVENT_H
#define QCALEVENT_H

#include <QObject>
#include <QDateTime>
#include <QStringList>
#include <QUrl>

class QCalEvent : public QObject
{
    Q_OBJECT

public:
    explicit QCalEvent(QObject *parent = 0);

    QString getUid();
    QDateTime getStartDate();
    QDateTime getStopDate();
    QStringList getCategories();
    QString getSummary();
    QString getLocation();
    QString getDescription();
    QUrl getEventUrl();
    QString getEventUrlType();
    QString getRoomName();

    void setUid(QString uid);
    void setStartDate(QDateTime date);
    void setStopDate(QDateTime date);
    void setCategories(QStringList categories);
    void setSummary(QString summary);
    void setLocation(QString location);
    void setDescription(QString description);
    void setEventUrl(QUrl eventUrl);
    void setEvpentUrlType(QString eventUrlType);
    void setRoomName(QString roomName);

 private:
    QString m_uid;
    QDateTime m_startDate;
    QDateTime m_stopDate;
    QStringList   m_categories;
    QString   m_summary;
    QString   m_location;
    QString   m_description;
    QUrl      m_eventUrl;
    QString   m_eventUrlType;
    QString   m_roomName;

};

#endif // QCALEVENT_H
