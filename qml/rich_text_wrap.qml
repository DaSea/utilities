import QtQuick 2.3

Rectangle {
    id: topRect;
    width: 500;
    height: 400;

    Text {
        id: wrapBlue;
        width: 150;
        height: 100;
        wrapMode: Text.WordWrap;
        font.bold: true;
        font.pixelSize: 24;
        font.underline: true;
        text: "Hello Blue Text";
        color: "blue";

        // 定位
        anchors.left: parent.left;
        anchors.top: parent.top;
        anchors.leftMargin: 10;
        anchors.topMargin: 10;
    }

    Text {
        id: richText;
        width: 150;
        height: 100;
        wrapMode: Text.WordWrap;
        font.bold: true;
        font.pixelSize: 24;
        font.underline: true;
        text: "Hello Blue <font color=\"blue\">Text</font>";

        // location
        anchors.left: parent.left;
        anchors.top: wrapBlue.bottom;
        anchors.leftMargin: 10;
        anchors.topMargin: 10;
    }

    Text {
        id: normal;
        anchors.right: parent.right;
        anchors.top: parent.top;
        anchors.rightMargin: 20;
        anchors.topMargin: 20;
        font.pixelSize: 24;
        text: "Normal Text";
    }

    Text {
        // 凸起的
        id: raised;
        anchors.left: normal.left;
        anchors.top: normal.bottom;
        anchors.topMargin: 4;
        font.pixelSize: 24;
        text: "Raised Text";

        style: Text.Raised;
        styleColor: "yellow";
    }

    Text {
        id: outline;
        anchors.left: normal.left;
        anchors.top: raised.bottom;
        anchors.topMargin: 4;
        font.pixelSize: 24;
        text: "Outline Text";

        style: Text.Outline;
        styleColor: "red";
    }

    Text {
        id: sunken;
        anchors.left: normal.left;
        anchors.top: outline.bottom;
        anchors.topMargin: 4;
        font.pixelSize: 24;
        text: "Sunken Text";

        style: Text.Sunken;
        styleColor: "#A00000";
    }
}
