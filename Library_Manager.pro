#-------------------------------------------------
#
# Project created by QtCreator 2023-11-10T13:01:33
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Library_Manager
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
    databases.cpp \
        main.cpp \
        mainsense.cpp \
    book.cpp \
    small_widget.cpp \
    insert_widget.cpp

HEADERS += \
    databases.h \
        mainsense.h \
    main.h \
    book.h \
    small_widget.h \
    insert_widget.h
