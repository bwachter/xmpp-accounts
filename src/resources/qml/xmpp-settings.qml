import QtQuick 1.1
import com.nokia.meego 1.1

Rectangle {
    signal setValueAsInt(string key, int value)
    signal setValueAsString(string key, string value)
    signal setValueAsBool(string key, bool value)
    
    Flickable {
        width:parent.width; height:parent.height
        //contentWidth: settingsGrid.width; contentHeight: settingsGrid.height
        flickableDirection: Flickable.VerticalFlick

        Column {
            Label {id: hd1; text: "FIXME, header"}

            Label {id: resourceLabel; text: "XMPP Resource"}
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

            LabeledSwitch {
                id: testlabelswitch
                text: "Test label switch"
                //height: 40
                //width: 200
            }

            Label {id: hdSsl; text: "SSL"}
            Grid {
                id: sslSettingsGrid;
                width: parent.width
                columns: 2
                Switch {
                    id: requireEncryptionSwitch
                    checked: param_require_encryption
                    onCheckedChanged: setValueAsBool("parameters/require-encryption", checked)
                }
                Label {id: requireEncryptionLabel; text: "Require encryption"}
                Switch {
                    id: ignoreSslErrorsSwitch
                    checked: param_ignore_ssl_errors
                    onCheckedChanged: setValueAsBool("parameters/ignore-ssl-errors", checked)
                }
                Label {id: ignoreSslErrorsLabel; text: "Ignore SSL errors"}
                Switch {
                    id: oldSslSwitch
                    checked: param_old_ssl
                    onCheckedChanged: setValueAsBool("parameters/old-ssl", checked)
                }
                Label {id: oldSslLabel; text: "Use old ssl"}
            }
        }
    }
}
