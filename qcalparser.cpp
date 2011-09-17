#include "qcalparser.h"

//Local includes
#include "qcalevent.h"

//Qt includes
#include <QFile>
#include <QDateTime>


QCalParser::QCalParser(QFile *iCalFile, QObject *parent) :
    QObject(parent)
{
    Q_ASSERT(iCalFile->open(QIODevice::ReadOnly | QIODevice::Text));

    m_file = iCalFile;
    parseICalFile();

}

void QCalParser::parseICalFile()
{
    do {
        parseICalBlock();
    }while(m_file->readLine().contains(QByteArray("END:VCALENDAR")));
}

void QCalParser::parseICalBlock()
{
    do {
    } while(m_file->readLine().contains(QByteArray("BEGIN:VEVENT")));

    QCalEvent *event = new QCalEvent(this);
    QString line;
    do {
        line = QString(m_file->readLine());
        if(line.startsWith(QLatin1String("UID:"))) {
            event->setUid(line.right(4));
        } else if (line.startsWith(QLatin1String("DTSTART:"))){
           event->setStartDate(convertStringToStartDate(line));
        } else if (line.startsWith(QLatin1String("DTEND:"))){
            event->setStartDate(convertStringToEndDate(line));
        } else if (line.startsWith(QLatin1String("CATEGORIES:"))) {
            event->setCategories(line.right(11).split(" " || ",", QString::SkipEmptyParts));
        } else if (line.startsWith(QLatin1String("SUMMARY:"))) {
            event->setSummary(line.right(13));
        } else if (line.startsWith(QLatin1String("LOCATION:"))) {
            event->setLocation(line.right(9));
        } else if (line.startsWith(QLatin1String("DESCRIPTION:"))) {
            event->setDescription(line.right(12));
        } else if (line.startsWith(QLatin1String("URL:"))) {
            event->setEventUrl(line.right(4));
        } else if (line.startsWith(QLatin1String("X-TYPE:"))) {
            event->setEvpentUrlType(line.right(7));
        } else if (line.startsWith(QLatin1String("X-ROOMNAME:"))) {
            event->setRoomName(line.right(11));
        }
    }while(!line.contains(QByteArray("END:VEVENT")));
}

QDateTime QCalParser::convertStringToStartDate(QString line)
{
    int year = line.mid(7, 4).toInt();
    int month = line.mid(12, 2).toInt();
    int day = line.mid(14, 2).toInt();
    int hours = line.mid(17, 2).toInt();
    int minutes = line.mid(19, 2).toInt();
    int seconds = line.mid(21, 2).toInt();
    return QDateTime(QDate(year, month, day),QTime(hours, minutes, seconds));
}

QDateTime QCalParser::convertStringToEndDate(QString line)
{
    int year = line.mid(5, 4).toInt();
    int month = line.mid(10, 2).toInt();
    int day = line.mid(12, 2).toInt();
    int hours = line.mid(15, 2).toInt();
    int minutes = line.mid(17, 2).toInt();
    int seconds = line.mid(19, 2).toInt();
    return QDateTime(QDate(year, month, day),QTime(hours, minutes, seconds));
}
