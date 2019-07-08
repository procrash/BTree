TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        event.cpp \
        eventqueue.cpp \
        main.cpp \
        point.cpp \
        polygon.cpp \
        quicksort.cpp \
        sweepline.cpp \
        sweeplinesegment.cpp

HEADERS += \
    btree.h \
    event.h \
    eventqueue.h \
    point.h \
    polygon.h \
    quicksort.h \
    sweepline.h \
    sweeplinesegment.h
