#-------------------------------------------------
#
# Project created by QtCreator 2015-11-13T22:21:19
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport


TARGET = RTKBASE
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
        threadheuresysteme.cpp \
    magraphicsscene.cpp \
    options1.cpp \
    affichesolutions.cpp \
    options2.cpp \
    vt.c \
    rtkrcv.c \
    MainThread.cpp \
    str2str.c \
    MainthreadStr2str.cpp \
    affichestr2str.cpp \
    mainthreadreadfile.cpp \
    optionsstr2str.cpp \
    qcustomplot.cpp \
    gestionconfig.cpp \
    choixedite.cpp \
    editeconfig.cpp \
    choixstr2str.cpp \
    choixconfig.cpp \
    optionssauvepoints.cpp \
    clavier.cpp \
    mylineedit.cpp \
    mycombobox.cpp

HEADERS  += mainwindow.h \
    threadheuresysteme.h \
    magraphicsscene.h \
    options1.h \
    affichesolutions.h \
    options2.h \
    vt.h \
    MainThread.h \
    MainthreadStr2str.h \
    affichestr2str.h \
    mainthreadreadfile.h \
    optionsstr2str.h \
    qcustomplot.h \
    gestionconfig.h \
    choixedite.h \
    editeconfig.h \
    choixstr2str.h \
    choixconfig.h \
    optionssauvepoints.h \
    clavier.h \
    mylineedit.h \
    mycombobox.h

FORMS    += mainwindow.ui \
    options1.ui \
    affichesolutions.ui \
    options2.ui \
    affichestr2str.ui \
    optionsstr2str.ui \
    gestionconfig.ui \
    choixedite.ui \
    editeconfig.ui \
    choixstr2str.ui \
    choixconfig.ui \
    optionssauvepoints.ui \
    clavier.ui \
    mylineedit.ui \
    mycombobox.ui

FORMS    += mainwindow.ui

LIBS += -L$$PWD/lib/rtklib/ -lrtk -lm -lrt -lpthread
INCLUDEPATH += $$PWD/lib/rtklib
DEPENDPATH += $$PWD/lib/rtklib

CONFIG += debug

QMAKE_CFLAGS +=  -ansi  -pedantic -DTRACE -DENAGLO -DENAGAL -DENAQZS -DNFREQ=3
QMAKE_CXXFLAGS +=  -std=c++0x
