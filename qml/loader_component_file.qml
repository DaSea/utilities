import QtQuick 2.4
Rectangle {
    width: 320;
    height: 240;
    color: "#EEEEEE";

    Text {
        id: coloredText;
        anchors{
            horizontalCenter: parent.horizontalCenter;
            top: parent.top;
            topMargin: 4;
        }
        text: "Hello, QML!";
        font.pixelSize: 24;
    }

    Loader {
        id: redLoader;
        width: 80;
        height: 60;
        focus: true;
        anchors{
            left: parent.left;
            leftMargin: 4;
            bottom: parent.bottom;
            bottomMargin: 4;
        }
        source: "ColorPicker.qml"
        KeyNavigation.right: blueLoader;
        KeyNavigation.tab: blueLoader;

        onLoaded: {
            item.color = "red";
            item.focus = true;
        }

        onFocusChanged: {
            item.focus = focus;
        }
    }

    Loader {
        id: blueLoader;
        anchors {
            left: redLoader.right;
            leftMargin: 4;
            bottom: redLoader.bottom;
        }
        source: "ColorPicker.qml";
        KeyNavigation.left: redLoader;
        KeyNavigation.tab: redLoader;
        onLoaded: {
            item.color = 'yellow';
        }
        onFocusChanged: {
            item.focus = focus;
        }
    }

    Connections {
        target: redLoader.item;
        onColorPicked :{
            coloredText.color = clr;
            if(!redLoader.focus) {
                redLoader.focus = true;
                blueLoader.focus = false;
            }
        }
    }

    Connections {
        target: blueLoader.item;
        onColorPicked: {
            coloredText.color = clr;
            if(!blueLoader.focus){
                blueLoader.focus = true;
                redLoader.focus = false;
            }
        }
    }
}
