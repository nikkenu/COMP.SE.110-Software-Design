import QtQuick 2.14
import QtQuick.Window 2.14
import QtCharts 2.3
import QtQuick.Controls 2.4
import QtQuick.Layouts 1.3
import QtQuick.Controls 1.4
//import Chart 1.0

Window {
    id: window
    width: 1000
    height: 720
    visible: true
    property alias rowLayoutWidth: rowLayout.width

    Connections {
        target: chart
        onTimeSeriesReady: function(x){
            var tmp = chartView.createSeries(ChartView.SeriesTypeLine, x, dateTimeXaxis, electricityValueYaxis);
            chart.setLineSeries(tmp);
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

            DateTimeAxis {
                id: dateTimeXaxis
            }

            ValueAxis {
                id: electricityValueYaxis
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
                            chart.getData("124");
                        } else {
                            // Remove lineseries
                        }
                    }
                }

                CheckBox {
                    id: eProdCheckBox
                    text: qsTr("Electricity production")
                    onCheckedStateChanged: function() {
                        if(checkedState) {
                            // Make API request
                        } else {
                            // Remove lineseries
                        }
                    }
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
                        enabled: false;
                    }

                    CheckBox {
                        id: nowCheckBox
                        text: qsTr("Now")
                        checked: true
                        onCheckedStateChanged: function() {
                            if(checkedState) {
                                dateToTextField.enabled = false;
                            } else {
                                dateToTextField.enabled = true;
                            }
                        }
                    }
                }


                Button {
                    id: refreshButton
                    text: qsTr("Refresh")
                }
            }

        }

    }

}

/*##^##
Designer {
    D{i:0;formeditorZoom:0.75}D{i:9}D{i:13}D{i:1}
}
##^##*/
