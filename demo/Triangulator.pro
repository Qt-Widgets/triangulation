CONFIG += debug
TEMPLATE = app
TARGET = launcher
DEPENDPATH += .
INCLUDEPATH += . ../lib
LIBS += -L../lib -ltriangulation

QT += widgets

SOURCES += main.cpp
HEADERS += MyGraphicsView.h
SOURCES += MyGraphicsView.cpp
