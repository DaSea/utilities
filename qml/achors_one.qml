import QtQuick 2.3

Rectangle {
    id: main;
    width: 300;
    height: 200;
    Rectangle {
        id: rect1;
        anchors.left: parent.left;
        anchors.leftMargin: 20;
        anchors.top: parent.top;
        anchors.topMargin: 20;
        width: 120;
        height: 120;
gradient: Gradient {
              GradientStop { position: 0.0; color: "#202020"; }
              GradientStop { position: 1.0; color: "#a0a0a0"; }
          }
    }

    Rectangle {
        anchors.left: rect1.right;
        anchors.leftMargin: 20;
        anchors.top: rect1.top;
width: 120;
height: 120;
rotation: 90;
gradient: Gradient {
              GradientStop { position: 0.0; color:"#202020"; }
              GradientStop { position: 1.0; color:"#a0a0a0"; }
          }
    }
}
