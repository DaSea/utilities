import QtQuick 2.4
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4

Rectangle {
    id: rootItem;
    width: 360;
    height: 250;
    // color: "grey";

    TextInput {
        id: txtInput;
        width: 120;
        height: 30;
        font.pixelSize: 20;
        color: "red";
        anchors.centerIn: parent;
        // validator: IntValidator { top: 15; bottom: 6; }
        validator: RegExpValidator {
            regExp: new RegExp("(2[0-5]{2}|2[0-4][0-9]|1?[0-9]{1,2})
            \\.(2[0-5]{2}|2[0-4][0-9]|1?[0-9]{1,2})
            \\.(2[0-5]{2}|2[0-4][0-9]|1?[0-9]{1,2})
            \\.(2[0-5]{2}|2[0-4][0-9]|1?[0-9]{1,2})");
        }
        inputMask: "000.000.000.000;_"
        focus: true;
    }

    TextField {
        id: txtFiled;
        anchors {
            left: txtInput.left;
            top: txtInput.bottom;
            topMargin: 5;
        }

        style: TextFieldStyle {
            textColor: "green";
            background: Rectangle {
                radius: 4;
                implicitWidth: 100;
                implicitHeight: 24;
                border.color: "black";
                border.width: 2;
            }
        }
    }
}
