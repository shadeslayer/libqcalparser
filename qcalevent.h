/*
 * This file is part of libqcalparser
 *
 * Copyright (C) Rohan Garg <rohan16garg@gmail.com>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 */

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
