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
    add_edit_table.cpp \
    prediction_tests.cpp \
    select_object_type.cpp \
    add_item.cpp

HEADERS  += mainwindow.h \
    connect_to_db.h \
    add_edit_table.h \
    prediction_tests.h \
    select_object_type.h \
    add_item.h

FORMS    += mainwindow.ui \
    add_edit_table.ui \
    prediction_tests.ui \
    select_object_type.ui \
    add_item.ui
