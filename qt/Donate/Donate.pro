#-------------------------------------------------
#
# Project created by QtCreator 2017-08-17T06:16:07
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Donate
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
        main.cpp \
        mainwindow.cpp \
    donate.cpp \
    change_college.cpp \
    change_class.cpp \
    change_student.cpp \
    insert_college.cpp \
    insert_class.cpp \
    insert_student.cpp \
    search.cpp \
    more.cpp \
    ratio.cpp

HEADERS += \
        mainwindow.h \
    donate.h \
    change_college.h \
    change_class.h \
    change_student.h \
    insert_college.h \
    insert_class.h \
    insert_student.h \
    search.h \
    more.h \
    ratio.h

FORMS += \
        mainwindow.ui \
    change_college.ui \
    change_class.ui \
    change_student.ui \
    insert_college.ui \
    insert_class.ui \
    insert_student.ui \
    search.ui \
    more.ui \
    ratio.ui
