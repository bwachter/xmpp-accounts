import QtQuick 1.1
import com.nokia.meego 1.0

// TODO:
// - add some spacing
// - allow setting platform style

Item {
    id: labeledSwitch

    property alias text: label.text
    property alias checked: switchbox.checked

    implicitWidth: switchbox.implicitWidth + label.implicitWidth
    implicitHeight: Math.max(switchbox.implicitHeight, label.implicitHeight, switchbox.height)

    Switch {
        id: switchbox
        platformStyle: SwitchStyle { inverted: true }
    }

    Label {
        id: label
        platformStyle: LabelStyle { inverted: true }
        anchors.verticalCenter: switchbox.verticalCenter
        anchors.left: switchbox.right
        wrapMode: Text.NoWrap
    }
}
