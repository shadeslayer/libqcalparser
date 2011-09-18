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

