TEMPLATE = app
TARGET = qmlvideofx_563

QT += quick multimedia

SOURCES += filereader.cpp main.cpp
HEADERS += filereader.h trace.h

RESOURCES += qmlvideofx.qrc

#include($$PWD/../snippets/performancemonitor/performancemonitordeclarative.pri)


#ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android

#OTHER_FILES += \
#    android/AndroidManifest.xml

QMAKE_INFO_PLIST = Info.plist

EXAMPLE_FILES += \
    qmlvideofx.png \
    qmlvideofx.svg


linux-rk3399mali-g++ | linux-rk3399x11-g++ {
    DEFINES += __RK3399__
    linux-rk3399mali-g++ {
        DEFINES += __RK3399_MALI__
    } else {
        DEFINES += __RK3399_X11__
    }


    target.path = /home/saibi/cam_gst_qt
    INSTALLS += target
}
