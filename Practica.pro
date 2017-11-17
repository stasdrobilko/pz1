#-------------------------------------------------
#
# Project created by QtCreator 2017-10-31T15:22:42
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Practica
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    bcalculator.cpp \
    form.cpp

HEADERS  += mainwindow.h \
    bcalculator.h \
    form.h

FORMS    += mainwindow.ui \
    bcalculator.ui \
    form.ui

SUBDIRS += \
    ../poslali/BCalc/BCalc.pro \
    BCalc.pro
