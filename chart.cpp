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
    for(const auto& i : timeSeriesData)
    {
        qreal x,y;
        auto tmp = i.value;
        y = tmp.toDouble();
        auto tmp2 = i.time;
        x = tmp2.toMSecsSinceEpoch();

        lineSeries->append(x,y);
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
    emit timeSeriesReady("Electricity consumption in Finland");
}
