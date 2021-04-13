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
    emit apiRequest(title);
}

void Chart::receiveData(std::vector<DataHandler::time_series_element> data)
{
    this->timeSeriesData = data;
}
