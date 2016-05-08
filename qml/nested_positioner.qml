import QtQuick 2.4

Rectangle {
    id: rootItem;
    width: 360;
    height: 240;
    color: "#eeeeee";

    Text {
        id: helloTxt;
        text: "Test test";
        anchors.centerIn: parent;
        font.bold: true;
        font.pixelSize: 24;
    }

    function setTextColor(clr) {
        helloTxt.color = clr;
    }

    Row {
        anchors {
            left: parent.left;
            leftMargin: 4;
            bottom: parent.bottom;
            bottomMargin: 4;
        }
        spacing: 4;

        Column {
            spacing: 4;

            ColorPicker {
                color: Qt.rgba(Math.random(), Math.random(), Math.random(), Math.random());
                onColorPicked: setTextColor(clr);
            }
            ColorPicker {
                color: Qt.rgba(Math.random(), Math.random(), Math.random(), Math.random());
                onColorPicked: setTextColor(clr);
            }
        }
        Column {
            spacing: 4;

            ColorPicker {
                color: Qt.rgba(Math.random(), Math.random(), Math.random(), Math.random());
                onColorPicked: setTextColor(clr);
            }
            ColorPicker {
                color: Qt.rgba(Math.random(), Math.random(), Math.random(), Math.random());
                onColorPicked: setTextColor(clr);
            }
        }
        Column {
            spacing: 4;

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
}
