import QtQuick 2.6
import QtQuick.Window 2.2
import QtMultimedia 5.4

import test.saibi.qt 1.0

Rectangle {
    visible: true
    width: 1280
    height: 800

    Camera {
        id: camera
        objectName: "qml-Camera"
    }

    MyFilter {
        id: filter
    }

    VideoOutput {
        id: viewfinder
        source: camera

        anchors.fill: parent

        filters: [ filter ]
    }


    Text {
        id: textmsg
        text: "Hello"
        font.pixelSize: 30

        width: 80
        height: 20

        MouseArea {
            id: mousearea
            anchors.fill: parent
            onPressed: {
                textmsg.text = "World"
            }
            onReleased: {
                textmsg.text = "Hello"
            }
        }
    }

}
