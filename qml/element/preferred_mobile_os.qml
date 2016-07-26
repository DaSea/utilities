import QtQuick 2.4
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4

Rectangle {
    id: rootItem;
    width: 400;
    height: 320;
    // color: "grey";

    Rectangle {
        id: resultHolder;
        color: "red";
        width: 150;
        height: 60;
        anchors.centerIn: parent;
        visible: false;
        z: 2;
        opacity: 0.7;
        border.width: 2;
        border.color: "#808080";
        Text {
            id: result;
            anchors.centerIn: parent;
            color: "green";
            font.bold: true;
        }
    }

    ExclusiveGroup {
        id: mos;
    }

    Component {
        id: radioStyle;
        RadioButtonStyle {
            indicator: Rectangle {
                implicitWidth: 16;
                implicitHeight: 12;
                radius: 6;
                border.color: control.hovered ? "darkblue" : "grey";
                border.width: 1;
                Rectangle {
                    anchors.fill: parent;
                    visible: control.checked;
                    color: "#0000a0";
                    radius: 5;
                    anchors.margins: 3;
                }
            }
            spacing: 5;
            label: Text {
                color: control.activeFocus ? "blue" : "black";
                text: control.text;
            }
        }
    }

    Text {
        id: notation;
        text: "Please select the best mobile os: ";
        anchors.top: parent.top;
        anchors.topMargin: 15;
        anchors.left: parent.left;
        anchors.leftMargin: 8;
    }

    RadioButton {
        id: android;
        text: "Android";
        exclusiveGroup: mos;
        anchors{
            top: notation.bottom;
            topMargin: 5;
            left: notation.left;
        }
        focus: true;
        checked: true;
        activeFocusOnPress: true;
        style: radioStyle;
        onClicked: resultHolder.visible = false;
    }
    RadioButton {
        id: ios;
        text: "iOS";
        exclusiveGroup: mos;
        anchors{
            top: android.bottom;
            topMargin: 5;
            left: notation.left;
        }
        activeFocusOnPress: true;
        style: radioStyle;
        onClicked: resultHolder.visible = false;
    }
    RadioButton {
        id: wp;
        text: "Window Phone";
        exclusiveGroup: mos;
        anchors{
            top: ios.bottom;
            topMargin: 5;
            left: notation.left;
        }
        activeFocusOnPress: true;
        style: radioStyle;
        onClicked: resultHolder.visible = false;
    }
    RadioButton {
        id: firefox;
        text: "Fire OS";
        exclusiveGroup: mos;
        anchors{
            top: wp.bottom;
            topMargin: 5;
            left: notation.left;
        }
        activeFocusOnPress: true;
        style: radioStyle;
        onClicked: resultHolder.visible = false;
    }
    RadioButton {
        id: salifish;
        text: "Salifish";
        exclusiveGroup: mos;
        anchors{
            top: firefox.bottom;
            topMargin: 5;
            left: notation.left;
        }
        activeFocusOnPress: true;
        style: radioStyle;
        onClicked: resultHolder.visible = false;
    }

    Button {
        id: confirm;
        text: "Confirm";
        anchors.top: salifish.bottom;
        anchors.topMargin: 9;
        anchors.left: notation.left;
        onClicked: {
            result.text = mos.current.text;
            resultHolder.visible = true;
        }
    }
}
