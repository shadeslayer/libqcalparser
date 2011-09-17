#ifndef QCALPARSER_H
#define QCALPARSER_H

#include "libqcalparser_global.h"

#include <QObject>

class QCalEvent;
class QFile;
class QDate;
class QStringList;
class QDateTime;

class LIBQCALPARSERSHARED_EXPORT QCalParser : public QObject {
    Q_OBJECT

public:
    QCalParser(QFile *iCalFile = 0, QObject *parent = 0);
    QList<QCalEvent*> getEventList();

private:
    QList<QCalEvent*> *m_event;
    QFile *m_file;
    void insertQCalEvent();
    void parseICalFile();
    void parseICalBlock();
    QDateTime convertStringToStartDate(QString line);
    QDateTime convertStringToEndDate(QString line);
    QStringList convertStringToStringList(QString line);
};

#endif // QCALPARSER_H
