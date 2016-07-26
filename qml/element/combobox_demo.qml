import QtQuick 2.4
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.3
import QtQuick.Controls.Styles 1.4

Rectangle {
    id: rootItem;
    width: 480;
    height: 360;
    color: "#a0b0a0";

    GridLayout {
        anchors.fill: parent;
        rows: 2;
        columns: 2;
        rowSpacing: 4;
        columnSpacing: 4;
        flow: GridLayout.TopToBottom;

        GroupBox {
            width: 200;
            height: 120;
            title: "只读电器";
            ComboBox {
                anchors.top: parent.top;
                anchors.topMargin: 8;
                width: parent.width;
                model: ["TV", "CD Player", "Set Top Box", "Router"];
            }
        }

        GroupBox{
            width: 200;
            height: 120;
            title: "可编辑水果";
            ComboBox {
                anchors.top: parent.top;
                anchors.topMargin: 8;
                width: parent.width;
                editable: true;
                model: ListModel {
                    ListElement {text: "Banana"; color: "yellow"}
                }
                onAccepted: {
                    if((count < 4) && (find(currentText) === -1)) {
                        model.append({text: editText});
                        currentIndex = find(currentText);
                        if(count == 4) {
                            editable = false;
                        }
                    }
                }
            }
        }

        GroupBox {
            width: 200;
            height: 120;
            title: "定制风格";
            ComboBox {
                anchors.top: parent.top;
                anchors.topMargin: 8;
                width: parent.width;
                model: ["Google", "IBM", "Digia", "HuaWei"];
                style: ComboBoxStyle {
                    dropDownButtonWidth: 20;
                    background: Rectangle {
                        implicitHeight: 24;
                        border.width: control.editable ? 0 : 2;
                        border.color: (control.hovered || control.pressed) ? "blue" : "gray";
                        color: (control.hovered || control.pressed) ? "#e0e0e0" : "#c0c0c0";

                        Canvas {
                            width: 16;
                            height: 18;
                            anchors.right: parent.right;
                            anchors.rightMargin: 2;
                            anchors.top: parent.top;
                            anchors.topMargin: 1;
                            onPaint: {
                                var ctx = getContext("2d");
                                ctx.save();
                                ctx.strokeStyle = "red";
                                ctx.lineWidth = 2;
                                ctx.beginPath();
                                ctx.moveTo(1, 8);
                                ctx.lineTo(9, 16);
                                ctx.lineTo(15, 8);
                                ctx.stroke();
                                ctx.restore();
                            }
                        }
                    }

                    label: Text {
                        anchors.left: parent.left;
                        anchors.leftMargin: 2;
                        width: parent.width - 2;
                        height: parent.height;
                        verticalAlignment: Text.AlignVCenter;
                        horizontalAlignment: Text.AlignHCenter;
                        text: control.currentText;
                        color: (control.hovered || control.pressed) ? "blue" : "black";
                    }
                }
            }
        }

        GroupBox {
            width: 200;
            height: 236;
            title: "月份输入";
            ComboBox {
                anchors.top: parent.top;
                anchors.topMargin: 8;
                width: parent.width;
                model: ListModel {}
                editable: true;
                validator: IntValidator { top: 12; bottom: 1; }
                onAccepted: {
                    if((count < 12) && (-1 === find(currentText))) {
                        model.append({text: editText});
                        currentIndex = find(currentText);
                        if(12 == count)
                            editable = false;
                    }
                }
            }
        }
    }
}
