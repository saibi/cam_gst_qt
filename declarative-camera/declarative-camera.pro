TEMPLATE=app
TARGET=declarative-camera

QT += quick qml multimedia

SOURCES += qmlcamera.cpp
RESOURCES += declarative-camera.qrc


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

