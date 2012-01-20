import QtQuick 1.1
import com.nokia.meego 1.0

Item {
    id: labeledSwitch

    property alias text: label.text
    property alias checked: switchbox.checked

    height: switchbox.height

    Switch {
        id: switchbox
    }
    
    Label {
        id: label
        anchors.verticalCenter: switchbox.verticalCenter
        anchors.left: switchbox.right
        wrapMode: Text.NoWrap
    }
}
