import QtQuick 2.4
import QtQuick.Controls 1.4

Rectangle {
    id: rootItem;
    width: 360;
    height: 360;
    property var count: 0;
    property Component component: null;

    Text {
        id: coloredText;
        text: "Hello qml!";
        anchors.centerIn: parent;
        font.pixelSize: 32;
    }

    function changeTextColor(clr) {
        coloredText.color = clr;
    }

    function createColorPicker(clr) {
        if(rootItem.component == null) {
            rootItem.component = Qt.createComponent("ColorPicker.qml");
        }

        var colorPicker;
        if(rootItem.component.status == Component.Ready) {
            colorPicker = rootItem.component.createObject(rootItem,
            {"color": clr, "x": rootItem.count*55, "y": 10});
            colorPicker.colorPicked.connect(rootItem.changeTextColor);

            if(1 == (rootItem.count % 2)) {
                colorPicker.destroy(1000);
            }
        }

        ++rootItem.count;
    }

    Button {
        id: addBtn;
        text: "ADD";
        anchors {
            left: parent.left;
            leftMargin: 4;
            bottom: parent.bottom;
            bottomMargin: 4;
        }
        onClicked: {
            createColorPicker(Qt.rgba(Math.random(), Math.random(), Math.random(), 1));
        }
    }
}
