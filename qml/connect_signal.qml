import QtQuick 2.4
import QtQuick.Controls 1.4

Rectangle {
    // 信号连接方法
    id: relay;
    width: 320;
    height: 240;
    color: "grey";

    signal messageReceived(string person, string notice);

    Component.onCompleted: {
        relay.messageReceived.connect(sendToPost);
        relay.messageReceived.connect(sendToTelegraph);
        relay.messageReceived.connect(sendToEmail);

        // 发出信号
        relay.messageReceived("Peter", "Happy new year!");
    }

    // 方法
    function sendToPost(person, notice) {
        console.log("send to post: " + person + ", " + notice);
    }

    function sendToTelegraph(person, notice) {
        console.log("Sending to telegraph: " + person + ", " + notice);
    }

    function sendToEmail(person, notice) {
        console.log("Sending to email: " + person + ", " + notice);
    }

    // 方法连接信号: 意味着当此方法执行时自动发出信号
    Rectangle {
        id: forwarder;
        width: 100;
        height: 100;
        color: "red";

        signal send();
        onSend: {
            console.log("send clicked!");
        }

        MouseArea {
            id: mouseArea;
            anchors.fill: parent;
            onClicked: {
                console.log("MouseArea clicked!");
            }
        }

        Component.onCompleted: {
            mouseArea.clicked.connect(send);
        }
    }
}
