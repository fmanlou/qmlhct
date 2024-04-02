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

    GroupBox {
        id: styleGroupBox

        title: "Style"

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

    Switch {
        checked: scheme.light

        onCheckedChanged: {
            scheme.light = checked
        }
    }

    ColumnLayout {
        anchors.top: parent.top
        anchors.topMargin: 100
        anchors.horizontalCenter: parent.horizontalCenter
        spacing: 16

        RowLayout {
            spacing: 10

            ColumnLayout {
                spacing: 0

                Rectangle {
                    width: 200
                    height: 55
                    color: scheme.primaryColor
                }

                Rectangle {
                    width: 200
                    height: 45
                    color: scheme.onPrimaryColor
                }
            }

            ColumnLayout {
                spacing: 0

                Rectangle {
                    width: 200
                    height: 55
                    color: scheme.secondaryColor
                }

                Rectangle {
                    width: 200
                    height: 45
                    color: scheme.onSecondaryColor
                }
            }

            ColumnLayout {
                spacing: 0

                Rectangle {
                    width: 200
                    height: 55
                    color: scheme.tertiaryColor
                }

                Rectangle {
                    width: 200
                    height: 45
                    color: scheme.onTeritaryColor
                }
            }

            ColumnLayout {
                spacing: 0

                Rectangle {
                    width: 200
                    height: 55
                    color: scheme.errorColor
                }

                Rectangle {
                    width: 200
                    height: 45
                    color: scheme.onErrorColor
                }
            }
        }

        RowLayout {
            spacing: 10

            ColumnLayout {
                spacing: 0

                Rectangle {
                    width: 200
                    height: 55
                    color: scheme.primaryContainerColor
                }

                Rectangle {
                    width: 200
                    height: 45
                    color: scheme.onPrimaryContainerColor
                }
            }

            ColumnLayout {
                spacing: 0

                Rectangle {
                    width: 200
                    height: 55
                    color: scheme.secondaryContainerColor
                }

                Rectangle {
                    width: 200
                    height: 45
                    color: scheme.onSecondaryContainerColor
                }
            }

            ColumnLayout {
                spacing: 0

                Rectangle {
                    width: 200
                    height: 55
                    color: scheme.tertiaryContainerColor
                }

                Rectangle {
                    width: 200
                    height: 45
                    color: scheme.onTertiaryContainerColor
                }
            }

            ColumnLayout {
                spacing: 0

                Rectangle {
                    width: 200
                    height: 55
                    color: scheme.errorContainerColor
                }

                Rectangle {
                    width: 200
                    height: 45
                    color: scheme.onErrorContainerColor
                }
            }
        }
    }
}
