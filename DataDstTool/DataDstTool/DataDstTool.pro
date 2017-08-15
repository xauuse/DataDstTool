#-------------------------------------------------
#
# Project created by QtCreator 2017-07-19T08:59:25
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DataDstTool
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    qexcel.cpp

HEADERS  += mainwindow.h \
    qexcel.h

FORMS    += mainwindow.ui

QT += sql

QT += axcontainer
