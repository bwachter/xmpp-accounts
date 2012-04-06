import QtQuick 1.1
import com.nokia.meego 1.0

// TODO: 
// - use set theme style in label
// - use correct width
    
Item {
    id: labeledHeader

    property alias text: label.text

    implicitWidth: header.implicitWidth + label.implicitWidth
    implicitHeight: Math.max(header.implicitHeight, label.implicitHeight)

    Image {
        id: header
        width: parent.width
        anchors {
            leftMargin: 16
            rightMargin: 16
        }
        source: "image://theme/meegotouch-separator-" + (theme.inverted ?  "inverted-" : "")+ "background-horizontal"
    }

    Label {
        id: label
        platformStyle: LabelStyle { inverted: true }
        anchors {
            verticalCenter: header.verticalCenter
            left: header.right
        }
        wrapMode: Text.NoWrap
    }
}
