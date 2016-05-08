import QtQuick 2.4

Rectangle {
    id: rootItem;
    width: 360;
    height: 240;
    color: "#eeeeee";

    Text {
        id: centerText;
        text: "Test txt!";
        anchors.horizontalCenter: parent.horizontalCenter;
        anchors.top: parent.top;
        anchors.topMargin: 4;
        font.bold: true;
        font.pixelSize: 24;
    }

    function setTextColor(clr) {
        centerText.color = clr;
    }

    Flow {
        anchors {
            left: parent.left;
            leftMargin: 4;
            bottom: parent.bottom;
            bottomMargin: 4;
        }
        width: 280;
        height: 130;
        flow: Flow.TopToBottom;

        ColorPicker {
            width: 80;
            height: 20;
            color: Qt.rgba(Math.random(), Math.random(), Math.random(), Math.random());
            onColorPicked: setTextColor(clr);
        }
        ColorPicker {
            width: 100;
            height: 40;
            color: Qt.rgba(Math.random(), Math.random(), Math.random(), Math.random());
            onColorPicked: setTextColor(clr);
        }
        ColorPicker {
            color: Qt.rgba(Math.random(), Math.random(), Math.random(), Math.random());
            onColorPicked: setTextColor(clr);
        }
        ColorPicker {
            width: 80;
            height: 25;
            color: Qt.rgba(Math.random(), Math.random(), Math.random(), Math.random());
            onColorPicked: setTextColor(clr);
        }
        ColorPicker {
            width: 35;
            height: 35;
            color: Qt.rgba(Math.random(), Math.random(), Math.random(), Math.random());
            onColorPicked: setTextColor(clr);
        }
        ColorPicker {
            width: 20;
            height: 80;
            color: Qt.rgba(Math.random(), Math.random(), Math.random(), Math.random());
            onColorPicked: setTextColor(clr);
        }
        ColorPicker {
            color: Qt.rgba(Math.random(), Math.random(), Math.random(), Math.random());
            onColorPicked: setTextColor(clr);
        }
    }
}
