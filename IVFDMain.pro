#-------------------------------------------------
#
# Project created by QtCreator 2018-05-31T09:07:48
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = IVFDMain
TEMPLATE = app


SOURCES += main.cpp\
        IVFDMainWidget.cpp \
    IVFDMainTcpServer.cpp \
    IVFDTcpClient.cpp \
    IVFDDriver.cpp \
    IVFDRunnable.cpp \
    IVFDSetStartIP.cpp \
    IVFDHeartBeat.cpp

HEADERS  += IVFDMainWidget.h \
    IVFDMainTcpServer.h \
    IVFDTcpClient.h \
    IVFDDriver.h \
    IVFDRunnable.h \
    IVFDSetStartIP.h \
    IVFDHeartBeat.h

FORMS    += IVFDMainWidget.ui

unix:!macx: LIBS += -L$$PWD/../../ivfdlogger/IvfdLogger/bin/ -lIvfdLogger

INCLUDEPATH += $$PWD/../../ivfdlogger/IvfdLogger
DEPENDPATH += $$PWD/../../ivfdlogger/IvfdLogger

