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

    QString eventUID();
    QDateTime eventStartDate();
    QDateTime eventStopDate();
    QStringList categoryList();
    QString eventSummary();
    QString eventLocation();
    QString eventDescription();
    QUrl eventUrl();
    QString eventUrlType();
    QString eventRoomName();

    void setUid(const QString &uid);
    void setStartDate(const QDateTime &date);
    void setStopDate(const QDateTime &date);
    void setCategories(const QStringList &categories);
    void setSummary(const QString &summary);
    void setLocation(const QString &location);
    void setDescription(const QString &description);
    void setEventUrl(const QUrl &eventUrl);
    void setEvpentUrlType(const QString &eventUrlType);
    void setRoomName(const QString &roomName);

 private:
    QString m_uid;
    QDateTime m_startDate;
    QDateTime m_stopDate;
    QStringList   m_categories;
    QString    m_summary;
    QString    m_location;
    QString    m_description;
    QUrl       m_eventUrl;
    QString    m_eventUrlType;
    QString    m_roomName;

};

#endif // QCALEVENT_H
