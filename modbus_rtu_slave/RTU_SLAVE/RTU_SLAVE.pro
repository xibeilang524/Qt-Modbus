QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

DEFINES += QT_DEPRECATED_WARNINGS

DESTDIR = $$PWD/exe/
TARGET = app

INCLUDEPATH = $$PWD/inc
LIBS = -L$$PWD/lib -lWS2_32

SOURCES += \
    main.cpp \
    slave.cpp

HEADERS += \
    slave.h

FORMS += \
    slave.ui


