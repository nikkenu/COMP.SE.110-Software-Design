#include "controller.h"

Controller::Controller(QObject *parent,
                       Chart *chart) :
    QObject(parent),
    chart_(chart)
{
//    DataHandler &dataHandler = DataHandler::getInstance();

//    connect(&dataHandler, &DataHandler::sendDataToChart,
//            chart_, &Chart::receiveData);

    /*connect(chart_, &Chart::getData,
            &dataHandler, &DataHandler::dataSignal);*/

    // chart sends signals to controller
    connect(chart_, &Chart::apiRequest,
            this, &Controller::apiRequest);
}

void Controller::apiRequest(QString title)
{
    if(title == "124") {
        fin_.getFromFingrid(124, "2021-03-15T13:11:51Z", "2021-03-18T13:11:51Z");
    }
}
