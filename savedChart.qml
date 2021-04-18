import QtQuick 2.0
import QtQuick.Window 2.0

Window {
    width: 1000
    height: 400
    title: "Saved chart"

    Image {
        id: chartImg
        source: "file:///" + appPath + "/saved_chart.png"
    }
}
