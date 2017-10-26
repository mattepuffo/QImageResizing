#-------------------------------------------------
#
# Project created by QtCreator 2015-08-23T20:23:54
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QImageResizing
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
    resizewindow.cpp \
    workerthread.cpp \
    imageresize.cpp

HEADERS  += mainwindow.h \
    resizewindow.h \
    workerthread.h \
    imageresize.h

FORMS    += mainwindow.ui \
    resizewindow.ui

RESOURCES += \
    resources.qrc

DEFINES += APP_NAME=\\\"QImageResize\\\"
DEFINES += ORG_NAME=\\\"Matteo_Ferrone\\\"
DEFINES += ORG_DOMAIN=\\\"www.mattepuffo.com\\\"
VERSION = 0.2.2
DEFINES += APP_VERSION=\\\"$$VERSION\\\"
