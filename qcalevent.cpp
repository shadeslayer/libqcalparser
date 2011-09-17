#include "qcalevent.h"


QCalEvent::QCalEvent(QObject *parent) :
    QObject(parent)
{
}

QString QCalEvent::getUid()
{
    return m_uid;
}

QDateTime QCalEvent::getStartDate()
{
    return m_startDate;
}

QDateTime QCalEvent::getStopDate()
{
    return m_stopDate;
}

QStringList QCalEvent::getCategories()
{
    return m_categories;
}

QString QCalEvent::getSummary()
{
    return m_summary;
}

QString QCalEvent::getLocation()
{
    return m_location;
}

QString QCalEvent::getDescription()
{
    return m_description;
}

QUrl QCalEvent::getEventUrl()
{
    return m_eventUrl;
}

QString QCalEvent::getEventUrlType()
{
    return m_eventUrlType;
}

QString QCalEvent::getRoomName()
{
    return m_roomName;
}

void QCalEvent::setUid(QString uid)
{
    m_uid = uid;
}

void QCalEvent::setStartDate(QDateTime date)
{
    m_startDate = date;
}

void QCalEvent::setStopDate(QDateTime date)
{
    m_stopDate = date;
}

void QCalEvent::setCategories(QStringList categories)
{
    m_categories = categories;
}

void QCalEvent::setSummary(QString summary)
{
    m_summary = summary;
}

void QCalEvent::setLocation(QString location)
{
    m_location = location;
}

void QCalEvent::setDescription(QString description)
{
    m_description = description;
}

void QCalEvent::setEventUrl(QUrl eventUrl)
{
    m_eventUrl = eventUrl;
}

void QCalEvent::setEvpentUrlType(QString eventUrlType)
{
    m_eventUrlType = eventUrlType;
}

void QCalEvent::setRoomName(QString roomName)
{
    m_roomName = roomName;
}
