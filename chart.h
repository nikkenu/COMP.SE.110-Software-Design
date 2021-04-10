#ifndef CHART_H
#define CHART_H

#include <QBarSeries>
#include <QChart>
#include <QLineSeries>
#include <QObject>

#include "datahandler.h"

struct MinMax
{
    int MIN;
    int MAX;
};

class Chart : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QtCharts::QLineSeries* timeSeries READ getTimeSeries WRITE setTimeSeries NOTIFY timeSeriesSignal)

public:
    explicit Chart(QObject *parent = nullptr);
    virtual ~Chart();

    QtCharts::QLineSeries* getTimeSeries() const;

    void setTimeSeries(QtCharts::QLineSeries *timeSeries);

    Q_INVOKABLE void showData();

public slots:
    void receiveData(std::vector<DataHandler::time_series_element> data);

signals:
    void timeSeriesSignal();
    void getData();

    void makeRequest();


private:
    QtCharts::QLineSeries* timeSeries_;

    // populate timeseries with random data for testing
    void randomData();


};


#endif // CHART_H
