import QtQuick 2.4
import QtQuick.Controls 1.4

Rectangle {
    width: 320;
    height: 240;
    color: "green";

    Text {
        id: text1;
        anchors.centerIn: parent;
        text: "Hello, fuck coding!";
        color: "blue";
        font.pixelSize: 24;
    }

    Button {
        id: button1;
        text: "Button test";
        anchors.top: text1.bottom;
        anchors.topMargin: 4;
    }

    Image {
        id: image1;
    }

    Text {
        id: disText;
        anchors.bottom: parent.bottom;
    }
    Component.onCompleted: {
        disText.text = text1 + " " + button1 + " " + image1;
    }
}
