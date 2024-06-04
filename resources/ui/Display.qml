import QtQuick.Controls 2.12
import QtQuick
import ise.nork
import "."

Rectangle {

    DisplayController {
        id: dtrl

        onLocationUpdate: loc => {
            console.log("LOC UPDATE");
        }

        onSceneURLChanged: {
            display_img.source = dtrl.scene_url;
        }

        onDucksChanged: {
            duck_list.model = dtrl.ducks;
            console.log(dtrl.ducks[0].texturePath);
        }
        //   console.log("GO TO ")
        // }
    }

    width: parent.width
    height: parent.height

    // color: "red"

    Image {
        id: display_img
        width: parent.width
        height: parent.height
        source: dtrl.scene_url
        cache: false
    }

    Repeater {
        id: duck_list
        anchors.fill: parent
        model: dtrl.ducks
        delegate: Item {
            id: del
            Duck {
                xpos: model.x_pos
                ypos: model.y_pos
                name: model.name
                description: model.description
                texturePath: model.texturePath
                instance_id: model.instance_id
            }
        }
    }
}
