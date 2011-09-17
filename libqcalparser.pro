#-------------------------------------------------
#
# Project created by QtCreator 2011-09-18T00:00:15
#
#-------------------------------------------------

QT       -= gui

TARGET = libqcalparser
TEMPLATE = lib

DEFINES += LIBQCALPARSER_LIBRARY

SOURCES += qcalparser.cpp \
    qcalevent.cpp

HEADERS += qcalparser.h\
        libqcalparser_global.h \
    qcalevent.h

symbian {
    MMP_RULES += EXPORTUNFROZEN
    TARGET.UID3 = 0xEA3EFA30
    TARGET.CAPABILITY = 
    TARGET.EPOCALLOWDLLDATA = 1
    addFiles.sources = libqcalparser.dll
    addFiles.path = !:/sys/bin
    DEPLOYMENT += addFiles
}

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}