

import QtQuick.Controls 2.12
import QtQuick
import ise.nork

Button{

  id: loc_indicator

  property string location
  property real xpos
  property real ypos
  property MiniMapController mmc

  icon.name: "location"
  icon.source: "/images/location_indicator.png"


  x : parent.width * xpos - loc_indicator.width / 2
  y : parent.height * ypos - loc_indicator.height / 2


  background: null

  onClicked: {
    console.log("GOTO Location: '" + location + "'");
    mmc.handle_location_click(location);
  }

}

