TEMPLATE = app
TARGET = camera

QT += multimedia multimediawidgets

HEADERS = \
    camera.h \
    imagesettings.h \
    videosettings.h \
    transparentwidget.h \
    sharedviewfinder.h

SOURCES = \
    main.cpp \
    camera.cpp \
    imagesettings.cpp \
    videosettings.cpp \
    transparentwidget.cpp \
    sharedviewfinder.cpp

FORMS += \
    camera.ui \
    videosettings.ui \
    imagesettings.ui \
    transparentwidget.ui

RESOURCES += camera.qrc

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
