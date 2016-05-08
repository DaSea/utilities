import QtQuick 2.3
import QtQuick.Controls 1.4

Rectangle {
    width: 320;
    height: 240;
    color: "grey";

    Text {
        id: text1;
        anchors.horizontalCenter: parent.horizontalCenter;
        anchors.top: parent.top;
        anchors.topMargin: 20;
        text: "Text one!"
        color: "blue";
        font.pixelSize: 28;
    }

    Text {
        id: text2;
        anchors.horizontalCenter: parent.horizontalCenter;
        anchors.top: text1.bottom;
        anchors.topMargin: 20;
        text: "Text two!";
        color: "red";
        font.pixelSize: 28;
    }

    Button {
        id: colorBtn;
        width: 80;
        height: 40;
        // radius: 10;
        anchors.horizontalCenter: parent.horizontalCenter;
        anchors.top: text2.bottom;
        anchors.topMargin: 10;
        text: "change";
    }

    Connections {
        target: colorBtn;
        onClicked: {
            text1.color = Qt.rgba(Math.random(), Math.random(), Math.random(), 1)
            text2.color = Qt.rgba(Math.random(), Math.random(), Math.random(), 0.8)
        }
    }
}
