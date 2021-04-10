#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>

#include "fingridhandler.h"
#include "fmihandler.h"
#include "datahandler.h"
#include "chart.h"

class Controller : public QObject
{
    Q_OBJECT
public:
    explicit Controller(QObject *parent = nullptr,
                        DataHandler *data = nullptr,
                        Chart *chart = nullptr);




signals:
    void getData();

public slots:




private:
    Fingridhandler fin_;
    FMIhandler fmi_;
    DataHandler* data_;
    Chart* chart_;

    void fixedCall();

};

#endif // CONTROLLER_H
