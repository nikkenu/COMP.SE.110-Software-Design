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
                        Chart *chart = nullptr);


signals:
    void getData();

public slots:
    void apiRequest(QString title);



private:
    Fingridhandler fin_;
    FMIhandler fmi_;
    Chart* chart_;

};

#endif // CONTROLLER_H
