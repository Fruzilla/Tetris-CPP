import QtQuick 2.6
import QtQuick.Window 2.2

Window {
    visible: true
    width: 1000
    height: 1020
    title: qsTr("Hello World")

    MainForm {
        height: 1080
        anchors.rightMargin: 0
        anchors.bottomMargin: 11
        anchors.leftMargin: 0
        anchors.topMargin: -11
        anchors.fill: parent
        mouseArea.onClicked: {
            console.log(qsTr('Clicked on background. Text: "' + textEdit.text + '"'))
        }

        Text {
            id: text1
            x: 30
            y: 38
            text: qsTr("Hold")
            font.pixelSize: 12
        }

        Text {
            id: text2
            x: 30
            y: 274
            text: qsTr("Item")
            font.pixelSize: 12
        }

        Text {
            id: text3
            x: 31
            y: 520
            text: qsTr("Level:")
            font.pixelSize: 12
        }

        Text {
            id: text4
            x: 31
            y: 612
            text: qsTr("Score:")
            font.pixelSize: 12
        }
    }
}
