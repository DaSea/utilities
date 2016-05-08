import QtQuick 2.4

Rectangle {
    id: rootItem;
    width: 320;
    height: 240;
    color: "#eeeeee";

    Text {
        id: centerText;
        text: "Column text~";
        anchors.centerIn: parent;
        font.bold: true;
        font.pixelSize: 34;
    }

    function setTextColor(clr) {
        centerText.color = clr;
    }

    Column {
        anchors {
            left: parent.left;
            leftMargin: 4;
            bottom: parent.bottom;
            bottomMargin: 4;
        }
        spacing: 4;

        ColorPicker {
            color: "red";
            onColorPicked: setTextColor(clr);
        }

        ColorPicker {
            color: "blue";
            onColorPicked: setTextColor(clr);
        }

        ColorPicker {
            color: "green";
            onColorPicked: setTextColor(clr);
        }

        ColorPicker {
            color: "yellow";
            onColorPicked: setTextColor(clr);
        }
    }
}
