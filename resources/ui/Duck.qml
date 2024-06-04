import QtQuick.Controls 2.12
import QtQuick
import QtQuick.Layouts
import ise.nork

Rectangle {
    id: duck_parent
    property int xpos
    property int ypos
    property real scaler: 1.0
    property bool claimed : false;
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
                width: flavorText.paintedWidth + 10
                height: flavorText.paintedHeight + 8
                Text {
                    id: flavorText
                    text: "<h4>" + duck_parent.name + "</h4>" + (duck_parent.claimed ? ("\n<i>" + duck_parent.description + "</i>") : "")
                    padding: 5
                }
            }
        }
    }
}
