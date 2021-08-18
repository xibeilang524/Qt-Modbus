QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11


DEFINES += QT_DEPRECATED_WARNINGS
DESTDIR = $$PWD/../exe
TARGET = app

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    src/modbus-data.c \
    src/modbus-tcp.c \
    src/modbus.c

HEADERS += \
    mainwindow.h

FORMS += \
    mainwindow.ui

INCLUDEPATH += $$PWD/inc
LIBS += -L$$PWD/lib -lWS2_32

# Default rules for deployment.
#qnx: target.path = /tmp/$${TARGET}/bin
#else: unix:!android: target.path = /opt/$${TARGET}/bin
#!isEmpty(target.path): INSTALLS += target
