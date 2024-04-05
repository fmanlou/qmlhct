import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import Qt.labs.platform 1.1
import Hct 1.0

Rectangle {
    anchors.fill: parent
    color: scheme.backgroundColor

    property DynamicScheme scheme: DynamicScheme {
        baseColor: colorDialog.color
    }

    MouseArea {
        anchors.fill: parent
        onClicked: {
            if (colorDialog.visible) {
                colorDialog.close()
            } else {
                colorDialog.open()
            }
        }
    }

    ColorDialog {
        id: colorDialog
        title: "Please choose a color"
        color: "#DDE8D4"
    }

    ColumnLayout {
        anchors.top: parent.top
        anchors.topMargin: 100
        anchors.horizontalCenter: parent.horizontalCenter

        RowLayout {
            spacing: 14

            ColumnLayout {
                spacing: 14
                Layout.fillWidth: true
                Layout.minimumWidth: 400
                Layout.alignment: Qt.AlignLeft | Qt.AlignTop

                RowLayout {
                    spacing: 5

                    ColumnLayout {
                        spacing: 0

                        Layout.fillWidth: true

                        Rectangle {

                            Layout.fillWidth: true
                            height: 55
                            color: scheme.primaryColor

                            Text {
                                anchors.fill: parent
                                wrapMode: Text.WordWrap
                                padding: 10
                                text: "Primary"
                                color: scheme.onPrimaryColor
                                font.pixelSize: 14
                            }
                        }

                        Rectangle {
                            Layout.fillWidth: true
                            height: 45
                            color: scheme.onPrimaryColor

                            Text {
                                anchors.fill: parent
                                wrapMode: Text.WordWrap
                                padding: 10
                                text: "On Primary"
                                color: scheme.primaryColor
                                font.pixelSize: 14
                            }
                        }
                    }

                    ColumnLayout {
                        spacing: 0
                        Layout.fillWidth: true

                        Rectangle {
                            Layout.fillWidth: true
                            height: 55
                            color: scheme.secondaryColor

                            Text {
                                anchors.fill: parent
                                wrapMode: Text.WordWrap
                                padding: 10
                                text: "Secondary"
                                color: scheme.onSecondaryColor
                                font.pixelSize: 14
                            }
                        }

                        Rectangle {
                            Layout.fillWidth: true
                            height: 45
                            color: scheme.onSecondaryColor

                            Text {
                                anchors.fill: parent
                                wrapMode: Text.WordWrap
                                padding: 10
                                text: "On Secondary"
                                color: scheme.secondaryColor
                                font.pixelSize: 14
                            }
                        }
                    }

                    ColumnLayout {
                        spacing: 0
                        Layout.fillWidth: true

                        Rectangle {
                            Layout.fillWidth: true
                            height: 55
                            color: scheme.tertiaryColor

                            Text {
                                anchors.fill: parent
                                wrapMode: Text.WordWrap
                                padding: 10
                                text: "Tertiary"
                                color: scheme.onTeritaryColor
                                font.pixelSize: 14
                            }
                        }

                        Rectangle {
                            Layout.fillWidth: true
                            height: 45
                            color: scheme.onTeritaryColor

                            Text {
                                anchors.fill: parent
                                wrapMode: Text.WordWrap
                                padding: 10
                                text: "On Tertiary"
                                color: scheme.tertiaryColor
                                font.pixelSize: 14
                            }
                        }
                    }
                }

                RowLayout {
                    spacing: 5
                    Layout.fillWidth: true

                    ColumnLayout {
                        spacing: 0
                        Layout.fillWidth: true

                        Rectangle {
                            Layout.fillWidth: true
                            height: 55
                            color: scheme.primaryContainerColor

                            Text {
                                anchors.fill: parent
                                wrapMode: Text.WordWrap
                                padding: 10
                                text: "Primary Container"
                                color: scheme.onPrimaryContainerColor
                                font.pixelSize: 14
                            }
                        }

                        Rectangle {
                            Layout.fillWidth: true
                            height: 45
                            color: scheme.onPrimaryContainerColor

                            Text {
                                anchors.fill: parent
                                wrapMode: Text.WordWrap
                                padding: 10
                                text: "On Primary Container"
                                color: scheme.primaryContainerColor
                                font.pixelSize: 14
                            }
                        }
                    }

                    ColumnLayout {
                        spacing: 0
                        Layout.fillWidth: true

                        Rectangle {
                            Layout.fillWidth: true
                            height: 55
                            color: scheme.secondaryContainerColor

                            Text {
                                anchors.fill: parent
                                wrapMode: Text.WordWrap
                                padding: 10
                                text: "Secondary Container"
                                color: scheme.onSecondaryContainerColor
                                font.pixelSize: 14
                            }
                        }

                        Rectangle {
                            Layout.fillWidth: true
                            height: 45
                            color: scheme.onSecondaryContainerColor

                            Text {
                                anchors.fill: parent
                                wrapMode: Text.WordWrap
                                padding: 10
                                text: "On Secondary Container"
                                color: scheme.secondaryContainerColor
                                font.pixelSize: 14
                            }
                        }
                    }

                    ColumnLayout {
                        spacing: 0
                        Layout.fillWidth: true

                        Rectangle {
                            Layout.fillWidth: true
                            height: 55
                            color: scheme.tertiaryContainerColor

                            Text {
                                anchors.fill: parent
                                wrapMode: Text.WordWrap
                                padding: 10
                                text: "Tertiary Container"
                                color: scheme.onTertiaryContainerColor
                                font.pixelSize: 14
                            }
                        }

                        Rectangle {
                            Layout.fillWidth: true
                            height: 45
                            color: scheme.onTertiaryContainerColor

                            Text {
                                anchors.fill: parent
                                wrapMode: Text.WordWrap
                                padding: 10
                                text: "On Tertiary Container"
                                color: scheme.tertiaryContainerColor
                                font.pixelSize: 14
                            }
                        }
                    }
                }

                RowLayout {
                    spacing: 5
                    Layout.fillWidth: true

                    ColumnLayout {
                        spacing: 0
                        Layout.fillWidth: true

                        RowLayout {
                            spacing: 0
                            Layout.fillWidth: true

                            Rectangle {
                                Layout.fillWidth: true
                                height: 55
                                color: scheme.primaryFixedColor

                                Text {
                                    anchors.fill: parent
                                    wrapMode: Text.WordWrap
                                    padding: 10
                                    text: "Primary Fixed"
                                    color: scheme.onPrimaryFixedColor
                                    font.pixelSize: 14
                                }
                            }

                            Rectangle {
                                Layout.fillWidth: true
                                height: 55
                                color: scheme.primaryFixedDimColor

                                Text {
                                    anchors.fill: parent
                                    wrapMode: Text.WordWrap
                                    padding: 10
                                    text: "Primary Fixed Dim"
                                    color: scheme.onPrimaryFixedVariantColor
                                    font.pixelSize: 14
                                }
                            }
                        }

                        Rectangle {
                            Layout.fillWidth: true
                            height: 40
                            color: scheme.onPrimaryFixedColor

                            Text {
                                anchors.fill: parent
                                wrapMode: Text.WordWrap
                                padding: 10
                                text: "On Primary Fixed"
                                color: scheme.primaryFixedColor
                                font.pixelSize: 14
                            }
                        }

                        Rectangle {
                            Layout.fillWidth: true
                            height: 40
                            color: scheme.onPrimaryFixedVariantColor

                            Text {
                                anchors.fill: parent
                                wrapMode: Text.WordWrap
                                padding: 10
                                text: "On Primary Fixed Variant"
                                color: scheme.primaryFixedDimColor
                                font.pixelSize: 14
                            }
                        }
                    }

                    ColumnLayout {
                        spacing: 0
                        Layout.fillWidth: true

                        RowLayout {
                            spacing: 0
                            Layout.fillWidth: true

                            Rectangle {
                                Layout.fillWidth: true
                                height: 55
                                color: scheme.secondaryFixedColor

                                Text {
                                    anchors.fill: parent
                                    wrapMode: Text.WordWrap
                                    padding: 10
                                    text: "Secondary Fixed"
                                    color: scheme.onSecondaryFixedColor
                                    font.pixelSize: 14
                                }
                            }

                            Rectangle {
                                Layout.fillWidth: true
                                height: 55
                                color: scheme.secondaryFixedDimColor

                                Text {
                                    anchors.fill: parent
                                    wrapMode: Text.WordWrap
                                    padding: 10
                                    text: "Secondary Fixed Dim"
                                    color: scheme.onSecondaryFixedVariantColor
                                    font.pixelSize: 14
                                }
                            }
                        }

                        Rectangle {
                            Layout.fillWidth: true
                            height: 40
                            color: scheme.onSecondaryFixedColor

                            Text {
                                anchors.fill: parent
                                wrapMode: Text.WordWrap
                                padding: 10
                                text: "On Secondary Fixed"
                                color: scheme.secondaryFixedColor
                                font.pixelSize: 14
                            }
                        }

                        Rectangle {
                            Layout.fillWidth: true
                            height: 40
                            color: scheme.onSecondaryFixedVariantColor

                            Text {
                                anchors.fill: parent
                                wrapMode: Text.WordWrap
                                padding: 10
                                text: "On Secondary Fixed Variant"
                                color: scheme.secondaryFixedDimColor
                                font.pixelSize: 14
                            }
                        }
                    }

                    ColumnLayout {
                        spacing: 0
                        Layout.fillWidth: true

                        RowLayout {
                            spacing: 0
                            Layout.fillWidth: true

                            Rectangle {
                                Layout.fillWidth: true
                                height: 55
                                color: scheme.tertiaryFixedColor

                                Text {
                                    anchors.fill: parent
                                    wrapMode: Text.WordWrap
                                    padding: 10
                                    text: "Tertiary Fixed"
                                    color: scheme.onTertiaryFixedColor
                                    font.pixelSize: 14
                                }
                            }

                            Rectangle {
                                Layout.fillWidth: true
                                height: 55
                                color: scheme.tertiaryFixedDimColor

                                Text {
                                    anchors.fill: parent
                                    wrapMode: Text.WordWrap
                                    padding: 10
                                    text: "Tertiary Fixed Dim"
                                    color: scheme.onTertiaryFixedVariantColor
                                    font.pixelSize: 14
                                }
                            }
                        }

                        Rectangle {
                            Layout.fillWidth: true
                            height: 40
                            color: scheme.onTertiaryFixedColor

                            Text {
                                anchors.fill: parent
                                wrapMode: Text.WordWrap
                                padding: 10
                                text: "On Tertiary Fixed"
                                color: scheme.tertiaryFixedColor
                                font.pixelSize: 14
                            }
                        }

                        Rectangle {
                            Layout.fillWidth: true
                            height: 40
                            color: scheme.onTertiaryFixedVariantColor

                            Text {
                                anchors.fill: parent
                                wrapMode: Text.WordWrap
                                padding: 10
                                text: "On Tertiary Fixed Variant"
                                color: scheme.tertiaryFixedDimColor
                                font.pixelSize: 14
                            }
                        }
                    }
                }

                ColumnLayout {
                    spacing: 0
                    Layout.fillWidth: true

                    RowLayout {
                        spacing: 0

                        Rectangle {
                            Layout.fillWidth: true
                            height: 55
                            color: scheme.surfaceDimColor

                            Text {
                                anchors.fill: parent
                                wrapMode: Text.WordWrap
                                padding: 10
                                text: "Surface Dim"
                                color: scheme.onSurfaceColor
                                font.pixelSize: 14
                            }
                        }

                        Rectangle {
                            Layout.fillWidth: true
                            height: 55
                            color: scheme.surfaceColor

                            Text {
                                anchors.fill: parent
                                wrapMode: Text.WordWrap
                                padding: 10
                                text: "Surface"
                                color: scheme.onSurfaceColor
                                font.pixelSize: 14
                            }
                        }

                        Rectangle {
                            Layout.fillWidth: true
                            height: 55
                            color: scheme.surfaceBrightColor

                            Text {
                                anchors.fill: parent
                                wrapMode: Text.WordWrap
                                padding: 10
                                text: "Surface Bright"
                                color: scheme.onSurfaceColor
                                font.pixelSize: 14
                            }
                        }
                    }

                    RowLayout {
                        spacing: 0

                        Rectangle {
                            Layout.fillWidth: true
                            height: 65
                            color: scheme.surfaceContainerLowestColor

                            Text {
                                anchors.fill: parent
                                wrapMode: Text.WordWrap
                                padding: 10
                                text: "Surface Container Lowest"
                                color: scheme.onSurfaceColor
                                font.pixelSize: 14
                            }
                        }

                        Rectangle {
                            Layout.fillWidth: true
                            height: 65
                            color: scheme.surfaceContainerLowColor

                            Text {
                                anchors.fill: parent
                                wrapMode: Text.WordWrap
                                padding: 10
                                text: "Surface Container Low"
                                color: scheme.onSurfaceColor
                                font.pixelSize: 14
                            }
                        }

                        Rectangle {
                            Layout.fillWidth: true
                            height: 65
                            color: scheme.surfaceContainerColor

                            Text {
                                anchors.fill: parent
                                wrapMode: Text.WordWrap
                                padding: 10
                                text: "Surface Container"
                                color: scheme.onSurfaceColor
                                font.pixelSize: 14
                            }
                        }

                        Rectangle {
                            Layout.fillWidth: true
                            height: 65
                            color: scheme.surfaceContainerHighColor

                            Text {
                                anchors.fill: parent
                                wrapMode: Text.WordWrap
                                padding: 10
                                text: "Surface Container High"
                                color: scheme.onSurfaceColor
                                font.pixelSize: 14
                            }
                        }

                        Rectangle {
                            Layout.fillWidth: true
                            height: 65
                            color: scheme.surfaceContainerHighestColor

                            Text {
                                anchors.fill: parent
                                wrapMode: Text.WordWrap
                                padding: 10
                                text: "Surface Container Highest"
                                color: scheme.onSurfaceColor
                                font.pixelSize: 14
                            }
                        }
                    }

                    RowLayout {
                        spacing: 0

                        Rectangle {
                            Layout.fillWidth: true
                            height: 45
                            color: scheme.onSurfaceColor

                            Text {
                                anchors.fill: parent
                                wrapMode: Text.WordWrap
                                padding: 10
                                text: "On Surface"
                                color: scheme.surfaceColor
                                font.pixelSize: 14
                            }
                        }

                        Rectangle {
                            Layout.fillWidth: true
                            height: 45
                            color: scheme.onSurfaceVariantColor

                            Text {
                                anchors.fill: parent
                                wrapMode: Text.WordWrap
                                padding: 10
                                text: "On Surface Variant"
                                color: scheme.surfaceColor
                                font.pixelSize: 14
                            }
                        }

                        Rectangle {
                            Layout.fillWidth: true
                            height: 45
                            color: scheme.outlineColor

                            Text {
                                anchors.fill: parent
                                wrapMode: Text.WordWrap
                                padding: 10
                                text: "Outline"
                                color: scheme.surfaceColor
                                font.pixelSize: 14
                            }
                        }

                        Rectangle {
                            Layout.fillWidth: true
                            height: 45
                            color: scheme.outlineVariantColor

                            Text {
                                anchors.fill: parent
                                wrapMode: Text.WordWrap
                                padding: 10
                                text: "Outline Variant"
                                color: scheme.onSurfaceColor
                                font.pixelSize: 14
                            }
                        }
                    }
                }
            }

            ColumnLayout {
                Layout.fillWidth: true
                Layout.minimumWidth: 130
                Layout.alignment: Qt.AlignLeft | Qt.AlignTop
                spacing: 14
                ColumnLayout {
                    spacing: 0
                    Layout.fillWidth: true

                    Rectangle {
                        Layout.fillWidth: true
                        height: 55
                        color: scheme.errorColor

                        Text {
                            anchors.fill: parent
                            wrapMode: Text.WordWrap
                            padding: 10
                            text: "Error"
                            color: scheme.onErrorColor
                            font.pixelSize: 14
                        }
                    }

                    Rectangle {
                        Layout.fillWidth: true
                        height: 45
                        color: scheme.onErrorColor

                        Text {
                            anchors.fill: parent
                            wrapMode: Text.WordWrap
                            padding: 10
                            text: "On Error"
                            color: scheme.errorColor
                            font.pixelSize: 14
                        }
                    }
                }

                ColumnLayout {
                    spacing: 0
                    Layout.fillWidth: true

                    Rectangle {
                        Layout.fillWidth: true
                        height: 55
                        color: scheme.errorContainerColor

                        Text {
                            anchors.fill: parent
                            wrapMode: Text.WordWrap
                            padding: 10
                            text: "Error Container"
                            color: scheme.onErrorContainerColor
                            font.pixelSize: 14
                        }
                    }

                    Rectangle {
                        Layout.fillWidth: true
                        height: 45
                        color: scheme.onErrorContainerColor

                        Text {
                            anchors.fill: parent
                            wrapMode: Text.WordWrap
                            padding: 10
                            text: "On Error Container"
                            color: scheme.errorContainerColor
                            font.pixelSize: 14
                        }
                    }
                }

                Rectangle {
                    Layout.fillWidth: true
                    height: 135
                    color: "transparent"
                }

                ColumnLayout {
                    spacing: 20
                    Layout.fillWidth: true

                    ColumnLayout {
                        spacing: 0
                        Rectangle {
                            Layout.fillWidth: true
                            height: 35
                            color: scheme.inverseSurfaceColor

                            Text {
                                anchors.fill: parent
                                wrapMode: Text.WordWrap
                                padding: 10
                                text: "Inverse Surface"
                                color: scheme.surfaceColor
                                font.pixelSize: 14
                            }
                        }
                        Rectangle {
                            Layout.fillWidth: true
                            height: 35
                            color: scheme.inverseOnSurfaceColor

                            Text {
                                anchors.fill: parent
                                wrapMode: Text.WordWrap
                                padding: 10
                                text: "Inverse On Surface"
                                color: scheme.onSurfaceColor
                                font.pixelSize: 14
                            }
                        }
                        Rectangle {
                            Layout.fillWidth: true
                            height: 35
                            color: scheme.inversePrimaryColor

                            Text {
                                anchors.fill: parent
                                wrapMode: Text.WordWrap
                                padding: 10
                                text: "Inverse Primary"
                                color: scheme.onPrimaryContainerColor
                                font.pixelSize: 14
                            }
                        }
                    }

                    RowLayout {
                        spacing: 20

                        Rectangle {
                            Layout.fillWidth: true
                            height: 40
                            color: scheme.scrimColor

                            Text {
                                anchors.fill: parent
                                wrapMode: Text.WordWrap
                                padding: 10
                                text: "Scrim"
                                color: scheme.inverseOnSurfaceColor
                                font.pixelSize: 14
                            }
                        }

                        Rectangle {
                            Layout.fillWidth: true
                            height: 40
                            color: scheme.shadowColor

                            Text {
                                anchors.fill: parent
                                wrapMode: Text.WordWrap
                                padding: 10
                                text: "Shadow"
                                color: scheme.inverseOnSurfaceColor
                                font.pixelSize: 14
                            }
                        }
                    }
                }
            }
        }

        GroupBox {
            id: styleGroupBox

            title: "Style"

            background: Rectangle {
                color: "transparent"
            }

            property string style: "Vibrant"

            RowLayout {
                RadioButton {
                    text: "Vibrant"
                    checked: true

                    onCheckedChanged: {
                        if (checked) {
                            styleGroupBox.style = text
                        }
                    }
                }
                RadioButton {
                    text: "TonalSpot"
                    onCheckedChanged: {
                        if (checked) {
                            styleGroupBox.style = text
                        }
                    }
                }
                RadioButton {
                    text: "Monochrome"
                    onCheckedChanged: {
                        if (checked) {
                            styleGroupBox.style = text
                        }
                    }
                }
                RadioButton {
                    text: "Content"
                    onCheckedChanged: {
                        if (checked) {
                            styleGroupBox.style = text
                        }
                    }
                }
                RadioButton {
                    text: "Expressive"
                    onCheckedChanged: {
                        if (checked) {
                            styleGroupBox.style = text
                        }
                    }
                }
                RadioButton {
                    text: "Fidelity"
                    onCheckedChanged: {
                        if (checked) {
                            styleGroupBox.style = text
                        }
                    }
                }
                RadioButton {
                    text: "FruitSalad"
                    onCheckedChanged: {
                        if (checked) {
                            styleGroupBox.style = text
                        }
                    }
                }
                RadioButton {
                    text: "Neutral"
                    onCheckedChanged: {
                        if (checked) {
                            styleGroupBox.style = text
                        }
                    }
                }
                RadioButton {
                    text: "Rainbow"
                    onCheckedChanged: {
                        if (checked) {
                            styleGroupBox.style = text
                        }
                    }
                }
            }

            onStyleChanged: {
                if (style === "Vibrant") {
                    scheme.style = DynamicScheme.Vibrant
                } else if (style === "TonalSpot") {
                    scheme.style = DynamicScheme.TonalSpot
                } else if (style === "Monochrome") {
                    scheme.style = DynamicScheme.Monochrome
                } else if (style === "Content") {
                    scheme.style = DynamicScheme.Content
                } else if (style === "Expressive") {
                    scheme.style = DynamicScheme.Expressive
                } else if (style === "Fidelity") {
                    scheme.style = DynamicScheme.Fidelity
                } else if (style === "FruitSalad") {
                    scheme.style = DynamicScheme.FruitSalad
                } else if (style === "Neutral") {
                    scheme.style = DynamicScheme.Neutral
                } else if (style === "Rainbow") {
                    scheme.style = DynamicScheme.Rainbow
                }
            }
        }
    }

    Switch {
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 10

        checked: scheme.isDark

        onCheckedChanged: {
            scheme.isDark = checked
        }
    }
}
