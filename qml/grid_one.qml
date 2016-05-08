import QtQuick 2.4

Rectangle {
    id: rootItem;
    width: 360;
    height: 240;

    Text {
        id: centerText;
        text: "a single text!";
        anchors.centerIn: parent;
        font.pixelSize: 32;
        font.bold: true;
    }

    function setTextColor(clr) {
        centerText.color = clr;
    }

    Grid {
        anchors {
            left: parent.left;
            leftMargin: 4;
            bottom: parent.bottom;
            bottomMargin: 4;
        }
        rows: 3;
        columns: 3;
        rowSpacing: 4;
        columnSpacing: 4;
        flow: Grid.TopToBottom;

        ColorPicker {
            color: Qt.rgba(Math.random(), Math.random(), Math.random(), Math.random());
            onColorPicked: setTextColor(clr);
        }
        ColorPicker {
            color: Qt.rgba(Math.random(), Math.random(), Math.random, Math.random());
            onColorPicked: setTextColor(clr);
        }
        ColorPicker {
            color: Qt.rgba(Math.random(), Math.random(), Math.random(), Math.random());
            onColorPicked: setTextColor(clr);
        }
        ColorPicker {
            color: Qt.rgba(Math.random(), Math.random(), Math.random(), Math.random());
            onColorPicked: setTextColor(clr);
        }
        ColorPicker {
            color: Qt.rgba(Math.random(), Math.random(), Math.random(), Math.random());
            onColorPicked: setTextColor(clr);
        }
        ColorPicker {
            color: Qt.rgba(Math.random(), Math.random(), Math.random(), Math.random());
            onColorPicked: setTextColor(clr);
        }
        ColorPicker {
            color: Qt.rgba(Math.random(), Math.random(), Math.random(), Math.random());
            onColorPicked: setTextColor(clr);
        }
    }
}
