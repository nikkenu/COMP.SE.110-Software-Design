#include "chart.h"
#include <QDebug>

Chart::Chart(QObject *parent) : QObject(parent)
{

}

Chart::~Chart()
{

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
