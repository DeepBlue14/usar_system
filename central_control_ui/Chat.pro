QT       += core websockets
QT       -= gui

TARGET = Chat
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

SOURCES += \
    src/main.cpp \
    src/chatserver.cpp 

HEADERS += \
    src/chatserver.h

OTHER_FILES += \
	src/chatclient.html

OBJECTS_DIR = ../build
MOC_DIR = src/moc
QMAKE_CC = gcc
QMAKE_CXX = g++	
