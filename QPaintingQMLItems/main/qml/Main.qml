import QtQuick
import com.franco.custom

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Custom visual type")

    Logo {
        id: logo1Id
        text: qsTr("Learn Qt")
        bgColor: "green"
        textColor: "white"
        topic: Logo.QTCPP
    }

    Logo {
        anchors {
            top: logo1Id.bottom
            margins: 20
        }

        id: logo2Id
        text: qsTr("Displaying QtQuick")
        bgColor: "dodgerblue"
        textColor: "white"
        topic: Logo.QTQUICK
    }
}
