import QtQuick 2.4
import QtQuick.Controls 1.4

Rectangle {
    width: 320;
    height: 240;
    color: "grey";

    QtObject {
        id: attrs;
        property int counter;
        Component.onCompleted: {
            attrs.counter = 10;
        }
    }

    Text {
        id: countShow;
        anchors.centerIn: parent;
        color: "blue";
        font.pixelSize: 24;
    }

    Timer {
        id: countDown;
        interval: 1000;
        repeat: true;
        triggeredOnStart: true;
        onTriggered: {
            countShow.text = attrs.counter;
            attrs.counter -= 1;
            if(attrs.counter < 0) {
                countDown.stop();
                countShow.text = "Clap now";
            }
        }
    }

    Button {
        id: startButton;
        anchors{
            top:countShow.bottom;
            topMargin: 20;
            horizontalCenter: countShow.horizontalCenter;
        }
        text: "Start";
        onClicked: {
            attrs.counter = 10;
            countDown.start();
        }
    }
}
