/*
 * This file is part of libqcalparser
 *
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

#include "qcalevent.h"

QCalEvent::QCalEvent(QObject *parent) :
    QObject(parent)
{
}

QCalEvent::~QCalEvent()
{
}

QDebug operator<<(QDebug dbg, const QCalEvent &c)
{
    dbg.nospace() << "QCalEvent(\n";
    foreach (const QString &key, c.propertyNames()) {
        dbg.nospace() << "    " << key << ": " << c.property(key) << "\n";
    }
    dbg.nospace() << ")\n";

    return dbg.space();
}
