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
    }
}
