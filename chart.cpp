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

void Chart::getFMIData(const QString &title, const QString &start, const QString &end)
{

    // REMOVE THIS LATER...
    QString place = "Pirkkala";

    if(title == fmi_->getFromFMIids(FMIhandler::FMIids::Current_temperature) ||
            title == fmi_->getFromFMIids(FMIhandler::FMIids::Observed_wind) ||
            title == fmi_->getFromFMIids(FMIhandler::FMIids::Observed_cloudiness)) {
        fmi_->getObservedPhenomenon(start, end, place, title);
    } else if(title == fmi_->getFromFMIids(FMIhandler::FMIids::Average_temperature) ||
              title == fmi_->getFromFMIids(FMIhandler::FMIids::Min_temperature) ||
              title == fmi_->getFromFMIids(FMIhandler::FMIids::Max_temperature)) {
        fmi_->getTemperatureDetails(start, end, place, title);
    } else {
        fmi_->getPredictedPhenomenon(start, end, place, title);
    }
}

QString Chart::calcPercentage(QString ID)
{
    QString nuclearPercentage = "empty";
    double tmp = 0;

    if (timeSeriesData.find("74") != timeSeriesData.end())
    {
        if (timeSeriesData.find(ID) != timeSeriesData.end())
        {
            double totalProduced = 0;
            std::vector<time_series_element> elementsProduced = timeSeriesData.at("74");
            for(auto i : elementsProduced)
            {
                QString tmp2 = i.value;
                double tmp3 = tmp2.toDouble();
                totalProduced = totalProduced + tmp3;
            }

            double totalPowerForm = 0;
            std::vector<time_series_element> elementsPowerForm = timeSeriesData.at(ID);
            for(auto i : elementsPowerForm)
            {
                QString tmp2 = i.value;
                double tmp3 = tmp2.toDouble();
                totalPowerForm = totalPowerForm + tmp3;
            }

            if(ID == "188" || ID == "191")
            {
                totalPowerForm = totalPowerForm/20;
            }

            tmp = totalPowerForm / totalProduced * 100;
            nuclearPercentage = QString::number(tmp);

        }
        else
        {
            qDebug() << "No data for power form.";
        }
    }
    else
    {
        qDebug() << "No data for power produced.";
    }

    qDebug() << "percentage: " << nuclearPercentage;

    return nuclearPercentage;
}

void Chart::getFingridData( const QString &title, const QString &start, const QString &end)
{
    qDebug() << "getData";
    //emit apiRequest(title);
    fin_->getFromFingrid(title.toInt(), start, end);
//    if (title == "124")
//    {
//        fin_->getFromFingrid(124, start, end);
//    }
//    else if (title == "74")
//    {
//        fin_->getFromFingrid(74, start, end);
//    }
//    else if (title == "188")
//    {
//        fin_->getFromFingrid(188, start, end);
//    }
//    else if (title == "191")
//    {
//        fin_->getFromFingrid(191, start, end);
//    }
//    else if (title == "245")
//    {
//        fin_->getFromFingrid(245, start, end);
//    }
}

void Chart::receiveFingridData( QByteArray data_from_api, QString ID)
{
    auto parsedData = parser_->parseFingridData(data_from_api);
    qDebug() << "heres johnny with the ID: " << ID;
    //this->timeSeriesData = parsedData;

    if (timeSeriesData.find(ID) == timeSeriesData.end())
    {
        timeSeriesData.insert({ID, parsedData});
    }
    else
    {
        timeSeriesData.at(ID) = parsedData;
    }

    QString signal{};
//    if (ID == "124")
//        signal = "Electricity consumption in Finland";
//    else
//        signal = "Electricity production";

    emit fingridSeriesReady(ID);

}

void Chart::receiveFMIData(QByteArray data_from_api, QString ID)
{
    qDebug() << "HERERE: " << ID;
    auto parsedData = parser_->parseFMIData(data_from_api);

    if (timeSeriesData.find(ID) == timeSeriesData.end())
    {
        timeSeriesData.insert({ID, parsedData});
    }
    else
    {
        timeSeriesData.at(ID) = parsedData;
    }

    emit fmiSeriesReady(ID);
}
