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
        x: 40
        y: 380
        text: qsTr("Read data")
        onClicked: {
            chart.showData();
        }
    }

    Component.onCompleted: {
         chart.timeSeries = consumptionChart
    }

}
