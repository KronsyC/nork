import QtQuick.Controls 2.12
import QtQuick

ApplicationWindow {
    visible: true

    menuBar: MenuBar {
        // ...
    }

    header: ToolBar {
        // ...
    }

    footer: TabBar {
        // ...
    }

    StackView {
        anchors.fill: parent
    }

    Text{
      text: "Hello, QT6!"
    }
}
