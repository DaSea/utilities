import QtQuick 2.3
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4

Rectangle {
    width: 300;
    height: 200;
    Button {
        text: "quit";
        anchors.centerIn: parent;
        style: ButtonStyle {
            background: Rectangle {
                implicitWidth: 70;
                implicitHeight: 30;
                border.width: control.pressed ? 2 : 0;
                border.color: (control.hovered || control.pressed) ? "green" : "#888888";
            }
        }

        onClicked: Qt.quit();
    }

    // 如果有多个button 用到一个style, 可以定义独立的组件
    Component {
        id: btnStyle;
        ButtonStyle {
            background: Rectangle {
                implicitWidth: 80;
                implicitHeight: 40;
                color: "red";
                border.width: control.pressed ? 2 : 0;
                border.color: (control.hovered || control.pressed) ? "green" : "red";
            }
        }
    }

    // use ButtonStyle
    Button {
        id: button1;
        anchors.left: parent.left;
        anchors.bottom: parent.bottom;
        style: btnStyle;
    }

    Button {
        id: button2;
        anchors.left: button1.right;
        anchors.leftMargin: 10;
        anchors.bottom: parent.bottom;
        anchors.bottomMargin: 10;
        style: btnStyle;
    }

}
