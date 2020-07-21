TEMPLATE = app
TARGET = videowidget

QT += multimedia multimediawidgets

HEADERS = \
    videoplayer.h

SOURCES = \
    main.cpp \
    videoplayer.cpp

QT+=widgets


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
