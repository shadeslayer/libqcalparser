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
