import QtQuick 2.6
import QtQuick.Window 2.2

import QtMultimedia 5.6

import test.saibi.qt 1.0

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    MyFilter {
        id: filter
    }


    MediaPlayer {
        id: player

        // source test
        // "file:///tmp/sintel_trailer-480p.webm"
        // "gst-pipeline: videotestsrc ! videoconvert ! autovideosink"
        // "gst-pipeline: rkisp device=/dev/video0 ! video/x-raw,format=NV12,width=180,height=120,framerate=30/1 ! videoconvert ! autovideosink"
        source: "gst-pipeline: rkisp device=/dev/video0 ! video/x-raw,format=NV12,width=640,height=480,framerate=30/1 ! myfilter ! videoconvert ! autovideosink"
        autoPlay: true
    }

    VideoOutput {
        id: output
        source: player
        anchors.fill: parent

        filters: [ filter ]
    }

    Text {
        id: textmsg
        text: "PRESS ME !!!"
        font.pixelSize: 40
        color: "yellow"

        width: 200
        height: 80

        MouseArea {
            id: mousearea
            anchors.fill: parent
            onPressed: {
                textmsg.text = "pressed"
            }
            onReleased: {
                textmsg.text = "PRESS ME !!!"
            }
        }
    }

}
