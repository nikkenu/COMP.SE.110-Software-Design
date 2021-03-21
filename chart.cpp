#include "chart.h"

#include <QDebug>

Chart::Chart(QObject *parent) : QObject(parent), timeSeries_(new QtCharts::QLineSeries)
{

}

Chart::~Chart()
{
    delete timeSeries_;
}

QtCharts::QLineSeries *Chart::getTimeSeries() const
{

}

void Chart::setTimeSeries(QtCharts::QLineSeries *timeSeries)
{

}

void Chart::showData()
{

}

void Chart::randomData()
{

}

void Chart::receiveData(std::vector<DataHandler::time_series_element> data)
{
    for (const auto& i : data)
    {
        qDebug() << i.value;
    }
}
