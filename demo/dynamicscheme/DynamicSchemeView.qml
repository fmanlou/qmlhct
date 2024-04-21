import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import Qt.labs.platform 1.1
import Hct 1.0

Rectangle {
    anchors.fill: parent
    color: scheme.background

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
                            color: scheme.primary

                            Text {
                                anchors.fill: parent
                                wrapMode: Text.WordWrap
                                padding: 10
                                text: "Primary"
                                color: scheme.onPrimary
                                font.pixelSize: 14
                            }
                        }

                        Rectangle {
                            Layout.fillWidth: true
                            height: 45
                            color: scheme.onPrimary

                            Text {
                                anchors.fill: parent
                                wrapMode: Text.WordWrap
                                padding: 10
                                text: "On Primary"
                                color: scheme.primary
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
                            color: scheme.secondary

                            Text {
                                anchors.fill: parent
                                wrapMode: Text.WordWrap
                                padding: 10
                                text: "Secondary"
                                color: scheme.onSecondary
                                font.pixelSize: 14
                            }
                        }

                        Rectangle {
                            Layout.fillWidth: true
                            height: 45
                            color: scheme.onSecondary

                            Text {
                                anchors.fill: parent
                                wrapMode: Text.WordWrap
                                padding: 10
                                text: "On Secondary"
                                color: scheme.secondary
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
                            color: scheme.tertiary

                            Text {
                                anchors.fill: parent
                                wrapMode: Text.WordWrap
                                padding: 10
                                text: "Tertiary"
                                color: scheme.onTeritary
                                font.pixelSize: 14
                            }
                        }

                        Rectangle {
                            Layout.fillWidth: true
                            height: 45
                            color: scheme.onTeritary

                            Text {
                                anchors.fill: parent
                                wrapMode: Text.WordWrap
                                padding: 10
                                text: "On Tertiary"
                                color: scheme.tertiary
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
                            color: scheme.primaryContainer

                            Text {
                                anchors.fill: parent
                                wrapMode: Text.WordWrap
                                padding: 10
                                text: "Primary Container"
                                color: scheme.onPrimaryContainer
                                font.pixelSize: 14
                            }
                        }

                        Rectangle {
                            Layout.fillWidth: true
                            height: 45
                            color: scheme.onPrimaryContainer

                            Text {
                                anchors.fill: parent
                                wrapMode: Text.WordWrap
                                padding: 10
                                text: "On Primary Container"
                                color: scheme.primaryContainer
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
                            color: scheme.secondaryContainer

                            Text {
                                anchors.fill: parent
                                wrapMode: Text.WordWrap
                                padding: 10
                                text: "Secondary Container"
                                color: scheme.onSecondaryContainer
                                font.pixelSize: 14
                            }
                        }

                        Rectangle {
                            Layout.fillWidth: true
                            height: 45
                            color: scheme.onSecondaryContainer

                            Text {
                                anchors.fill: parent
                                wrapMode: Text.WordWrap
                                padding: 10
                                text: "On Secondary Container"
                                color: scheme.secondaryContainer
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
                            color: scheme.tertiaryContainer

                            Text {
                                anchors.fill: parent
                                wrapMode: Text.WordWrap
                                padding: 10
                                text: "Tertiary Container"
                                color: scheme.onTertiaryContainer
                                font.pixelSize: 14
                            }
                        }

                        Rectangle {
                            Layout.fillWidth: true
                            height: 45
                            color: scheme.onTertiaryContainer

                            Text {
                                anchors.fill: parent
                                wrapMode: Text.WordWrap
                                padding: 10
                                text: "On Tertiary Container"
                                color: scheme.tertiaryContainer
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
                                color: scheme.primaryFixed

                                Text {
                                    anchors.fill: parent
                                    wrapMode: Text.WordWrap
                                    padding: 10
                                    text: "Primary Fixed"
                                    color: scheme.onPrimaryFixed
                                    font.pixelSize: 14
                                }
                            }

                            Rectangle {
                                Layout.fillWidth: true
                                height: 55
                                color: scheme.primaryFixedDim

                                Text {
                                    anchors.fill: parent
                                    wrapMode: Text.WordWrap
                                    padding: 10
                                    text: "Primary Fixed Dim"
                                    color: scheme.onPrimaryFixedVariant
                                    font.pixelSize: 14
                                }
                            }
                        }

                        Rectangle {
                            Layout.fillWidth: true
                            height: 40
                            color: scheme.onPrimaryFixed

                            Text {
                                anchors.fill: parent
                                wrapMode: Text.WordWrap
                                padding: 10
                                text: "On Primary Fixed"
                                color: scheme.primaryFixed
                                font.pixelSize: 14
                            }
                        }

                        Rectangle {
                            Layout.fillWidth: true
                            height: 40
                            color: scheme.onPrimaryFixedVariant

                            Text {
                                anchors.fill: parent
                                wrapMode: Text.WordWrap
                                padding: 10
                                text: "On Primary Fixed Variant"
                                color: scheme.primaryFixedDim
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
                                color: scheme.secondaryFixed

                                Text {
                                    anchors.fill: parent
                                    wrapMode: Text.WordWrap
                                    padding: 10
                                    text: "Secondary Fixed"
                                    color: scheme.onSecondaryFixed
                                    font.pixelSize: 14
                                }
                            }

                            Rectangle {
                                Layout.fillWidth: true
                                height: 55
                                color: scheme.secondaryFixedDim

                                Text {
                                    anchors.fill: parent
                                    wrapMode: Text.WordWrap
                                    padding: 10
                                    text: "Secondary Fixed Dim"
                                    color: scheme.onSecondaryFixedVariant
                                    font.pixelSize: 14
                                }
                            }
                        }

                        Rectangle {
                            Layout.fillWidth: true
                            height: 40
                            color: scheme.onSecondaryFixed

                            Text {
                                anchors.fill: parent
                                wrapMode: Text.WordWrap
                                padding: 10
                                text: "On Secondary Fixed"
                                color: scheme.secondaryFixed
                                font.pixelSize: 14
                            }
                        }

                        Rectangle {
                            Layout.fillWidth: true
                            height: 40
                            color: scheme.onSecondaryFixedVariant

                            Text {
                                anchors.fill: parent
                                wrapMode: Text.WordWrap
                                padding: 10
                                text: "On Secondary Fixed Variant"
                                color: scheme.secondaryFixedDim
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
                                color: scheme.tertiaryFixed

                                Text {
                                    anchors.fill: parent
                                    wrapMode: Text.WordWrap
                                    padding: 10
                                    text: "Tertiary Fixed"
                                    color: scheme.onTertiaryFixed
                                    font.pixelSize: 14
                                }
                            }

                            Rectangle {
                                Layout.fillWidth: true
                                height: 55
                                color: scheme.tertiaryFixedDim

                                Text {
                                    anchors.fill: parent
                                    wrapMode: Text.WordWrap
                                    padding: 10
                                    text: "Tertiary Fixed Dim"
                                    color: scheme.onTertiaryFixedVariant
                                    font.pixelSize: 14
                                }
                            }
                        }

                        Rectangle {
                            Layout.fillWidth: true
                            height: 40
                            color: scheme.onTertiaryFixed

                            Text {
                                anchors.fill: parent
                                wrapMode: Text.WordWrap
                                padding: 10
                                text: "On Tertiary Fixed"
                                color: scheme.tertiaryFixed
                                font.pixelSize: 14
                            }
                        }

                        Rectangle {
                            Layout.fillWidth: true
                            height: 40
                            color: scheme.onTertiaryFixedVariant

                            Text {
                                anchors.fill: parent
                                wrapMode: Text.WordWrap
                                padding: 10
                                text: "On Tertiary Fixed Variant"
                                color: scheme.tertiaryFixedDim
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
                            color: scheme.surfaceDim

                            Text {
                                anchors.fill: parent
                                wrapMode: Text.WordWrap
                                padding: 10
                                text: "Surface Dim"
                                color: scheme.onSurface
                                font.pixelSize: 14
                            }
                        }

                        Rectangle {
                            Layout.fillWidth: true
                            height: 55
                            color: scheme.surface

                            Text {
                                anchors.fill: parent
                                wrapMode: Text.WordWrap
                                padding: 10
                                text: "Surface"
                                color: scheme.onSurface
                                font.pixelSize: 14
                            }
                        }

                        Rectangle {
                            Layout.fillWidth: true
                            height: 55
                            color: scheme.surfaceBright

                            Text {
                                anchors.fill: parent
                                wrapMode: Text.WordWrap
                                padding: 10
                                text: "Surface Bright"
                                color: scheme.onSurface
                                font.pixelSize: 14
                            }
                        }
                    }

                    RowLayout {
                        spacing: 0

                        Rectangle {
                            Layout.fillWidth: true
                            height: 65
                            color: scheme.surfaceContainerLowest

                            Text {
                                anchors.fill: parent
                                wrapMode: Text.WordWrap
                                padding: 10
                                text: "Surface Container Lowest"
                                color: scheme.onSurface
                                font.pixelSize: 14
                            }
                        }

                        Rectangle {
                            Layout.fillWidth: true
                            height: 65
                            color: scheme.surfaceContainerLow

                            Text {
                                anchors.fill: parent
                                wrapMode: Text.WordWrap
                                padding: 10
                                text: "Surface Container Low"
                                color: scheme.onSurface
                                font.pixelSize: 14
                            }
                        }

                        Rectangle {
                            Layout.fillWidth: true
                            height: 65
                            color: scheme.surfaceContainer

                            Text {
                                anchors.fill: parent
                                wrapMode: Text.WordWrap
                                padding: 10
                                text: "Surface Container"
                                color: scheme.onSurface
                                font.pixelSize: 14
                            }
                        }

                        Rectangle {
                            Layout.fillWidth: true
                            height: 65
                            color: scheme.surfaceContainerHigh

                            Text {
                                anchors.fill: parent
                                wrapMode: Text.WordWrap
                                padding: 10
                                text: "Surface Container High"
                                color: scheme.onSurface
                                font.pixelSize: 14
                            }
                        }

                        Rectangle {
                            Layout.fillWidth: true
                            height: 65
                            color: scheme.surfaceContainerHighest

                            Text {
                                anchors.fill: parent
                                wrapMode: Text.WordWrap
                                padding: 10
                                text: "Surface Container Highest"
                                color: scheme.onSurface
                                font.pixelSize: 14
                            }
                        }
                    }

                    RowLayout {
                        spacing: 0

                        Rectangle {
                            Layout.fillWidth: true
                            height: 45
                            color: scheme.onSurface

                            Text {
                                anchors.fill: parent
                                wrapMode: Text.WordWrap
                                padding: 10
                                text: "On Surface"
                                color: scheme.surface
                                font.pixelSize: 14
                            }
                        }

                        Rectangle {
                            Layout.fillWidth: true
                            height: 45
                            color: scheme.onSurfaceVariant

                            Text {
                                anchors.fill: parent
                                wrapMode: Text.WordWrap
                                padding: 10
                                text: "On Surface Variant"
                                color: scheme.surface
                                font.pixelSize: 14
                            }
                        }

                        Rectangle {
                            Layout.fillWidth: true
                            height: 45
                            color: scheme.outline

                            Text {
                                anchors.fill: parent
                                wrapMode: Text.WordWrap
                                padding: 10
                                text: "Outline"
                                color: scheme.surface
                                font.pixelSize: 14
                            }
                        }

                        Rectangle {
                            Layout.fillWidth: true
                            height: 45
                            color: scheme.outlineVariant

                            Text {
                                anchors.fill: parent
                                wrapMode: Text.WordWrap
                                padding: 10
                                text: "Outline Variant"
                                color: scheme.onSurface
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
                        color: scheme.error

                        Text {
                            anchors.fill: parent
                            wrapMode: Text.WordWrap
                            padding: 10
                            text: "Error"
                            color: scheme.onError
                            font.pixelSize: 14
                        }
                    }

                    Rectangle {
                        Layout.fillWidth: true
                        height: 45
                        color: scheme.onError

                        Text {
                            anchors.fill: parent
                            wrapMode: Text.WordWrap
                            padding: 10
                            text: "On Error"
                            color: scheme.error
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
                        color: scheme.errorContainer

                        Text {
                            anchors.fill: parent
                            wrapMode: Text.WordWrap
                            padding: 10
                            text: "Error Container"
                            color: scheme.onErrorContainer
                            font.pixelSize: 14
                        }
                    }

                    Rectangle {
                        Layout.fillWidth: true
                        height: 45
                        color: scheme.onErrorContainer

                        Text {
                            anchors.fill: parent
                            wrapMode: Text.WordWrap
                            padding: 10
                            text: "On Error Container"
                            color: scheme.errorContainer
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
                            color: scheme.inverseSurface

                            Text {
                                anchors.fill: parent
                                wrapMode: Text.WordWrap
                                padding: 10
                                text: "Inverse Surface"
                                color: scheme.surface
                                font.pixelSize: 14
                            }
                        }
                        Rectangle {
                            Layout.fillWidth: true
                            height: 35
                            color: scheme.inverseOnSurface

                            Text {
                                anchors.fill: parent
                                wrapMode: Text.WordWrap
                                padding: 10
                                text: "Inverse On Surface"
                                color: scheme.onSurface
                                font.pixelSize: 14
                            }
                        }
                        Rectangle {
                            Layout.fillWidth: true
                            height: 35
                            color: scheme.inversePrimary

                            Text {
                                anchors.fill: parent
                                wrapMode: Text.WordWrap
                                padding: 10
                                text: "Inverse Primary"
                                color: scheme.onPrimaryContainer
                                font.pixelSize: 14
                            }
                        }
                    }

                    RowLayout {
                        spacing: 20

                        Rectangle {
                            Layout.fillWidth: true
                            height: 40
                            color: scheme.scrim

                            Text {
                                anchors.fill: parent
                                wrapMode: Text.WordWrap
                                padding: 10
                                text: "Scrim"
                                color: scheme.inverseOnSurface
                                font.pixelSize: 14
                            }
                        }

                        Rectangle {
                            Layout.fillWidth: true
                            height: 40
                            color: scheme.shadow

                            Text {
                                anchors.fill: parent
                                wrapMode: Text.WordWrap
                                padding: 10
                                text: "Shadow"
                                color: scheme.inverseOnSurface
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
