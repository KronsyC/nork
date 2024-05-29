import QtQuick.Controls 2.12
import QtQuick
import QtQuick.Layouts
import ise.nork;

Rectangle{
  width: parent.width
  height: parent.height

  Image{
    source: "images/minimap.jpg"
    width: parent.width
    height: parent.height
  }

  LocationIndicator{
    xpos: 0.65
    ypos: 0.65

    location: "loc.kitchen"
  }


  LocationIndicator{
    xpos: 0.5
    ypos: 0.8

    location: "loc.south_wing"
  }

  LocationIndicator{
    xpos: 0.2
    ypos: 0.5

    location: "loc.west_wing"
  }

  LocationIndicator{
    xpos: 0.78
    ypos: 0.55

    location: "loc.east_wing"
  }

  LocationIndicator{
    xpos: 0.9
    ypos: 0.5

    location: "loc.ta_lounge"
  }

  LocationIndicator{
    xpos: 0.68
    ypos: 0.36
    location: "loc.north_chairs"
  }

  LocationIndicator{
    xpos: 0.38
    ypos: 0.65
    location: "loc.south_chairs"
  }

  LocationIndicator{
    xpos: 0.34
    ypos: 0.36
    location: "loc.forest_room"
  }

  LocationIndicator{
    xpos: 0.5
    ypos: 0.25
    location: "loc.north_wing"
  }
}
