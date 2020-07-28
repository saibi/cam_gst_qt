import QtQuick 2.6
import QtQuick.Window 2.2

import QtMultimedia 5.4


Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Camera {
        id: camera
        objectName: "qml-Camera"

        viewfinder.resolution: "640x480"
    }

    VideoOutput {
        id: viewfinder
        source: camera



    }
}
