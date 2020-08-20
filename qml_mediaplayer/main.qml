import QtQuick 2.6
import QtQuick.Window 2.2

import QtMultimedia 5.6

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")


    MediaPlayer {
        id: player
        source: "file:///tmp/sintel_trailer-480p.webm"
        autoPlay: true
    }

    VideoOutput {
        id: output
        source: player
        anchors.fill: parent
    }
}
