QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GeometriaComputacional
TEMPLATE = app


SOURCES += main.cpp\
        mainScreen.cpp \
    poli.cpp \
    arco.cpp \
    cubo.cpp \
    prismRec.cpp \
    prismTri.cpp \
    cono.cpp \
    transformaciones.cpp

HEADERS  += mainScreen.h \
    poli.h \
    arco.h \
    cubo.h \
    prismRec.h \
    prismTri.h \
    cono.h \
    transformaciones.h

FORMS    += mainScreen.ui \
    poli.ui \
    arco.ui \
    cubo.ui \
    prismRec.ui \
    prismTri.ui \
    cono.ui

CONFIG-=app_bundle
