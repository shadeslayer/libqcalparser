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

#ifndef QCALPARSER_H
#define QCALPARSER_H

#include "libqcalparser_global.h"

#include <QtCore/QObject>
#include <QtCore/QSharedPointer>

class QCalEvent;
class QFile;
class QTextStream;

class LIBQCALPARSERSHARED_EXPORT QCalParser : public QObject {
    Q_OBJECT
public:
    QCalParser(QObject *parent = 0);
    ~QCalParser();

    QList<QSharedPointer<QCalEvent> > eventList();

public slots:
    bool parse(const QByteArray &data);
    bool parse(QFile *file);

private:
    void parse();
    void parseBlock();

    QList<QSharedPointer<QCalEvent> > m_eventList;
    QTextStream *m_dataStream;
};

#endif // QCALPARSER_H
