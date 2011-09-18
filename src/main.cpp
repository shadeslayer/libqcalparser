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
#include "qcalevent.h"

#include <QtCore/QCoreApplication>
#include <QFile>
#include <QString>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QFile *file = new QFile(a.arguments().at(1));
    QCalParser *parser = new QCalParser(file);
    foreach(QCalEvent* event, parser->getEventList()) {
        qDebug() << event->eventUID();
        qDebug() << event->categoryList();
        qDebug() << event->eventDescription();
        qDebug() << event->eventUrl();
        qDebug() << event->eventUrlType();
        qDebug() << event->eventLocation();
        qDebug() << event->eventRoomName();
        qDebug() << event->eventStartDate();
        qDebug() << event->eventStopDate();
     }
}

