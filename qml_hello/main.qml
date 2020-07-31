import QtQuick 2.6
import QtQuick.Window 2.2

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Rectangle {

        id: rect

        anchors.fill: parent
        radius: 20.0

        color: "yellow"


        Text {
            text: "Hello World"
            font.pixelSize: 24


        }
    }
}
