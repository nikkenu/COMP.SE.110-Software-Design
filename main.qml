import QtQuick 2.14
import QtQuick.Window 2.14
import QtCharts 2.3
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.3

Window {
    width: 1000
    height: 720
    visible: true

    ChartView {
        id: electricityChart
        x: 10
        y: 10
        width: 480
        height: 300
        antialiasing: true

        ValueAxis {
            id: axisX
            min: 0
            max: 5
            tickCount: 5
        }
        ValueAxis {
            id: axisY
            min: 0
            max: 5
            tickCount: 5
        }

        LineSeries {
            id: consumptionChart
            name: "Electricity consumption"
            visible: true
            axisX: axisX
            axisY: axisY

            XYPoint {
                x: 0
                y: 2
            }

            XYPoint {
                x: 1
                y: 1.2
            }

            XYPoint {
                x: 2
                y: 3.3
            }

            XYPoint {
                x: 5
                y: 2.1
            }
        }
        LineSeries {
            id: consumptionForecastChart
            name: "Electricity consumption forecast"
            visible: false
            XYPoint {
                x: 0
                y: 3
            }

            XYPoint {
                x: 1
                y: 2.2
            }

            XYPoint {
                x: 2
                y: 4.3
            }

            XYPoint {
                x: 5
                y: 3.1
            }
        }
        LineSeries {
            id: productionPredictionChart
            name: "Electricity production prediction"
            visible: false
            XYPoint {
                x: 0
                y: 4
            }

            XYPoint {
                x: 1
                y: 3.2
            }

            XYPoint {
                x: 2
                y: 4.3
            }

            XYPoint {
                x: 5
                y: 4.1
            }
        }
        LineSeries {
            id: productionChart
            name: "Electricity production"
            visible: false
            XYPoint {
                x: 0
                y: 3.5
            }

            XYPoint {
                x: 1
                y: 2.7
            }

            XYPoint {
                x: 2
                y: 4.1
            }

            XYPoint {
                x: 5
                y: 4.7
            }
        }
        LineSeries {
            id: windProductionChart
            name: "Wind power production"
            visible: false
            XYPoint {
                x: 0
                y: 2.3
            }

            XYPoint {
                x: 1
                y: 3.2
            }

            XYPoint {
                x: 2
                y: 3.1
            }

            XYPoint {
                x: 5
                y: 4
            }
        }
        LineSeries {
            id: nuclearProductionChart
            name: "Nuclear power production"
            visible: false
            XYPoint {
                x: 0
                y: 3.7
            }

            XYPoint {
                x: 1
                y: 3.2
            }

            XYPoint {
                x: 2
                y: 3.2
            }

            XYPoint {
                x: 5
                y: 3.5
            }
        }
        LineSeries {
            id: hydroProductionChart
            name: "Hydro power production"
            visible: false
            XYPoint {
                x: 0
                y: 3.6
            }

            XYPoint {
                x: 1
                y: 3.5
            }

            XYPoint {
                x: 2
                y: 3.5
            }

            XYPoint {
                x: 5
                y: 3
            }
        }
    }

    ChartView {
        id: weatherChart
        x: 510
        y: 10
        width: 480
        height: 300
        antialiasing: true

        ValueAxis {
            id: weatherAxisX
            min: 0
            max: 5
            tickCount: 5
        }
        ValueAxis {
            id: weatherAxisY
            min: 0
            max: 5
            tickCount: 5
        }

        LineSeries {
            name: "Temperature"
            id: temperatureChart
            visible: true
            axisX: weatherAxisX
            axisY: weatherAxisY

            XYPoint {
                x: 0
                y: 2
            }

            XYPoint {
                x: 1
                y: 1.2
            }

            XYPoint {
                x: 2
                y: 3.3
            }

            XYPoint {
                x: 5
                y: 2.1
            }
        }
        LineSeries {
            name: "Observed wind"
            id: observedWindChart
            visible: false
            XYPoint {
                x: 0
                y: 2.5
            }

            XYPoint {
                x: 1
                y: 1.7
            }

            XYPoint {
                x: 2
                y: 3.8
            }

            XYPoint {
                x: 5
                y: 2.6
            }
        }
        LineSeries {
            name: "Observed cloudiness"
            id: observedCloudinessChart
            visible: false
            XYPoint {
                x: 0
                y: 3
            }

            XYPoint {
                x: 1
                y: 2.1
            }

            XYPoint {
                x: 2
                y: 2.7
            }

            XYPoint {
                x: 5
                y: 3
            }
        }
        LineSeries {
            name: "Predicted wind"
            id: predictedWindChart
            visible: false
            XYPoint {
                x: 0
                y: 4
            }

            XYPoint {
                x: 1
                y: 3.8
            }

            XYPoint {
                x: 2
                y: 3.6
            }

            XYPoint {
                x: 5
                y: 3.5
            }
        }
        LineSeries {
            name: "Predicted cloudiness"
            id: predictedCloudinessChart
            visible: false
            XYPoint {
                x: 0
                y: 1.2
            }

            XYPoint {
                x: 1
                y: 1.5
            }

            XYPoint {
                x: 2
                y: 1.1
            }

            XYPoint {
                x: 5
                y: 1.7
            }
        }
    }

    GridLayout {
        id: electricityBoxLayout
        x: 10
        y: 320
        width: 480
        height: 200
        columns: 2

        CheckBox {
            id: consumptionBox
            text: qsTr("Electricity consumption")
            checkState: Qt.Checked
            nextCheckState: function() {
                if (checkState == Qt.Checked) {
                    consumptionChart.visible = false
                    return Qt.Unchecked
                }
                else {
                    consumptionChart.visible = true
                    return Qt.Checked
                }
            }
        }

        CheckBox {
            id: consumptionForecastBox
            text: qsTr("Electricity consumption forecast (24h)")
            nextCheckState: function() {
                if (checkState == Qt.Checked) {
                    consumptionForecastChart.visible = false
                    return Qt.Unchecked
                }
                else {
                    consumptionForecastChart.visible = true
                    return Qt.Checked
                }
            }
        }

        CheckBox {
            id: productionPredictionBox
            text: qsTr("Electricity production prediction (24h)")
            nextCheckState: function() {
                if (checkState == Qt.Checked) {
                    productionPredictionChart.visible = false
                    return Qt.Unchecked
                }
                else {
                    productionPredictionChart.visible = true
                    return Qt.Checked
                }
            }
        }

        CheckBox {
            id: productionBox
            text: qsTr("Electricity production")
            nextCheckState: function() {
                if (checkState == Qt.Checked) {
                    productionChart.visible = false
                    return Qt.Unchecked
                }
                else {
                    productionChart.visible = true
                    return Qt.Checked
                }
            }
        }

        CheckBox {
            id: windProductionBox
            text: qsTr("Wind power production")
            nextCheckState: function() {
                if (checkState == Qt.Checked) {
                    windProductionChart.visible = false
                    return Qt.Unchecked
                }
                else {
                    windProductionChart.visible = true
                    return Qt.Checked
                }
            }
        }

        CheckBox {
            id: nuclearProductionBox
            text: qsTr("Nuclear power production")
            nextCheckState: function() {
                if (checkState == Qt.Checked) {
                    nuclearProductionChart.visible = false
                    return Qt.Unchecked
                }
                else {
                    nuclearProductionChart.visible = true
                    return Qt.Checked
                }
            }
        }

        CheckBox {
            id: hydroProductionBox
            text: qsTr("Hydro power production")
            nextCheckState: function() {
                if (checkState == Qt.Checked) {
                    hydroProductionChart.visible = false
                    return Qt.Unchecked
                }
                else {
                    hydroProductionChart.visible = true
                    return Qt.Checked
                }
            }
        }
    }

    GridLayout {
        id: weatherBoxLayout
        x: 510
        y: 320
        width: 480
        height: 148
        transformOrigin: Item.Center
        columns: 2

        CheckBox {
            id: temperatureBox
            text: qsTr("Temperature")
            checkState: Qt.Checked
            nextCheckState: function() {
                if (checkState == Qt.Checked) {
                    temperatureChart.visible = false
                    return Qt.Unchecked
                }
                else {
                    temperatureChart.visible = true
                    return Qt.Checked
                }
            }
        }

        CheckBox {
            id: observedWindBox
            text: qsTr("Observed wind")
            nextCheckState: function() {
                if (checkState == Qt.Checked) {
                    observedWindChart.visible = false
                    return Qt.Unchecked
                }
                else {
                    observedWindChart.visible = true
                    return Qt.Checked
                }
            }
        }

        CheckBox {
            id: observedCloudinessBox
            text: qsTr("Observed cloudiness")
            nextCheckState: function() {
                if (checkState == Qt.Checked) {
                    observedCloudinessChart.visible = false
                    return Qt.Unchecked
                }
                else {
                    observedCloudinessChart.visible = true
                    return Qt.Checked
                }
            }
        }

        CheckBox {
            id: predictedWindBox
            text: qsTr("Predicted wind")
            nextCheckState: function() {
                if (checkState == Qt.Checked) {
                    predictedWindChart.visible = false
                    return Qt.Unchecked
                }
                else {
                    predictedWindChart.visible = true
                    return Qt.Checked
                }
            }
        }

        CheckBox {
            id: predictedCloudinessBox
            text: qsTr("Predicted cloudiness")
            nextCheckState: function() {
                if (checkState == Qt.Checked) {
                    predictedCloudinessChart.visible = false
                    return Qt.Unchecked
                }
                else {
                    predictedCloudinessChart.visible = true
                    return Qt.Checked
                }
            }
        }
    }

}
