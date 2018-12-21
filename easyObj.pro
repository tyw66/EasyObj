TEMPLATE = app
QT += core gui widgets

RC_ICONS = ./res/logo.ico

HEADERS += \
    core/color.h \
    core/scene.h \
    core/transform.h \
    core/vec.h \
    gui/viewer.h \
    core/object/mesh.h \
    core/object/object3d.h \
    core/object/triangle.h \
    core/parser/objfileparser.h \
    core/sample.h

SOURCES += \
    core/scene.cpp \
    core/transform.cpp \
    gui/main.cpp \
    gui/viewer.cpp \
    core/object/mesh.cpp \
    core/object/triangle.cpp \
    core/parser/objfileparser.cpp \
    core/sample.cpp



QMAKE_CXXFLAGS += -fopenmp
LIBS += -lgomp -lpthread
