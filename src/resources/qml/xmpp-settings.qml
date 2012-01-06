import QtQuick 1.0
import com.nokia.meego 1.0

Rectangle {
    Flickable {
        width:parent.width; height:parent.height
        contentWidth: settingsGrid.width; contentHeight: settingsGrid.height
        flickableDirection: Flickable.VerticalFlick

    }
}
