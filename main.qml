import QtQuick 2.14
import QtQuick.Window 2.14
import QtCharts 2.3
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.3

Window {
    width: 930
    height: 720
    visible: true
    title: qsTr("Hello World")

    Row {
        id: chartRow
        padding: 10
        ChartView {
            title: "Line"
            width: 450
            height: 350
            antialiasing: true

            LineSeries {
                name: "LineSeries"
                XYPoint { x: 0; y: 0 }
                XYPoint { x: 1.1; y: 2.1 }
                XYPoint { x: 1.9; y: 3.3 }
                XYPoint { x: 2.1; y: 2.1 }
                XYPoint { x: 2.9; y: 4.9 }
                XYPoint { x: 3.4; y: 3.0 }
                XYPoint { x: 4.1; y: 3.3 }
            }
        }
        ChartView {
            title: "Line"
            width: 450
            height: 350
            antialiasing: true

            LineSeries {
                name: "LineSeries"
                XYPoint { x: 0; y: 0 }
                XYPoint { x: 1.1; y: 2.1 }
                XYPoint { x: 1.9; y: 3.3 }
                XYPoint { x: 2.1; y: 2.1 }
                XYPoint { x: 2.9; y: 4.9 }
                XYPoint { x: 3.4; y: 3.0 }
                XYPoint { x: 4.1; y: 3.3 }
            }
        }
    }

    RowLayout {
        id: dropdownRow
        spacing: 30
        anchors.top: chartRow.bottom
        anchors.fill: parent
        anchors.leftMargin: 10
        anchors.rightMargin: 10

        Text {
            text: "Production"
            font.pixelSize: 12

        }

        ComboBox {
            Layout.fillWidth: true
            height: 15
            model: ["Total", "Wind", "Hydro", "Nuclear"]
        }

        Text {
            text: "Consumption"
            font.pixelSize: 12
        }

        ComboBox {
            Layout.fillWidth: true
            height: 15
            model: ["Total", "Wind", "Hydro", "Nuclear"]
        }
    }
}
