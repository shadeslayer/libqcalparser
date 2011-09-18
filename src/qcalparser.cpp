/*
 * This file is part of libqcalparser
 *
 * Copyright (C) Rohan Garg <rohan16garg@gmail.com>
 * Copyright (C) 2011 Harald Sitter <apachelogger@ubuntu.com>
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

#include <QtCore/QDateTime>
#include <QtCore/QDebug>
#include <QtCore/QFile>
#include <QtCore/QTextStream>

#include "qcalevent.h"

QCalParser::QCalParser(QObject *parent) :
    QObject(parent)
{

}

QCalParser::~QCalParser()
{
    delete m_dataStream;
}

bool QCalParser::parse(const QByteArray &data)
{
    m_dataStream = new QTextStream(data);
    parse();

    return true;
}

bool QCalParser::parse(QFile *file)
{
    if (!file->isOpen()) {
        if (!file->open(QIODevice::ReadOnly | QIODevice::Text))
            return false;
    }

    m_dataStream = new QTextStream(file);
    parse();

    return true;
}

void QCalParser::parse()
{
    QString line = m_dataStream->readLine();
    while(!line.isNull()) {
        if(line.contains("BEGIN:VEVENT")) {
          parseBlock();
        }

        line = m_dataStream->readLine();
    };
}

void QCalParser::parseBlock()
{
    QCalEvent *event = new QCalEvent(this);
    QString line;
    do {
        line = m_dataStream->readLine();
        if(line.startsWith(QLatin1String("UID:"))) {
            event->setUid(line.section(QLatin1Char(':'), 1));
            continue;
        } else if (line.startsWith(QLatin1String("DTSTART:"))){
           event->setStartDate(QDateTime::fromString(line, "'DTSTART:'yyyyMMdd'T'hhmmss'Z'"));
           continue;
        } else if (line.startsWith(QLatin1String("DTEND:"))){
            event->setStopDate(QDateTime::fromString(line, "'DTEND:'yyyyMMdd'T'hhmmss'Z'"));
            continue;
        } else if (line.startsWith(QLatin1String("CATEGORIES:"))) {
            event->setCategories(line.section(QLatin1Char(':'), 1).split(" " || ",", QString::SkipEmptyParts));
            continue;
        } else if (line.startsWith(QLatin1String("SUMMARY:"))) {
            event->setSummary(line.section(QLatin1Char(':'), 1));
            continue;
        } else if (line.startsWith(QLatin1String("LOCATION:"))) {
            event->setLocation(line.section(QLatin1Char(':'), 1));
            continue;
        } else if (line.startsWith(QLatin1String("DESCRIPTION:"))) {
            event->setDescription(line.section(QLatin1Char(':'), 1));
            continue;
        } else if (line.startsWith(QLatin1String("URL:"))) {
            event->setEventUrl(line.section(QLatin1Char(':'), 1));
            continue;
        } else if (line.startsWith(QLatin1String("X-TYPE:"))) {
            event->setEvpentUrlType(line.section(QLatin1Char(':'), 1));
            continue;
        } else if (line.startsWith(QLatin1String("X-ROOMNAME:"))) {
            event->setRoomName(line.section(QLatin1Char(':'), 1));
            continue;
        }
    } while (!line.contains(QByteArray("END:VEVENT")));
    m_eventList.append(event);
}

QList <QCalEvent *> QCalParser::getEventList()
{
    return m_eventList;
}
