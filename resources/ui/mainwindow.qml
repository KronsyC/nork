import QtQuick.Controls 2.12
import QtQuick
import QtQuick.Layouts
import ise.nork;
import "."

ApplicationWindow {
    visible: true
    id: root
    property var obj : MainWindow {}

    height: 800
    width: 1000
    maximumHeight: height
    maximumWidth: width

    minimumHeight: height
    minimumWidth: width
    Column {
        anchors.fill: parent

        // Top part
        Rectangle {
            id: topPart
            color: "lightblue"
            width: parent.width
            height: parent.height * 0.7
          
            Display{

            }
        }

        // Bottom part (split into left and right)
        Row {
            id: bottomPart
            width: parent.width
            height: parent.height * 0.3
            // Bottom left part
            Rectangle {
                id: bottomLeftPart
                color: "lightgrey"
                width: parent.width - bottomRightPart.width
                height: parent.height

                Text {
                    anchors.centerIn: parent
                    text: "Bottom Left Part"
                    font.pixelSize: 20
                }
            }

            // Bottom right part
            Rectangle {
                id: bottomRightPart
                width: parent.height
                height: parent.height

                // Custom MiniMap component
                MiniMap {
                    // anchors.fill: parent
                }
            }
        }
    }

    Component.onCompleted: {
      root.obj = Qt.createQmlObject("import ise.nork; MainWindow{}", root)
    }

}
