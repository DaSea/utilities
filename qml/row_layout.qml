import QtQuick 2.4
import QtQuick.Layouts 1.3

Rectangle {
    id: rootItem;
    width: 360;
    height: 240;
    color: "#eeeeee";

    Text {
        id: centerText;
        text: "Test test";
        anchors.centerIn: parent;
        font.bold: true;
        font.pixelSize: 24;
    }

    function setTextColor(clor) {
        centerText.color = clor;
    }

    RowLayout {
        anchors {
            left: parent.left;
            right: parent.right;
            bottom: parent.bottom;
            leftMargin: 4;
            rightMargin: 4;
            bottomMargin: 4;
        }
        spacing: 4;

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

            Layout.fillWidth: true;
        }
    }
}

