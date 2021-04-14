#include "chart.h"
#include <QDebug>

Chart::Chart(QObject *parent,
             xmlParser *parser,
             Fingridhandler *fingridHandler,
             FMIhandler *fmiHandler) :
    QObject(parent), parser_(parser), fin_(fingridHandler), fmi_(fmiHandler)
{

}

Chart::~Chart()
{

}

void Chart::setLineSeries(QLineSeries *lineSeries, QString ID)
{

    auto it = timeSeriesData.find(ID);
    if (it == timeSeriesData.end())
    {
        qDebug() << "no such data for ID: " << ID;
        // no such data
        return;
    }
    auto data = it->second;
    int cnt{0};
    for(const auto& i : data)
    {
        qreal x,y;
        y = i.value.toDouble();
        x = i.time.toMSecsSinceEpoch();
        lineSeries->append(x,y);
        cnt++;
    }

    qDebug() << "cnt at the end: " << cnt;
}

void Chart::getData( const QString &title, const QString &start, const QString &end)
{
    qDebug() << "getData";
    //emit apiRequest(title);

    if (title == "124")
    {
        fin_->getFromFingrid(124, start, end);
    }
    else if (title == "74")
    {
        qDebug() << "ebin";
        fin_->getFromFingrid(74, start, end);
    }
}

void Chart::receiveData( QByteArray data_from_api, QString ID)
{
    auto parsedData = parser_->parseFingridData(data_from_api);
    qDebug() << "heres johnny with the ID: " << ID;
    //this->timeSeriesData = parsedData;

    timeSeriesData.insert({ID, parsedData});

    QString signal{};
//    if (ID == "124")
//        signal = "Electricity consumption in Finland";
//    else
//        signal = "Electricity production";

    emit timeSeriesReady(ID);

}
