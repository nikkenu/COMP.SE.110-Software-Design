#ifndef FINGRIDHANDLER_H
#define FINGRIDHANDLER_H

#include "BaseAPIhandler.h"

class Fingridhandler: public BaseAPIhandler
{
public:

    /*
     * Electricity consumption in Finland // Id 124 // MWh/h
     * Electricity consumption forecast for the next 24 hours // Id 165 // MWh/h
     * Electricity production in Finland // Id 74 // MWh/h
     * A tentative production prediction for the next 24 hours as an hourly energy // Id 242 // MWh/h
     * Nuclear power production // Id 188 // MW
     * Hydro power production // Id 191 // MW
     * Wind power production forecast // Id 245 // MWh/h
    */
    enum FingridApiIds {
        Electricity_consumption = 124,
        Electricity_consumption_forecast = 165,
        Electricity_production_in_Finland = 74,
        Tentative_production_prediction = 242,
        Nuclear_power_production = 188,
        Hydro_power_production = 191,
        Wind_power_production = 245
    };

    Fingridhandler();

    /*
     * Fingrid API call.
     * parameters: id, start_time, end_time
     * Timeformat: YYYY-MM-DDThh:mm:ssZ
    */
    void getFromFingrid(int id, QString start_time, QString end_time);

};

#endif // FINGRIDHANDLER_H
