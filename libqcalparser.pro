#-------------------------------------------------
#
# Project created by QtCreator 2011-09-18T00:00:15
#
#-------------------------------------------------

QT       -= gui

TARGET = libqcalparser
TEMPLATE = lib

DEFINES += LIBQCALPARSER_LIBRARY

SOURCES += src/qcalparser.cpp \
    src/qcalevent.cpp

HEADERS += src/qcalparser.h\
        src/libqcalparser_global.h \
    src/qcalevent.h

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

TARGET = qcalparser
TEMPLATE = app
SOURCES += src/main.cpp
