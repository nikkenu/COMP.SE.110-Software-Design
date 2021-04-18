import QtQuick 2.14
import QtQuick.Window 2.14
import QtCharts 2.3
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.3
import QtQuick.Controls 1.4
import QtQuick.Dialogs 1.0
//import Chart 1.0

Window {
    id: window
    width: 1000
    height: 720
    visible: true
    property var graphId: 1
    property var win;
    property alias rowLayoutWidth: rowLayout.width
    property var register: {"t2m" : "Current temperature", "ws_10min": "Observed wind", "n_man":"Observed cloudiness",
    "TA_PT1H_MIN":"Minimum temperature", "TA_PT1H_AVG":"Average temperature", "TA_PT1H_MAX":"Maximum temperature",
    "windspeedms":"Predicted wind", "temperature":"Predicted temperature", 124 : "Electricity consumption",
    165 : "Electricity consumption forecast", 74 : "Electricity production", 242 : "Tentative production prediction",
    188 : "Nuclear power production", 191 : "Hydro power production", 245 : "Wind power production"}

    Connections {
        target: chart

        onFingridSeriesReady: function(x){
            var tmp = chartView.createSeries(ChartView.SeriesTypeLine, register[x], dateTimeXaxis, electricityValueYaxis);
            chart.setLineSeries(tmp, x);
        }
        onFmiSeriesReady: function(x) {
            var tmp = chartView.createSeries(ChartView.SeriesTypeLine, register[x], dateTimeXaxis, weatherValueYaxis);
            chart.setLineSeries(tmp, x);
        }



    }

    Column {
        id: column
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        anchors.rightMargin: 0
        anchors.leftMargin: 0
        anchors.bottomMargin: 0
        anchors.topMargin: 0

        ChartView {
            id: chartView
            width: column.width
            height: column.height/2
            backgroundColor: "#00000000"

            ValueAxis {
                id: weatherValueYaxis
                min: -40
                max: 40
            }

            DateTimeAxis {
                id: dateTimeXaxis
                min: "2021-03-15T13:11:51Z"
                max: "2021-03-18T13:11:51Z"
            }

            ValueAxis {
                id: electricityValueYaxis
                min: 0
                max: 15000
            }

        }

        RowLayout {
            id: rowLayout2
            width: 100
            height: 100
            spacing: 20

            Column {
                id: column1
                height: 330
                padding: 10
                spacing: 5

                Text {
                    id: text2
                    text: qsTr("Electricity")
                    font.pixelSize: 12
                }

                CheckBox {
                    id: electricityConsumptionCheckBox
                    text: qsTr("Electricity consumption in Finland")
                    onCheckedStateChanged: function() {
                        if(checkedState) {
                            chart.getFingridData("124", dateFromTextField.text, dateToTextField.text);
                        } else {
                            chartView.removeSeries(chartView.series(register["124"]));
                        }
                    }
                }

                CheckBox {
                    id: eProdCheckBox
                    text: qsTr("Electricity production")
                    onCheckedStateChanged: function() {
                        if(checkedState) {
                            chart.getFingridData("74", dateFromTextField.text, dateToTextField.text);
                        } else {
                            // Remove lineseries
                            chartView.removeSeries(chartView.series(register["74"]))
                        }
                    }
                }

                CheckBox {
                    id: nuclearPowerCheckBox
                    text: qsTr("Nuclear production")
                    onCheckedStateChanged: function() {
                        if(checkedState) {
                            chart.getFingridData("188", dateFromTextField.text, dateToTextField.text);
                        } else {
                            // Remove lineseries
                            chartView.removeSeries(chartView.series(register["188"]))
                        }
                    }
                }

                CheckBox {
                    id: hydropowerCheckBox
                    text: qsTr("Hydro power production")
                    onCheckedStateChanged: function() {
                        if(checkedState) {
                            chart.getFingridData("191", dateFromTextField.text, dateToTextField.text);
                        } else {
                            // Remove lineseries
                            chartView.removeSeries(chartView.series(register["191"]))
                        }
                    }
                }


                CheckBox {
                    id: windpowerCheckBox
                    text: qsTr("Wind production")
                    onCheckedStateChanged: function() {
                        if(checkedState) {
                            chart.getFingridData("245", dateFromTextField.text, dateToTextField.text);
                        } else {
                            // Remove lineseries
                            chartView.removeSeries(chartView.series(register["245"]))
                        }
                    }
                }

                CheckBox {
                    id: tentativeProdCheckBox
                    text: qsTr("Tentative production prediction")
                    onCheckedStateChanged: function() {
                        if(checkedState) {
                            chart.getFingridData("242", dateFromTextField.text, dateToTextField.text);
                        } else {
                            // Remove lineseries
                            chartView.removeSeries(chartView.series(register["242"]))
                        }
                    }
                }

            }

            Column {
                id: column2
                width: 200
                height: 400

                Text {
                    id: text1
                    text: qsTr("Weather")
                    font.pixelSize: 12
                }

                CheckBox {
                    id: currentTempCheckBox
                    text: qsTr("Current temperature")
                    onCheckedStateChanged: function() {
                        if(checkedState) {
                            chart.getFMIData("t2m", dateFromTextField.text, dateToTextField.text);
                        } else {
                            // Remove lineseries
                            chartView.removeSeries(chartView.series(register["t2m"]))
                        }
                    }
                }

                CheckBox {
                    id: observedWindCheckBox
                    text: qsTr("Observed wind")
                    onCheckedStateChanged: function() {
                        if(checkedState) {
                            chart.getFMIData("ws_10min", dateFromTextField.text, dateToTextField.text);
                        } else {
                            // Remove lineseries
                            chartView.removeSeries(chartView.series(register["ws_10min"]))
                        }
                    }
                }

                CheckBox {
                    id: observedCloudCheckBox
                    text: qsTr("Observed cloudiness")
                    onCheckedStateChanged: function() {
                        if(checkedState) {
                            chart.getFMIData("n_man", dateFromTextField.text, dateToTextField.text);
                        } else {
                            // Remove lineseries
                            chartView.removeSeries(chartView.series(register["n_man"]))
                        }
                    }
                }

                CheckBox {
                    id: avgTempCheckBox
                    text: qsTr("Average temperature")
                    onCheckedStateChanged: function() {
                        if(checkedState) {
                            chart.getFMIData("TA_PT1H_AVG", dateFromTextField.text, dateToTextField.text);
                        } else {
                            // Remove lineseries
                            chartView.removeSeries(chartView.series(register["TA_PT1H_AVG"]))
                        }
                    }
                }

                CheckBox {
                    id: minTempCheckBox
                    text: qsTr("Minimum temperature")
                    onCheckedStateChanged: function() {
                        if(checkedState) {
                            chart.getFMIData("TA_PT1H_MIN", dateFromTextField.text, dateToTextField.text);
                        } else {
                            // Remove lineseries
                            chartView.removeSeries(chartView.series(register["TA_PT1H_MIN"]))
                        }
                    }
                }

                CheckBox {
                    id: maxTempCheckBox
                    text: qsTr("Maximum temperature")
                    onCheckedStateChanged: function() {
                        if(checkedState) {
                            chart.getFMIData("TA_PT1H_MAX", dateFromTextField.text, dateToTextField.text);
                        } else {
                            // Remove lineseries
                            chartView.removeSeries(chartView.series(register["TA_PT1H_MAX"]))
                        }
                    }
                }

                CheckBox {
                    id: predictedWindCheckBox
                    text: qsTr("Predicted wind")
                    onCheckedStateChanged: function() {
                        if(checkedState) {
                            chart.getFMIData("windspeedms", dateFromTextField.text, dateToTextField.text);
                        } else {
                            // Remove lineseries
                            chartView.removeSeries(chartView.series(register["windspeedms"]))
                        }
                    }
                }

                CheckBox {
                    id: predictedTempCheckBox
                    text: qsTr("Predicted temperature")
                    onCheckedStateChanged: function() {
                        if(checkedState) {
                            chart.getFMIData("temperature", dateFromTextField.text, dateToTextField.text);
                        } else {
                            // Remove lineseries
                            chartView.removeSeries(chartView.series(register["temperature"]))
                        }
                    }
                }


                ComboBox {
                    id: weatherLocation
                    model: ["Pirkkala", "Helsinki", "Oulu"]

                    onActivated: chart.changeLocation(currentText)
                }
            }

            Column {
                id: column3
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

                    Button {
                        id: nowCheckBox
                        text: qsTr("Now")
                        checked: true
                        onClicked: function()
                        {
                            var date = chart.currentTime()
                            dateFromTextField.text = date
                        }
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

                    Button {
                        id: nowCheckBox2
                        text: qsTr("Now")
                        checked: true
                        onClicked: function()
                        {
                            var date = chart.currentTime()
                            dateToTextField.text = date
                        }
                    }
                }


                Button {
                    id: refreshButton
                    text: qsTr("Refresh")

                    onClicked:
                    {
                        dateTimeXaxis.min = dateFromTextField.text
                        dateTimeXaxis.max = dateToTextField.text
                    }
                }

            }
            Column {
                id: column4
                width: 200
                spacing: 5

                Button {
                    id: saveButton
                    text: "Save chart"
                    onClicked: saveChart()
                }

                Button {
                    id: openButton
                    text: "Open chart"
                    onClicked: openChart()
                }

                Text {
                    id: saveStatus
                    text: qsTr("")
                }

                Timer {
                    id: saveStatusTimer
                    interval: 3000
                    running: false
                    onTriggered: {
                        saveStatus.text = "";
                        running = false;
                    }
                }
            }

            Column {
                id: columnPercentages
                width: 200
                height: 239
                spacing: 5


                Text {
                    id: text7
                    text: qsTr("Percentage of each power form")
                    font.pixelSize: 12
                }

                RowLayout {
                    id: rowLayoutNuclear

                    Text {
                        id: text8
                        width: 100
                        text: qsTr("Nuclear")
                        font.pixelSize: 12
                    }

                    TextField {
                        id: nuclearPercentage
                        width: 100
                        height: 20
                        text: "000"
                        placeholderText: qsTr("Text Field")
                        enabled: false;
                    }

                }

                RowLayout {
                    id: rowLayoutHydro

                    Text {
                        id: text9
                        width: 100
                        text: qsTr("Hydro")
                        font.pixelSize: 12
                    }

                    TextField {
                        id: hydroPercentage
                        width: 100
                        height: 20
                        text: "100"
                        placeholderText: qsTr("Text Field")
                        enabled: false;
                    }

                }

                RowLayout {
                    id: rowLayoutWind

                    Text {
                        id: text10
                        width: 100
                        text: qsTr("Wind")
                        font.pixelSize: 12
                    }

                    TextField {
                        id: windPercentage
                        width: 100
                        height: 20
                        text: "200"
                        placeholderText: qsTr("Text Field")
                        enabled: false;
                    }

                }




                Button {
                    id: calculatePercentages
                    text: qsTr("Calculate")

                    onClicked:
                    {
                        nuclearPercentage.text  = chart.calcPercentage("188")
                        hydroPercentage.text = chart.calcPercentage("191")
                        windPercentage.text = chart.calcPercentage("245")
                    }
                }
            }



        }

    }

    function saveChart() {
        console.log(appPath);
        chartView.grabToImage(function(img) {
            img.saveToFile(appPath + "/saved_chart.png");
        });
        saveStatus.text = "Saved chart";
        saveStatusTimer.start();
    }

    function openChart() {
        var component = Qt.createComponent("savedChart.qml");
        win = component.createObject(window);
        win.show();

    }

}

/*##^##
Designer {
    D{i:0;formeditorZoom:1.66}
}
##^##*/
