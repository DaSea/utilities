import QtQuick 2.4
import QtQuick.Controls 1.4

Rectangle {
    width: 320;
    height: 480;
    color: "grey";

    focus: true;
    Keys.enabled: true;
    Keys.onEscapePressed: {
        Qt.quit();
    }
    Keys.forwardTo: [ moveText, likeQt ];

    Text {
        id: moveText;
        x: 20;
        y: 20;
        width:200;
        height: 30;
        text: "Moving text!";
        color: "blue";
        font { bold: true; pixelSize: 24; }
        Keys.enabled: true;
        Keys.onPressed: {
            switch(event.key) {
                case Qt.Key_Left:
                    x -= 10;
                    break;
                case Qt.Key_Right:
                    x += 10;
                    break;
                case Qt.Key_Down:
                    y += 10;
                    break;
                case Qt.Key_Up:
                    y -= 10;
                    break;
                default:
                    return;
                }

            event.accepted = true;
        }
    }

    CheckBox {
        id: likeQt;
        text: "Like QtQuick";
        anchors{
            left: parent.left;
            leftMargin: 10;
            bottom: parent.bottom;
            bottomMargin: 20;
        }
        z: 1;
    }
}
