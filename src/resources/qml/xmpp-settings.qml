import QtQuick 1.1
import com.nokia.meego 1.0

// TODO:
// - add some spacing
// - set correct width for headers and text fields

Flickable {
    id: xmppPage
    flickableDirection: Flickable.VerticalFlick
    height: parent.height
    width: parent.width
    contentHeight: xmppColumn.height
    contentWidth: xmppColumn.width

    signal setValueAsInt(string key, int value)
    signal setValueAsString(string key, string value)
    signal setValueAsBool(string key, bool value)


    Column {
        id: xmppColumn
        width: parent.width

        LabeledHeader { id: hdMain; width:parent.width }

        LabeledHeader {id: resourceLabel; text: "XMPP Resource"; width: parent.width }
        TextField {
            id: xmppResource
            text: param_resource
            onActiveFocusChanged: if (!focus) { setValueAsString("parameters/resource", text); }
        }

        TextField {
            id: xmppPriority
            text: param_priority
            inputMask: "900"
            onActiveFocusChanged: if (!focus) { setValueAsInt("parameters/priority", text); }
        }

        LabeledHeader {
            id: hdSsl
            text: "SSL"
        }

        LabeledSwitch {
            text: "Require encryption"
            id: requireEncryptionSwitch
            checked: param_require_encryption
            onCheckedChanged: setValueAsBool("parameters/require-encryption", checked)
        }
        LabeledSwitch {
            text: "Ignore SSL errors"
            id: ignoreSslErrorsSwitch
            checked: param_ignore_ssl_errors
            onCheckedChanged: setValueAsBool("parameters/ignore-ssl-errors", checked)
        }
            LabeledSwitch {
            text: "Use old SSL"
            id: oldSslSwitch
            checked: param_old_ssl
            onCheckedChanged: setValueAsBool("parameters/old-ssl", checked)
        }
    }
}
