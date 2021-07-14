QT -= gui
QT += network serialbus

CONFIG += c++latest console
CONFIG -= app_bundle


SOURCES += \
        main.cpp \
        mycan.cpp

HEADERS += \
    mycan.h
