import QtQuick 2.4
import QtQuick.Controls 1.4

Rectangle {
    id: rootItem;
    width: 320;
    height: 240;
    color: "grey";
    property var colorPickerShow: false;

    Text {
        id: coloredText;
        anchors{
            horizontalCenter: parent.horizontalCenter;
            top: parent.top;
            topMargin: 8;
        }
        text: "Hello, quick!";
        font.pixelSize: 32;
    }

    Button {
        id: showButton;
        text: "Show";
        anchors {
            left: parent.left;
            leftMargin: 4;
            bottom: parent.bottom;
            bottomMargin: 4;
        }

        onClicked: {
            if(rootItem.colorPickerShow) {
                redLoader.sourceComponent = undefined;
                blueLoader.source = "";
                rootItem.colorPickerShow = false;
                showButton.text = "Show";
            } else {
                redLoader.source = "ColorPicker.qml"
                blueLoader.source = "ColorPicker.qml"
                redLoader.item.colorPicked.connect(onPickedRed);
                blueLoader.item.colorPicked.connect(onPickedBlue);

                rootItem.colorPickerShow = true;
                showButton.text = "Hide";
                redLoader.focus = true;
            }
        }
    }

    Loader {
        id: redLoader;
        anchors{
            left: showButton.right;
            leftMargin: 4;
            bottom: showButton.bottom;
        }
        KeyNavigation.tab: blueLoader;
        KeyNavigation.right: blueLoader;

        onLoaded: {
            if(null != item) {
                item.color = "red";
                item.focus = true;
            }
        }

        onFocusChanged: {
            if(null != item) {
                item = focus;
            }
        }
    }

    Loader {
        id: blueLoader;
        anchors {
            left: redLoader.right;
            leftMargin: 4;
            bottom: redLoader.bottom;
        }

        KeyNavigation.tab: redLoader;
        KeyNavigation.left: redLoader;

        onLoaded: {
            if(null != item) {
                item.color = "blue";
            }
        }

        onFocusChanged: {
            if(null != item) item.focus = focus;
        }
    }

    function onPickedRed(clr) {
        coloredText.color = clr;
        if(!redLoader.focus) {
            redLoader.focus = true;
            blueLoader.focus = false;
        }
    }

    function onPickedBlue(clr) {
        coloredText.color = clr;
        if(!blueLoader.focus) {
            blueLoader.focus = true;
            redLoader.focus = false;
        }
    }

}
