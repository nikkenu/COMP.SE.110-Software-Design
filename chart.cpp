#include "chart.h"

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
