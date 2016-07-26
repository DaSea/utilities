import QtQuick 2.4
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4

Rectangle {
    id: rootItem;
    width: 320;
    height: 300;

    Rectangle {
        id: resultHolder;
        color: "#a0a0a0";
        width: 160;
        height: 100;
        anchors.centerIn: parent;
        visible: false;
        z: 2;
        opacity: 0.6;
        border.color: "red";
        border.width: 2;
        radius: 8;
        Text {
            id: result;
            anchors.fill: parent;
            anchors.margins: 5;
            font.bold: true;
            wrapMode: Text.Wrap;
            color: "blue";
        }
    }

    Component {
        id: checkStyle;
        CheckBoxStyle {
            indicator: Rectangle {
                implicitWidth: 14;
                implicitHeight: 14;
                border.color: control.hovered ? "darkblue" : "grey";
                border.width: 2;

                Canvas {
                    anchors.fill: parent;
                    anchors.margins: 3;
                    visible: control.checked;
                    onPaint: {
                        var ctx = getContext("2d");
                        ctx.save();
                        ctx.strokeStyle = "#c00020";
                        ctx.lineWidth = 2;
                        ctx.beginPath();
                        ctx.moveTo(0, 0);
                        ctx.lineTo(width, height);
                        ctx.moveTo(0, height);
                        ctx.lineTo(width, 0);
                        ctx.stroke();
                        ctx.restore();
                    }
                }
            }

            label: Text {
                color: control.checked ? "blue" : "black";
                text: control.text;
            }
        }
    }

    GroupBox {
        id: groupBox;
        title: "请选择你喜欢的爱情电影: "
        anchors {
            top: parent.top;
            topMargin: 8;
            left: parent.left;
            leftMargin: 20;
        }
        width: 250;
        height: 160;
        Column {
            id: movies;
            anchors {
                top: notation.bottom;
                topMargin: 15;
            }
            spacing: 8;
            CheckBox {
                text: "廊桥遗梦";
                style: checkStyle;
                onClicked: resultHolder.visible = false;
            }
            CheckBox {
                text: "英雄";
                style: checkStyle;
                onClicked: resultHolder.visible = false;
            }
            CheckBox {
                text: "功夫";
                style: checkStyle;
                onClicked: resultHolder.visible = false;
            }
            CheckBox {
                text: "西游记";
                style: checkStyle;
                onClicked: resultHolder.visible = false;
            }
        }
    }
    Button {
        id: confirm;
        text: "Confirm";
        anchors.top: groupBox.bottom;
        anchors.topMargin: 8;
        anchors.left: groupBox.left;
        anchors.leftMargin: 20;
        onClicked: {
            var str = new Array();
            var index = 0;
            var count = movies.children.length;
            for(var i = 0; i < count; ++i) {
                if(movies.children[i].checked) {
                    str[index] = movies.children[i].text;
                    ++index;
                }
            }

            if(index > 0) {
                result.text = str.join();
                resultHolder.visible = true;
            }
        }
    }
}
