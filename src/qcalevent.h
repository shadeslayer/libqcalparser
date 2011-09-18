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

#ifndef QCALEVENT_H
#define QCALEVENT_H

#include <QtCore/QDebug>
#include <QtCore/QMetaProperty>
#include <QtCore/QObject>
#include <QtCore/QVariant>

#define E_PROPERTY(name) QVariant name() const { return QObject::property(#name); }

class QCalEvent : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QVariant uid READ uid)
    Q_PROPERTY(QVariant dtstart READ dtstart)
    Q_PROPERTY(QVariant dtend READ dtend)
    Q_PROPERTY(QVariant categories READ categories)
    Q_PROPERTY(QVariant summary READ summary)
    Q_PROPERTY(QVariant location READ location)
    Q_PROPERTY(QVariant description READ description)
    Q_PROPERTY(QVariant url READ url)
public:
    explicit QCalEvent(QObject *parent = 0);
    virtual ~QCalEvent();

    E_PROPERTY(uid)
    E_PROPERTY(dtstart)
    E_PROPERTY(dtend)
    E_PROPERTY(categories)
    E_PROPERTY(summary)
    E_PROPERTY(location)
    E_PROPERTY(description)
    E_PROPERTY(url)

    Q_INVOKABLE void setProperty(const QString &iCalKey, const QVariant &value)
    {
        QString key = iCalKey.toLower().replace(QChar('-'), QChar('_'));
        qDebug() << key << value;
        m_properties.insert(key, value);
    }

    Q_INVOKABLE QVariant property(const char *key) const { return property(QString(key)); }
    Q_INVOKABLE QVariant property(const QString &key) const { return m_properties.value(key); }

    QList<QString> propertyNames() const { return m_properties.keys(); }

private:
    QVariantMap m_properties;
};

QDebug operator<<(QDebug dbg, const QCalEvent &c);

#undef E_PROPERTY

#endif // QCALEVENT_H
