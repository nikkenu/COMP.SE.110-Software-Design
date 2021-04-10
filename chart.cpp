#include "chart.h"

#include <QDebug>
#include <QValueAxis>

const QList<MinMax> ELECTICITY_CONSUMPTION_LIMTS = { { 0, 200}, { 8500, 12500} };

Chart::Chart(QObject *parent) : QObject(parent), timeSeries_(new QtCharts::QLineSeries)
{

}

Chart::~Chart()
{
    delete timeSeries_;
}

QtCharts::QLineSeries *Chart::getTimeSeries() const
{
    return timeSeries_;
}

void Chart::setTimeSeries(QtCharts::QLineSeries *timeSeries)
{

    timeSeries_ = timeSeries;
    timeSeries_->setName("paras sähkönkulutus ikinä");


    // axis from exaxmple, very little idea of what is going on here...
    QList<QtCharts::QAbstractAxis*> axisList = timeSeries_->attachedAxes();
    for (int axisIndex{0}; axisIndex < 2 && axisIndex < axisList.length(); ++axisIndex)
    {
        auto axis = axisList.at(axisIndex);
        if (axis->type() == QtCharts::QAbstractAxis::AxisType::AxisTypeValue)
        {
            auto valueAxis = dynamic_cast<QtCharts::QValueAxis*>(axis);
            valueAxis->setMin(ELECTICITY_CONSUMPTION_LIMTS[axisIndex].MIN);
            valueAxis->setMax(ELECTICITY_CONSUMPTION_LIMTS[axisIndex].MAX);

            timeSeries_->attachAxis(valueAxis);
        }
    }
    emit timeSeriesSignal();
}

void Chart::showData()
{
    qInfo() << "data button clicked";
    emit getData();
}

void Chart::randomData()
{

}

void Chart::receiveData(std::vector<DataHandler::time_series_element> data)
{
    auto cnt = timeSeries_->count();
    for (const auto& i : data)
    {
        qreal x,y;
        auto tmp = i.value;
        x=cnt;
        y= tmp.toDouble();
        cnt++;

        timeSeries_->append(x,y);

    }

    qDebug() << timeSeries_->count();
    qDebug() << "ebin";
    emit timeSeriesSignal();
}
