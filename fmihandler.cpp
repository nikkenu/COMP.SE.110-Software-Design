#include "fmihandler.h"

FMIhandler::FMIhandler()
{

}

QString FMIhandler::getFromFMIids(FMIhandler::FMIids id)
{
    switch(id) {
        case FMIids::Current_temperature: return "t2m";
        case FMIids::Observed_wind: return "ws_10min";
        case FMIids::Observed_cloudiness: return "n_man";
        case FMIids::Average_temperature: return "TA_PT1H_AVG";
        case FMIids::Min_temperature: return "TA_PT1H_MIN";
        case FMIids::Max_temperature: return "TA_PT1H_MAX";
        case FMIids::Predicted_wind: return "windspeedms";
        case FMIids::Predicted_temperature: return "temperature";
    }
}

void FMIhandler::getObservedPhenomenon(QString start_time, QString end_time, QString place, QString parameter)
{
    qDebug() << QDateTime::currentDateTimeUtc().toString(Qt::ISODate);
    QNetworkRequest rq(QUrl(BASEURL + "starttime=" + start_time + "&endtime=" +
                            end_time + "&storedquery_id=fmi::observations::weather::simple&place=" +
                            place + "&timestep=" + QString::number(TIMESTEP) + "&parameters=" + parameter));
    //qInfo() << rq.url();
    get(rq);
    ID = parameter;
}

void FMIhandler::getPredictedPhenomenon(QString start_time, QString end_time, QString place, QString parameter)
{
    QNetworkRequest rq(QUrl(BASEURL + "starttime=" + start_time + "&endtime=" +
                            end_time + "&storedquery_id=fmi::forecast::hirlam::surface::point::simple&place=" +
                            place + "&timestep=" + QString::number(TIMESTEP) + "&parameters=" + parameter));
    //qInfo() << rq.url();
    get(rq);
    ID = parameter;
}

void FMIhandler::getTemperatureDetails(QString start_time, QString end_time, QString place, QString parameter)
{
    QNetworkRequest rq(QUrl(BASEURL + "starttime=" + start_time + "&endtime=" +
                            end_time + "&storedquery_id=fmi::observations::weather::hourly::simple&place=" +
                            place + "&timestep=" + QString::number(TIMESTEP) + "&parameters=" + parameter));
    //qInfo() << rq.url();
    get(rq);
    ID = parameter;
}
