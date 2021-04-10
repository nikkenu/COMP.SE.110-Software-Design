#include "controller.h"

Controller::Controller(QObject *parent,
                       DataHandler *data,
                       Chart *chart) :
    QObject(parent),
    fin_(data),
    fmi_(data),
    data_(data),
    chart_(chart)
{
    connect(data_, &DataHandler::sendDataToChart,
            chart_, &Chart::receiveData);

    connect(chart_, &Chart::getData,
            data_, &DataHandler::dataSignal);

    fixedCall(); // makes one fixed call. only for testing these connections actually work.

}

void Controller::fixedCall()
{
    fin_.getFromFingrid(Fingridhandler::Electricity_consumption, "2021-03-15T13:11:51Z", "2021-03-18T13:11:51Z");
}
