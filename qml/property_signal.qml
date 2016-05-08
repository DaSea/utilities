import QtQuick 2.4
import QtQuick.Controls 1.4

Rectangle {
    width: 320
    height: 249
    color: "grey"

    Text {
        id: text1
        anchors.centerIn: parent
        text: "one"
        color: "blue"
        font.pixelSize: 23
        onTextChanged: {
            text2.text = text
        }
    }

    Text {
        id: text2
        anchors.left: text1.left;
        anchors.top: text1.bottom
        anchors.topMargin: 20
        text: "hello"
    }

    Button {
        anchors.top: text2.bottom
        anchors.topMargin: 33
        anchors.horizontalCenter: parent.horizontalCenter
        text: "change signal"
        onClicked: {
            text1.text = "都不是问题"
        }
    }
}
