import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 2.15
import Hct 1.0

Window {
    id: root
    width: 640
    height: 480
    visible: true
    title: qsTr("QmlHct")  

    Hct {
        id: color 

        h: 180
        c: 50
        t: 50     
    }

    ColumnLayout {
        anchors.top: parent.top
        anchors.topMargin: 100
        anchors.horizontalCenter: parent.horizontalCenter
        spacing: 16

        RowLayout {
            spacing: 10
            Text {
                id: hueText

                Layout.preferredWidth: chromaText.implicitWidth
                horizontalAlignment: Qt.AlignRight
                text: "Hue"
            }

            TextField {
                leftPadding: 5
                text: color.h
                validator: IntValidator {bottom: 0; top: 360;}

                onTextChanged: {
                    color.h = parseInt(text);
                }
            }

            Slider {
                id: hueSlider

                from: 0
                to: 360
                stepSize: 1

                value: color.h

                onValueChanged: {
                    color.h = value;
                }
            }
        }

        RowLayout {
            spacing: 10
            Text {
                id: chromaText

                Layout.preferredWidth: implicitWidth
                horizontalAlignment: Qt.AlignRight
                text: "Chroma"
            }

            TextField {
                leftPadding: 5
                text: color.c
                validator: IntValidator {bottom: 0; top: 100;}

                onTextChanged: {
                    color.c = parseInt(text);
                }
            }

            Slider {
                id: chromaSlider

                from: 0
                to: 100
                stepSize: 1

                value: color.c 

                onValueChanged: {
                    color.c = value;
                }
            }
        }

        RowLayout {
            spacing: 10
            Text {
                id: toneText

                Layout.preferredWidth: chromaText.implicitWidth
                horizontalAlignment: Qt.AlignRight
                text: "Tone"
            }

            TextField {
                leftPadding: 5
                text: color.t
                validator: IntValidator {bottom: 0; top: 100;}

                onTextChanged: {
                    color.t = parseInt(text);
                }
            }

            Slider {
                id: toneSlider

                from: 0
                to: 100
                stepSize: 1

                value: color.t

                onValueChanged: {
                    color.t = value;
                }
            }
        }

        
        Rectangle {
            
            Layout.fillWidth: true
            height: 160
            
            color: color.rgb
        }

        Text {
            text: color.rgb
        }
    }

}
