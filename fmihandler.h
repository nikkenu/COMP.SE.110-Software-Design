#ifndef FMIHANDLER_H
#define FMIHANDLER_H

#include "baseapihandler.h"

class FMIhandler: public BaseAPIhandler
{
public:

    // TODO: Timestep?

    QString CURRENT_TEMPERATURE = "t2m";
    QString OBSERVED_WIND = "ws_10min";
    QString OBSERVED_CLOUDINESS = "n_man";
    QString AVERAGE_TEMPERATURE = "TA_PT1H_AVG";
    QString MIN_TEMPERATURE = "TA_PT1H_MIN";
    QString MAX_TEMPERATURE = "TA_PT1H_MAX";
    QString PREDICTED_WIND = "windspeedms";
    QString PREDICTED_TEMPERATURE = "temperature";

    FMIhandler();

    /*
     * Get current temperature, and observed wind and cloudiness.
     * Tags: t2m (temperature), ws_10min (windspeed) and n_man (cloudiness)
     * If start_time empty -> current time.
    */
    void getObservedPhenomenon(QString start_time, QString end_time, QString place, QString parameter);

    void getPredictedPhenomenon(QString start_time, QString end_time, QString place, QString parameter);

    void getTemperatureDetails(QString start_time, QString end_time, QString place, QString parameter);

private:
    unsigned int TIMESTEP = 30;
    QString BASEURL = "https://opendata.fmi.fi/wfs?request=getFeature&version=2.0.0&";
};

#endif // FMIHANDLER_H
