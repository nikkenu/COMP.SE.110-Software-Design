#include "fmihandler.h"

FMIhandler::FMIhandler()
{
    DataHandler &dataHandler = DataHandler::getInstance();
    QObject::connect(this, &FMIhandler::sendData, &dataHandler,
                       &DataHandler::receiveFMIData);
}

void FMIhandler::getObservedPhenomenon(QString start_time, QString end_time, QString place, QString parameter)
{
    qDebug() << QDateTime::currentDateTimeUtc().toString(Qt::ISODate);

    QNetworkRequest rq(QUrl(BASEURL + "starttime=" + start_time + "&endtime=" +
                            end_time + "&storedquery_id=fmi::observations::weather::simple&place=" +
                            place + "&timestep=" + QString::number(TIMESTEP) + "&parameters=" + parameter));
    //qInfo() << rq.url();
    get(rq);
}

void FMIhandler::getPredictedPhenomenon(QString start_time, QString end_time, QString place, QString parameter)
{
    QNetworkRequest rq(QUrl(BASEURL + "starttime=" + start_time + "&endtime=" +
                            end_time + "&storedquery_id=fmi::forecast::hirlam::surface::point::simple&place=" +
                            place + "&timestep=" + QString::number(TIMESTEP) + "&parameters=" + parameter));
    //qInfo() << rq.url();
    get(rq);
}

void FMIhandler::getTemperatureDetails(QString start_time, QString end_time, QString place, QString parameter)
{
    QNetworkRequest rq(QUrl(BASEURL + "starttime=" + start_time + "&endtime=" +
                            end_time + "&storedquery_id=fmi::observations::weather::hourly::simple&place=" +
                            place + "&timestep=" + QString::number(TIMESTEP) + "&parameters=" + parameter));
    //qInfo() << rq.url();
    get(rq);
}
