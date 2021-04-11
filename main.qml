import QtQuick 2.14
import QtQuick.Window 2.14
import QtCharts 2.3
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.3
import QtQuick.Controls 1.4


Window {
    width: 1000
    height: 720
    visible: true
    property alias rowLayoutWidth: rowLayout.width

    ChartView {
        id: electricityChart
        x: 10
        y: 10
        width: 480
        height: 350
        antialiasing: true

        LineSeries {
            id: consumptionChart
        }
        LineSeries {
            id: consumptionForecastChart
        }
        LineSeries {
            id: productionPredictionChart
        }
        LineSeries {
            id: productionChart
        }
        LineSeries {
            id: windProductionChart
        }
        LineSeries {
            id: nuclearProductionChart
        }
        LineSeries {
            id: hydroProductionChart
        }
    }

    ChartView {
        id: weatherChart
        x: 510
        y: 10
        width: 480
        height: 350
        antialiasing: true

        LineSeries {
            id: temperatureChart
        }
        LineSeries {
            id: observedWindChart
        }
        LineSeries {
            id: observedCloudinessChart
        }
        LineSeries {
            id: predictedWindChart
        }
        LineSeries {
            id: predictedCloudinessChart
        }
    }

    Button {
        id: dataButton
        x: 843
        y: 633
        text: qsTr("Read data")
        onClicked: {
            chart.showData();
            chart.makeRequest();
        }
    }

    Column {
        id: column
        x: 10
        y: 366
        width: 203
        height: 330
        spacing: 5

        Text {
            id: text1
            text: qsTr("Weather")
            font.pixelSize: 12
        }

        CheckBox {
            id: temperatureCheckBox
            text: qsTr("Temperature")
        }

        CheckBox {
            id: observedWindCheckBox
            text: qsTr("Observed wind")
        }

        CheckBox {
            id: observedCloudinessCheckBox
            text: qsTr("Observed cloudiness")
        }

        CheckBox {
            id: predictedWindCheckBox
            text: qsTr("Predicted wind")
        }

        CheckBox {
            id: predictedTemperatureCheckBox
            text: qsTr("Predicted temperature")
        }
    }

    Column {
        id: column1
        x: 219
        y: 366
        width: 406
        height: 330
        spacing: 5

        Text {
            id: text2
            text: qsTr("Electricity")
            font.pixelSize: 12
        }

        CheckBox {
            id: electricityConsumptionCheckBox
            text: qsTr("Electricity consumption in Finland")
        }

        CheckBox {
            id: eConForeCheckBox
            text: qsTr("Electricity consumption forecast for the nesxt 24 hours")
        }

        CheckBox {
            id: tProdPredCheckBox
            text: qsTr("A tentative production prediction for the next 24 hours as hourly energy")
        }

        CheckBox {
            id: eProdCheckBox
            text: qsTr("Electricity production")
        }

        CheckBox {
            id: windProdCheckBox
            text: qsTr("Wind power production forecast")
        }

        CheckBox {
            id: nuclearProdCheckBox
            text: qsTr("Nuclear power production")
        }

        CheckBox {
            id: hydroProdCheckBox
            text: qsTr("Hydro power production")
        }
    }

    Column {
        id: column2
        x: 631
        y: 366
        width: 143
        height: 330
        spacing: 5

        Text {
            id: text3
            text: qsTr("Temperature")
            font.pixelSize: 12
        }

        CheckBox {
            id: tempAvgCheckBox
            text: qsTr("Average")
        }

        CheckBox {
            id: tempMinCheckBox
            text: qsTr("Minimum")
        }

        CheckBox {
            id: tempMaxCheckBox
            text: qsTr("Maximum")
        }
    }

    Column {
        id: column3
        x: 780
        y: 366
        width: 200
        height: 239
        spacing: 5

        Text {
            id: text4
            text: qsTr("Date")
            font.pixelSize: 12
        }

        RowLayout {
            id: rowLayout

            Text {
                id: text5
                text: qsTr("From")
                font.pixelSize: 12
            }

            TextField {
                id: dateFromTextField
                text: "2021-03-15T13:11:51Z"
                placeholderText: qsTr("Text Field")
            }

        }

        RowLayout {
            id: rowLayout1

            Text {
                id: text6
                text: qsTr("To")
                font.pixelSize: 12
            }

            TextField {
                id: dateToTextField
                width: 127
                height: 20
                text: "2021-03-18T13:11:51Z"
                placeholderText: qsTr("Text Field")
            }

            CheckBox {
                id: nowCheckBox
                text: qsTr("Now")
            }
        }

    }




    Component.onCompleted: {
        chart.timeSeries = consumptionChart
    }

}

/*##^##
Designer {
    D{i:0;formeditorZoom:0.75}
}
##^##*/
