#-------------------------------------------------
#
# Project created by QtCreator 2013-02-02T09:23:57
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = monscore
TEMPLATE = app

unix:!macx: LIBS += -lmongoclient -lboost_thread-mt -lboost_filesystem -lboost_program_options -lboost_system

SOURCES += main.cpp\
        mainwindow.cpp \
    scorekeeper.cpp \
    scoreentry.cpp \
    highscoredialog.cpp

HEADERS  += mainwindow.h \
    scorekeeper.h \
    scoreentry.h \
    highscoredialog.h

FORMS    += mainwindow.ui \
    highscoredialog.ui
