TEMPLATE = app
QT += core gui widgets

HEADERS += \
    core/case.h \
    core/color.h \
    core/scene.h \
    core/transform.h \
    core/vec.h \
    gui/viewer.h \
    core/object/mesh.h \
    core/object/object3d.h \
    core/object/triangle.h \
    core/parser/objfileparser.h

SOURCES += \
    core/case.cpp \
    core/scene.cpp \
    gui/main.cpp \
    gui/viewer.cpp \
    core/object/mesh.cpp \
    core/object/triangle.cpp \
    core/parser/objfileparser.cpp