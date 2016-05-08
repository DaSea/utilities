import QtQuick 2.3

Item {
    children: {
        Text: {
            text: "Text One";
        };
        Text: {
            text: "Text Two";
        }
    }

    Component.onCompleted: {
        for(var i = 0; i < children.length; ++i) {
            console.log("Text of label ", i, " : ", children[i].text);
        }
    }
}
