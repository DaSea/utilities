import QtQuick 2.4
import QtQuick.Controls 1.4

Rectangle {
    id: rootItem;
    width: 360;
    height: 300;
    property Component component: null;
    property var dynamicObjects: new Array();

    Text {
        id: coloredText;
        anchors.centerIn: parent;
        font.pixelSize: 32;
        text: "hello qml!";
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
            {
                "x": rootItem.dynamicObjects.length*55,
                "y": 10,
                "color": clr
            });
            colorPicker.colorPicked.connect(rootItem.changeTextColor);
            rootItem.dynamicObjects[rootItem.dynamicObjects.length] = colorPicker;
        }
    }

    Button {
        // id: addBtn;
        text: "Add";
        anchors{
            left: parent.left;
            leftMargin: 4;
            bottom: parent.bottom;
            bottomMargin: 4;
        }

        onClicked: {
            createColorPicker(Qt.rgba(Math.random(), Math.random(), Math.random(), 0.7));
        }
    }

    Button {
        id: delBtn;
        text: "Delete";
        anchors {
            left: addBtn.right;
            leftMargin: 4;
            bottom: addBtn.bottom;
        }

        onClicked: {
            if(rootItem.dynamicObjects.length > 0) {
                var deleted = rootItem.dynamicObjects.splice(-1, 1);
                deleted[0].destroy();
            }
        }
    }
}
