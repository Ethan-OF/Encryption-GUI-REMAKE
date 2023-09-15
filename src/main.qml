import QtQuick
import QtQuick.Controls 6.4

Window {
    width: 290
    height: 120
    visible: true
    color: "#1e1d24"
    title: qsTr("Encryption Tool")

    TextField {
        id: keyField
        x: 0
        y: 104
        width: 84
        height: 15
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        readOnly: runBTN.checked
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
        checkable: runBTN.checked

        Connections {
            target: runBTN
            function onClicked(s)
            {
                core.run(inputArea.text, keyField.text, modeSWT.checked);
            }
        }

        Connections {
            target: runBTN
            function onClicked()
            {
                runBTN.enabled = false;
            }
        }

        Connections {
            target: core
            function onUpdate()
            {
                runBTN.enabled = true
            }
        }
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

    ScrollView {
        id: scrollArea
        x: 84
        y: 0
        width: 206
        height: 121
        ScrollBar.vertical.policy: ScrollBar.AlwaysOn

        TextArea {
            id: inputArea
            x: 0
            y: 0
            width: 206
            height: 120
            wrapMode: Text.Wrap
            textFormat: Text.PlainText
            readOnly: runBTN.checked
            placeholderText: qsTr("INPUT / OUTPUT")

            Connections {
                target: core
                function onUpdate(s)
                {
                    inputArea.text = s
                }
            }
        }
    }

}
