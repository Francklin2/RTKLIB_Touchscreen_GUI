#-------------------------------------------------
#
# Project created by QtCreator 2018-02-02T21:09:47
#
#-------------------------------------------------

QT       += core gui
QT           += network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = RTK_BASE_Statio_Position
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    approxcoord.cpp \
    coord_coverter.cpp \
    downloader.cpp \
    gpstime.cpp \
    mydialog.cpp \
    mymessagehandler.cpp \
    processing.cpp \
    rnx2rtkp.cpp \
    station.cpp

HEADERS  += mainwindow.h \
    approxcoord.h \
    coord_coverter.h \
    downloader.h \
    gpstime.h \
    mydialog.h \
    mymessagehandler.h \
    processing.h \
    rnx2rtkp.h \
    station.h

FORMS    += mainwindow.ui \
    mydialog.ui
