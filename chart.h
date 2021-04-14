#ifndef CHART_H
#define CHART_H

#include <QBarSeries>
#include <QChart>
#include <QLineSeries>
#include <QObject>
#include <QtCharts>
#include <QDateTime>
//#include "datahandler.h"
#include "xmlparser.h"
#include "fingridhandler.h"
#include "fmihandler.h"

#include <unordered_map>

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
    explicit Chart(QObject *parent = nullptr, xmlParser *parser = nullptr,
                   Fingridhandler *fingridHandler = nullptr,
                   FMIhandler *fmiHandler = nullptr);
    virtual ~Chart();

    //QtCharts::QLineSeries* getTimeSeries() const;
    //void setTimeSeries(QtCharts::QLineSeries *timeSeries);
    //Q_INVOKABLE void showData();

    Q_INVOKABLE void setLineSeries(QLineSeries *lineSeries, QString ID);


    // tells the api handler to get data
    Q_INVOKABLE void getFingridData( const QString &title, const QString &start, const QString &end);
    Q_INVOKABLE void getFMIData( const QString &title, const QString &start, const QString &end);


public slots:
    void receiveFingridData(QByteArray data_from_api, QString ID);
    void receiveFMIData(QByteArray data_from_api, QString ID);

signals:
    void apiRequest(QString title);

    void fingridSeriesReady(QString title);
    void fmiSeriesReady(QString title);

    //void timeSeriesSignal();
    //void getData();

    //void makeRequest();


private:
   // QtCharts::QLineSeries* timeSeries_;
   //std::vector<DataHandler::time_series_element> timeSeriesData = {};

   std::unordered_map<QString, std::vector<time_series_element>> timeSeriesData = {};

   xmlParser *parser_;
   Fingridhandler *fin_;
   FMIhandler *fmi_;


};


#endif // CHART_H
