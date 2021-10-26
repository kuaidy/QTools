import QtQuick 2.0

Item {
    Rectangle {
        id: mainRect
        //anchors.centerIn: parent
        x: (mainWindow.width - mainRect.width) / 2
        y: (mainWindow.height - mainRect.height) / 2
        width: 400
        height: 400
        color: 'red'
        //color: '#FF0000'
        //color: Qt.rgba(255, 0, 0)
        border.color: 'blue'
        border.width: 4
        gradient: Gradient {
            GradientStop { position: 0.0; color: "red" }
            GradientStop { position: 1.0; color: "blue" }
        }
        radius: 10
    }
}
