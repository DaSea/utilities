import QtQuick 2.4

Rectangle {
    width: 320;
    height: 230;
    color: "#c0c0c0";

    Text {
        id: coloredText;
        anchors{
            horizontalCenter: parent.horizontalCenter;
            top: parent.top;
            topMargin: 8;
        }
        text: "Hello World!";
        font.pixelSize: 24;
    }

    Component {
        id: colorComponent;
        Rectangle {
            id: colorPicker;
            width: 50;
            height: 30;
            signal colorPicked(color clr);
            border{
                width: focus ? 4 : 0;
                color: focus ? "#90d750" : "#808080";
            }
            MouseArea{
                anchors.fill: parent;
                onPressed: {
                    colorPicker.colorPicked(colorPicker.color);
                }
            }
        }
    }

    Loader {
        id: redColor;
        width: 80;
        height: 50;
        anchors{
            left: parent.left;
            leftMargin: 4;
            bottom: parent.bottom;
            bottomMargin: 4;
        }
        sourceComponent: colorComponent;
        onLoaded: {
            item.color = "red";
        }
    }

    Loader {
        id: blueColor;
        anchors {
            left: redColor.right;
            leftMargin: 4;
            bottom: redColor.bottom;
        }
        sourceComponent: colorComponent;
        onLoaded: item.color = "blue";
    }

    Connections {
        target: redColor.item;
        onColorPicked: coloredText.color = clr;
    }

    Connections {
        target: blueColor.item;
        onColorPicked: coloredText.color = clr;
    }
}
