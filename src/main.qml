import QtQuick
import QtQuick.Controls 6.4

Window {
    width: 290
    height: 120
    visible: true
    color: "#1e1d24"
    title: qsTr("Encryption Tool")

    TextArea {
        id: inputArea
        x: 84
        y: 0
        width: 206
        height: 120
        readOnly: runBTN.checked
        placeholderText: qsTr("INPUT / OUTPUT")
    }

    TextField {
        id: keyField
        x: 0
        y: 104
        width: 84
        height: 15
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        readOnly: runBTN.checked
        inputMask: ""
        maximumLength: 5
        placeholderText: qsTr("Key (DEFAULT)")
    }

    Button {
        id: runBTN
        x: 14
        y: 5
        width: 57
        height: 23
        text: modeSWT.checked? "ENC" : "DCR"
        checkable: true
    }

    Text {
        id: modeTXT
        x: 26
        y: 34
        color: "#f3f3f3"
        text: qsTr("Mode:")
        font.pixelSize: 12
    }

    Switch {
        id: modeSWT
        x: 14
        y: 46
        text: qsTr("")
        autoExclusive: false
        checkable: true
        rotation: 0
        checked: true
        display: AbstractButton.IconOnly
        enabled: !runBTN.checked
    }
}
