import QtQuick 2.4
import QtQuick.Layouts 1.2

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
        z: 1;
    }

    function setTextColor(clr) {
        helloTxt.color = clr
    }

    GridLayout {
        // anchors {
            // left: parent.left;
            // leftMargin: 4;
            // bottom: parent.bottom;
            // bottomMargin: 4;
        // }
        // width: 300; // [1]
        z: 2;
        anchors.fill: parent;
        rows: 3;
        columns: 3;
        rowSpacing: 4;
        columnSpacing: 4;
        flow: GridLayout.TopToBottom;

        ColorPicker {
            Layout.columnSpan: 3;
            Layout.rowSpan: 3; //[2]

            color: Qt.rgba(Math.random(), Math.random(), Math.random());
            onColorPicked: setTextColor(clr);
        }
        ColorPicker {
            Layout.fillWidth: true; //[3]

            color: Qt.rgba(Math.random(), Math.random(), Math.random());
            onColorPicked: setTextColor(clr);
        }
        ColorPicker {
            color: Qt.rgba(Math.random(), Math.random(), Math.random());
            onColorPicked: setTextColor(clr);
        }
        ColorPicker {
            color: Qt.rgba(Math.random(), Math.random(), Math.random());
            onColorPicked: setTextColor(clr);
        }
        ColorPicker {
            color: Qt.rgba(Math.random(), Math.random(), Math.random());
            onColorPicked: setTextColor(clr);
        }
        ColorPicker {
            color: Qt.rgba(Math.random(), Math.random(), Math.random());
            onColorPicked: setTextColor(clr);
        }
        ColorPicker {
            color: Qt.rgba(Math.random(), Math.random(), Math.random());
            onColorPicked: setTextColor(clr);
        }
    }
}
