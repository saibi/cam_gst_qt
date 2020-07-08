#-------------------------------------------------
#
# Project created by QtCreator 2020-07-08T12:01:42
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = video_overlay
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp

HEADERS += \
        mainwindow.h

FORMS += \
        mainwindow.ui

linux-rk3399mali-g++ | linux-rk3399x11-g++ {
    DEFINES += __RK3399__

    target.path = /home/saibi/cam_gst_qt
    INSTALLS += target

    PKG_CONFIG_PATH=
    PKG_CONFIG_LIBDIR=$$[QT_SYSROOT]/usr/lib/aarch64-linux-gnu/pkgconfig:$$[QT_SYSROOT]/usr/lib/pkgconfig:$$[QT_SYSROOT]/usr/share/pkgconfig
    PKG_CONFIG_SYSROOT_DIR=$$[QT_SYSROOT]
}

# for gstreamer
QMAKE_CXXFLAGS += `pkg-config --cflags gstreamer-video-1.0 gstreamer-1.0`
LIBS += `pkg-config --libs gstreamer-video-1.0 gstreamer-1.0`
