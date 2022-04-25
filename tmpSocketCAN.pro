QT -= gui
QT += network serialbus

CONFIG += c++latest console
CONFIG -= app_bundle


SOURCES += \
        main.cpp \
        socketcan.cpp

HEADERS += \
    socketcan.h
