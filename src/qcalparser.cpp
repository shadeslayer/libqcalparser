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

#include "qcalparser.h"

//Local includes
#include "qcalevent.h"

//Qt includes
#include <QFile>
#include <QDateTime>
#include <QDebug>
#include <QTextStream>


QCalParser::QCalParser(QFile *iCalFile, QObject *parent) :
    QObject(parent)
{
    Q_ASSERT(iCalFile->open(QIODevice::ReadOnly | QIODevice::Text));

    m_eventList.clear();

    m_dataStream = new QTextStream(iCalFile);
    parseICalFile();

}

void QCalParser::parseICalFile()
{
    QString line = m_dataStream->readLine();
    while(!line.isNull()) {
        if(line.contains("BEGIN:VEVENT")) {
          parseICalBlock();
        }

        line = m_dataStream->readLine();

    };
}

void QCalParser::parseICalBlock()
{
    QCalEvent *event = new QCalEvent(this);
    QString line;
    do {
        line = m_dataStream->readLine();
        if(line.startsWith(QLatin1String("UID:"))) {
            event->setUid(line.section(QLatin1Char(':'), 1));
        } else if (line.startsWith(QLatin1String("DTSTART:"))){
           event->setStartDate(convertStringToStartDate(line));
        } else if (line.startsWith(QLatin1String("DTEND:"))){
            event->setStartDate(convertStringToEndDate(line));
        } else if (line.startsWith(QLatin1String("CATEGORIES:"))) {
            event->setCategories(line.section(QLatin1Char(':'), 1).split(" " || ",", QString::SkipEmptyParts));
        } else if (line.startsWith(QLatin1String("SUMMARY:"))) {
            event->setSummary(line.section(QLatin1Char(':'), 1));
        } else if (line.startsWith(QLatin1String("LOCATION:"))) {
            event->setLocation(line.section(QLatin1Char(':'), 1));
        } else if (line.startsWith(QLatin1String("DESCRIPTION:"))) {
            event->setDescription(line.section(QLatin1Char(':'), 1));
        } else if (line.startsWith(QLatin1String("URL:"))) {
            event->setEventUrl(line.section(QLatin1Char(':'), 1));
        } else if (line.startsWith(QLatin1String("X-TYPE:"))) {
            event->setEvpentUrlType(line.section(QLatin1Char(':'), 1));
        } else if (line.startsWith(QLatin1String("X-ROOMNAME:"))) {
            event->setRoomName(line.section(QLatin1Char(':'), 1));
        }
    }while(!line.contains(QByteArray("END:VEVENT")));
    m_eventList.append(event);
}

QDateTime QCalParser::convertStringToStartDate(const QString &line)
{
    int year = line.mid(8, 4).toInt();
    int month = line.mid(12, 2).toInt();
    int day = line.mid(14, 2).toInt();
    int hours = line.mid(17, 2).toInt();
    int minutes = line.mid(19, 2).toInt();
    int seconds = line.mid(21, 2).toInt();
    return QDateTime(QDate(year, month, day), QTime(hours, minutes, seconds), Qt::UTC);
}

QDateTime QCalParser::convertStringToEndDate(const QString &line)
{
    int year = line.mid(5, 4).toInt();
    int month = line.mid(10, 2).toInt();
    int day = line.mid(12, 2).toInt();
    int hours = line.mid(15, 2).toInt();
    int minutes = line.mid(17, 2).toInt();
    int seconds = line.mid(19, 2).toInt();
    return QDateTime(QDate(year, month, day), QTime(hours, minutes, seconds), Qt::UTC);
}

QList <QCalEvent*> QCalParser::getEventList()
{
    return m_eventList;
}
