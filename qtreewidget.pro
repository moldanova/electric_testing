#-------------------------------------------------
#
# Project created by QtCreator 2014-04-28T00:10:56
#
#-------------------------------------------------

QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = qtreewidget
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    connect_to_db.cpp \
    select_table.cpp \
    add_edit_table.cpp \
    prediction_tests.cpp

HEADERS  += mainwindow.h \
    connect_to_db.h \
    select_table.h \
    add_edit_table.h \
    prediction_tests.h

FORMS    += mainwindow.ui \
    select_table.ui \
    add_edit_table.ui \
    prediction_tests.ui
