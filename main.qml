import QtQuick 2.6
import QtQuick.Window 2.2
import QtQuick.Controls 1.0

Window {
    visible: true
    height : 600
    width : 400

    // Background
    Rectangle{
        anchors.fill : parent
        color : "#180126"
    }

    Row{
        height : 200
        width : parent.width

        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top : parent.top
        anchors.topMargin: Qt.platform.os === "android" ? 150 : 20

        Image{
            height : parent.height
            width : parent.width / 3
            fillMode: Image.PreserveAspectFit
            source : "flag_france.png"

            MouseArea{
                anchors.fill : parent
                onClicked: {

                    translateItem.selectLanguage("FR")
                }
            }
        }
        Image{
            height : parent.height
            width : parent.width / 3
            fillMode: Image.PreserveAspectFit
            source : "flag_uk.png"

            MouseArea{
                anchors.fill : parent
                onClicked: {

                    translateItem.selectLanguage("EN")
                }
            }
        }
        Image{
            height : parent.height
            width : parent.width / 3
            fillMode: Image.PreserveAspectFit
            source : "flag_german.png"

            MouseArea{
                anchors.fill : parent
                onClicked: {

                    translateItem.selectLanguage("DE")
                }
            }
        }
    }

    Item{

        width : parent.width
        height: Qt.platform.os === "android" ? 150 : 75
        anchors.centerIn: parent

        Rectangle{
            width : parent.width
            height : parent.height
            color : "#FF9F1C"
        }

        Text {
            text: qsTr("Hello World") + translateItem.emptyString
            color : "#180126"
            font.pointSize: 20
            font.bold: true
            anchors.centerIn: parent
        }
    }
}
