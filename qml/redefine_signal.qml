import QtQuick 2.4
import QtQuick.Controls 1.4

Rectangle {
    width: 320;
    height: 240;
    color: "#c0c0c0";

    Text {
        id: colorText;
        anchors.horizontalCenter: parent.horizontalCenter;
        anchors.top: parent.top;
        anchors.topMargin: 8;
        text: "Hello, qt quick!";
        font.pixelSize: 24;
    }

    Component {
        id: colorComponent;
        Rectangle {
            id: colorPicker;
            width: 50;
            height: 50;
            signal colorPickered(color clr);
            MouseArea {
                anchors.fill: parent;
                onPressed: {
                    colorPicker.colorPickered(colorPicker.color);
                }
            }
        }
    }

    Loader {
        id: redLoader;
        anchors.left: parent.left;
        anchors.leftMargin: 4;
        anchors.bottom: parent.bottom;
        anchors.bottomMargin: 4;
        sourceComponent: colorComponent;
        onLoaded: {
            item.color = "red";
        }
    }

    Loader {
        id: blueLoader;
        anchors.left: redLoader.right;
        anchors.leftMargin: 4;
        anchors.bottom: redLoader.bottom;
        sourceComponent: colorComponent;
        onLoaded: {
            item.color = "blue";
        }
    }

    Connections {
        target: redLoader.item;
        onColorPickered: {
            colorText.color = clr;
        }
    }

    Connections {
        target: blueLoader.item;
        onColorPickered: {
            colorText.color = clr;
        }
    }
}
