import QtQuick.Controls 2.12
import QtQuick
import QtQuick.Layouts
import ise.nork

Rectangle {
    id: duck_parent
    required property int xpos
    required property int ypos
    property real scaler: 1.0
    required property string texturePath
    required property string name
    required property string description
    required property int instance_id;

    DuckController{
      id: dctrl
      instance_id: duck_parent.instance_id
    }

    x: xpos
    y: ypos
    width: 50 * scaler
    height: 50 * scaler
    color: "transparent"
    Image {
        id: image
        width: parent.width
        height: parent.height
        source: parent.texturePath

        MouseArea {
            id: mouseArea
            anchors.fill: parent
            hoverEnabled: true

            onEntered: tooltip.visible = true
            onExited: tooltip.visible = false

            onClicked: dctrl.handleClaim()
        }

        ToolTip {
            id: tooltip
            visible: false
            // anchors.top: parent.bottom
            // anchors.horizontalCenter: parent.horizontalCenter

            // Customize tooltip appearance
            background: Rectangle {
                color: "lightgray"
                radius: 5
            }
            Text {
                text: duck_parent.name + "\n" + duck_parent.description
                padding: 5
            }
        }
    }
}
