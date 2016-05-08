import QtQuick 2.3
import QtQuick.Controls 1.4
import QtQuick.Window 2.2
import QtQuick.Controls.Styles 1.4
import QtQuick.Dialogs 1.2

Window {
    visible: true;
    width: 600;
    height: 480;
    minimumWidth: 480;
    minimumHeight: 400;

    BusyIndicator {
        id: busy;
        running: false;
        anchors.centerIn: parent;
        z: 2;
    }

    Text {
        id: stateLabel;
        visible: false;
        anchors.centerIn: parent;
        z: 3;
    }

    Image {
        id: imageViewer;
        asynchronous: true;
        anchors.fill: parent;
        fillMode: Image.PreserveAspectFit;
        onStatusChanged : {
            if(imageViewer.status == Image.Loading) {
                busy.running = true;
                stateLabel.visible = false;
            }else if(imageViewer.status == Image.Ready) {
                busy.running = false;
            }else if(imageViewer.status == Image.Error) {
                busy.running = false;
                stateLabel.visible = true;
                stateLabel.text = "Error!";
            }
        }
    }

    Button {
        id: openFile;
        text: "Open";
        anchors.left: parent.left;
        anchors.bottom: parent.bottom;
        anchors.leftMargin: 8;
        anchors.bottomMargin: 8;
        style: ButtonStyle {
            background: Rectangle {
                implicitWidth: 75;
                implicitHeight: 30;
                color: control.hovered ? "#c0c0c0" : "#a0a0a0";
                border.width: 5;
                border.color: control.pressed ? "green" : "#red";
            }
        }

        onClicked: {
            fileDialog.open();
        }

        z: 4;
    }

    Text {
        id: imagePath;
        anchors.left: openFile.right;
        anchors.leftMargin: 8;
        anchors.bottom: openFile.bottom;
        font.pixelSize: 18;
    }

    FileDialog {
        id: fileDialog;
        title: "Please choose a picture:";
        nameFilters: ["Image files (*.jpg *.png *.gif)"];
        onAccepted: {
            imageViewer.source = fileDialog.fileUrl;
            /* imagePath.text = fileDialog.fileUrl; */
            // 移除file:///
            var path = new String(fileDialog.fileUrl);
            imagePath.text = path.slice(8);
        }
    }
}
