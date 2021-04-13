#ifndef CHART_H
#define CHART_H

#include <QBarSeries>
#include <QChart>
#include <QLineSeries>
#include <QObject>
#include <QtCharts>
#include "datahandler.h"

struct MinMax
{
    int MIN;
    int MAX;
};

class Chart : public QObject
{
    Q_OBJECT
    //Q_PROPERTY(QtCharts::QLineSeries* timeSeries READ getTimeSeries WRITE setTimeSeries NOTIFY timeSeriesSignal)

public:
    explicit Chart(QObject *parent = nullptr);
    virtual ~Chart();

    //QtCharts::QLineSeries* getTimeSeries() const;
    //void setTimeSeries(QtCharts::QLineSeries *timeSeries);
    //Q_INVOKABLE void showData();

    Q_INVOKABLE void setLineSeries(QLineSeries *lineSeries);
    Q_INVOKABLE void getData(const QString &title);


public slots:
    void receiveData(std::vector<DataHandler::time_series_element> data);

signals:
    void apiRequest(QString title);

    void timeSeriesReady(QString title);

    //void timeSeriesSignal();
    //void getData();

    //void makeRequest();


private:
   // QtCharts::QLineSeries* timeSeries_;
   std::vector<DataHandler::time_series_element> timeSeriesData = {};


};


#endif // CHART_H
