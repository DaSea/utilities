import QtQuick 2.4
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4

Rectangle {
    id: rootItem;

    width: 360;
    height: 240;
    color: "lightgray";

    Component {
        id: tabContent;
        Rectangle {
            implicitWidth: 100;
            implicitHeight: 100;
            anchors.fill: parent;
            color: Qt.rgba(Math.random(), Math.random(), Math.random(), 0.5);
        }
    }

    Button {
        id: addTab;
        x: 9;
        y: 8;
        width: 60;
        height: 25;
        text: "AddTab";
        onClicked: {
            tabView.addTab("tab-"+tabView.count, tabContent);
        }
    }

    TabView {
        id: tabView;
        anchors.top: addTab.bottom;
        anchors.topMargin: 8;
        anchors.left: parent.left;
        anchors.right: parent.right;
        anchors.bottom: parent.bottom;
    }
}
