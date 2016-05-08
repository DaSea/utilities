import QtQuick 2.4

Rectangle {
    width: 320;
    height: 240;

    MouseArea {
        anchors.fill: parent;
        acceptedButtons: Qt.LeftButton| Qt.RightButton;
        onClicked: {
            if(Qt.RightButton == mouse.button) {
                Qt.quit();
            }else if(Qt.LeftButton == mouse.button) {
                color = Qt.rgba((mouse.x%255)/255.0, (mouse.y%255)/255.0, 0.6, 0.7);
            }
        }

        onDoubleClicked: {
            color = "grey";
        }
    }
}
