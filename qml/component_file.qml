import QtQuick 2.4

Rectangle {
    width: 320;
    height: 240;
    color: "#EEEEEE";

    Text {
        id: coloredText;
        anchors {
            horizontalCenter: parent.horizontalCenter;
            top: parent.top;
            topMargin: 4;
        }
        text: "Hello World!";
        font.pixelSize: 32;
    }

    function setTextColor(clr) {
        coloredText.color = clr;
    }

    ColorPicker {
        id: redColor;
        color: "red";
        focus: true;
        anchors {
            left: parent.left;
            leftMargin: 4;
            bottom: parent.bottom;
            bottomMargin: 4;
        }

        KeyNavigation.right: blueColor;
        KeyNavigation.tab: blueColor;
        onColorPicked: {
            coloredText.color = clr;
        }
    }

    ColorPicker {
        id: blueColor;
        color: "blue";
        // focus: true;
        anchors {
            left: redColor.right;
            leftMargin: 4;
            bottom: parent.bottom;
            bottomMargin: 4;
        }

        KeyNavigation.left: redColor;
        KeyNavigation.right: pinkColor;
        KeyNavigation.tab: pinkColor;
    }

    ColorPicker {
        id: pinkColor;
        color: "pink";
        // focus: true;
        anchors {
            left: blueColor.right;
            leftMargin: 4;
            bottom: parent.bottom;
            bottomMargin: 4;
        }

        KeyNavigation.left: blueColor;
        KeyNavigation.tab: redColor;
    }

    Component.onCompleted: {
        blueColor.colorPicked.connect(setTextColor);
        pinkColor.colorPicked.connect(setTextColor);
    }
}
