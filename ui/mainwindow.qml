import QtQuick.Controls 2.12
import QtQuick
import QtQuick.Layouts
import ise.nork;

ApplicationWindow {
    visible: true
    id: root
    property var obj : MainWindow {}

    menuBar: MenuBar {
        // ...
    }

    header: ToolBar {
        // ...
    }

    footer: TabBar {
        // ...
    }

    RowLayout{
      Button{
        text : "Left"
        onClicked: root.obj.handleLeft()
      }

      Button{
        text: "Right"
        onClicked: root.obj.handleRight()
      }
    }
    StackView {
        anchors.fill: parent
    }

    Component.onCompleted: {
      root.obj = Qt.createQmlObject("import ise.nork; MainWindow{}", root)
    }

}
