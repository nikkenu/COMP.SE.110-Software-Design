#include "chart.h"
#include <QDebug>

Chart::Chart(QObject *parent) : QObject(parent)
{

}

Chart::~Chart()
{

}

void Chart::setLineSeries(QLineSeries *lineSeries)
{
    // Sample data
    for(int i = 0; i < 10; i++) {
        lineSeries->append(i, i);
    }
}

void Chart::getData(const QString &title)
{
    qDebug() << "getData";
    emit apiRequest(title);
}

void Chart::receiveData(std::vector<DataHandler::time_series_element> data)
{
    this->timeSeriesData = data;
    qDebug() << "here";
    emit timeSeriesReady("ASD");
}
