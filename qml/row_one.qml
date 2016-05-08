import QtQuick 2.4

Rectangle {
    id: rootItem;
    width: 360;
    height: 240;
    color: "#eeeeee";

    Text {
        id: centerText;
        text: "A single Text";
        anchors.centerIn: parent;
        font.bold: true;
        font.pixelSize: 24;
    }

    function setTextColor(clr) {
        centerText.color = clr;
    }

    Row {
        anchors {
            left: parent.left;
            leftMargin: 4;
            bottom: parent.bottom;
            bottomMargin: 4;
        }
        spacing: 4;

        ColorPicker {
            color: Qt.rgba(Math.random(), Math.random(), Math.random(), 1.0);
            onColorPicked: setTextColor(clr);
        }
        ColorPicker {
            color: Qt.rgba(Math.random(), Math.random(), Math.random(), 1.0);
            onColorPicked: setTextColor(clr);
        }
        ColorPicker {
            color: Qt.rgba(Math.random(), Math.random(), Math.random(), 1.0);
            onColorPicked: setTextColor(clr);
        }
        ColorPicker {
            color: Qt.rgba(Math.random(), Math.random(), Math.random(), 1.0);
            onColorPicked: setTextColor(clr);
        }
    }
}
