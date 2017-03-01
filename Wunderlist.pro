#-------------------------------------------------
#
# Project created by QtCreator 2014-09-19T15:02:24
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Wunderlist
TEMPLATE = app


SOURCES += main.cpp\
        dialog.cpp \
    activity.cpp \
    controller.cpp \
    list.cpp \
    lists.cpp \
    model.cpp \
    qam.cpp \
    qmodel.cpp \
    qtm.cpp

HEADERS  += dialog.h \
    activity.h \
    controller.h \
    list.h \
    lists.h \
    model.h \
    qam.h \
    qmodel.h \
    qtm.h

FORMS    += dialog.ui
