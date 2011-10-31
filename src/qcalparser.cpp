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
#include <QtCore/QFile>
#include <QtCore/QStringList>
#include <QtCore/QTextStream>

#include "qcalevent.h"

QCalParser::QCalParser(QObject *parent) :
    QObject(parent),
    m_dataStream(0)
{
}

QCalParser::~QCalParser()
{
    if (m_dataStream)
        delete m_dataStream;
}

#warning FIXME datstream looses mem if parse is called multiple times

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
    QSharedPointer<QCalEvent> event = QSharedPointer<QCalEvent>(new QCalEvent);
    QString line;
    while (!(line = m_dataStream->readLine()).contains(QByteArray("END:VEVENT"))) {
        const int deliminatorPosition = line.indexOf(QLatin1Char(':'));
        const QString key   = line.mid(0, deliminatorPosition);
        const QString value = line.mid(deliminatorPosition + 1, -1);

        if (key == QLatin1String("DTSTART") || key == QLatin1String("DTEND")) {
            QDateTime utcTime = QDateTime::fromString(value, "yyyyMMdd'T'hhmmss'Z'");
            utcTime.setTimeSpec(Qt::UTC);
            event->setProperty(key, utcTime.toLocalTime());
            continue;
        } else if (key == QLatin1String("CATEGORIES")) {
            event->setProperty(key, value.split(" " || ",", QString::SkipEmptyParts));
        } else {
            event->setProperty(key, value);
        }
    }
    m_eventList.append(event);
}

QList<QSharedPointer<QCalEvent> > QCalParser::eventList()
{
    return m_eventList;
}
