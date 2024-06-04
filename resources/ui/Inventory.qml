import QtQuick.Controls 2.12
import QtQuick
import ise.nork
import "."


Rectangle{
  
  InventoryController{
    id: ic


    onDucksChanged: {
     inv_grid.model = ic.ducks 
    }
  }


  width: parent.width
  height: parent.height 
  color: "gray"


  GridView{
    id: inv_grid
    width: parent.width
    height: parent.height 

    cellWidth: 80
    cellHeight: 120
    model: ic.ducks

    delegate: Item{
      Duck{
        name: model.name
        description: model.description
        texturePath: model.texturePath
        instance_id: model.instance_id
        scaler: 1.3
        claimed: true
      }
    }
  }
}
