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

#include "qcalevent.h"


QCalEvent::QCalEvent(QObject *parent) :
    QObject(parent)
{
}

QCalEvent::~QCalEvent()
{
}

QString QCalEvent::eventUID()
{
    return m_uid;
}

QDateTime QCalEvent::eventStartDate()
{
    return m_startDate;
}

QDateTime QCalEvent::eventStopDate()
{
    return m_stopDate;
}

QStringList QCalEvent::categoryList()
{
    return m_categories;
}

QString QCalEvent::eventSummary()
{
    return m_summary;
}

QString QCalEvent::eventLocation()
{
    return m_location;
}

QString QCalEvent::eventDescription()
{
    return m_description;
}

QUrl QCalEvent::eventUrl()
{
    return m_eventUrl;
}

QString QCalEvent::eventUrlType()
{
    return m_eventUrlType;
}

QString QCalEvent::eventRoomName()
{
    return m_roomName;
}

void QCalEvent::setUid(const QString &uid)
{
    m_uid = uid;
}

void QCalEvent::setStartDate(const QDateTime &date)
{
    m_startDate = date;
}

void QCalEvent::setStopDate(const QDateTime &date)
{
    m_stopDate = date;
}

void QCalEvent::setCategories(const QStringList &categories)
{
    m_categories = categories;
}

void QCalEvent::setSummary(const QString &summary)
{
    m_summary = summary;
}

void QCalEvent::setLocation(const QString &location)
{
    m_location = location;
}

void QCalEvent::setDescription(const QString &description)
{
    m_description = description;
}

void QCalEvent::setEventUrl(const QUrl &eventUrl)
{
    m_eventUrl = eventUrl;
}

void QCalEvent::setEvpentUrlType(const QString &eventUrlType)
{
    m_eventUrlType = eventUrlType;
}

void QCalEvent::setRoomName(const QString &roomName)
{
    m_roomName = roomName;
}
