#-------------------------------------------------
#
# Project created by QtCreator 2014-10-26T15:23:22
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Kersach_1_Client_MinGW
TEMPLATE = app

RC_FILE = Kersach1MINGW.rc
CONFIG += static
QMAKE_LFLAGS += -static -static-libgcc
LIBS += -static-libgcc


SOURCES += main.cpp\
        mainwindow.cpp \
    fileworking.cpp

HEADERS  += mainwindow.h \
    Encryption.h

FORMS    += mainwindow.ui

OTHER_FILES +=
