#-------------------------------------------------
#
# Project created by QtCreator 2016-11-20T15:07:48
#
#-------------------------------------------------

QT += core gui
QT += charts network
QT += charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = exer03
TEMPLATE = app


SOURCES += main.cpp\
        mainwidget.cpp \
    dataworker.cpp

HEADERS  += mainwidget.h \
    dataworker.h 

FORMS    += mainwidget.ui
