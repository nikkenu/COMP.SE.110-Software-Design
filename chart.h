#ifndef CHART_H
#define CHART_H

#include <QBarSeries>
#include <QChart>
#include <QLineSeries>
#include <QObject>
#include <QtCharts>
#include <QDateTime>
#include "xmlparser.h"
#include "fingridhandler.h"
#include "fmihandler.h"

#include <unordered_map>
#include <unordered_set>

class Chart : public QObject
{
    Q_OBJECT

public:
    explicit Chart(QObject *parent = nullptr, xmlParser *parser = nullptr,
                   Fingridhandler *fingridHandler = nullptr,
                   FMIhandler *fmiHandler = nullptr);
    virtual ~Chart();

    Q_INVOKABLE void setLineSeries(QLineSeries *lineSeries, QString ID);

    // tells the api handler to get data
    Q_INVOKABLE void getFingridData( const QString &title, const QString &start, const QString &end);
    Q_INVOKABLE void getFMIData( const QString &title, const QString &start, const QString &end);

    Q_INVOKABLE void changeLocation(QString location);

    Q_INVOKABLE QString calcPercentage(QString ID);

    Q_INVOKABLE QString currentTime();


public slots:
    void receiveFingridData(QByteArray data_from_api, QString ID);
    void receiveFMIData(QByteArray data_from_api, QString ID);

signals:
    void fingridSeriesReady(QString title);
    void fmiSeriesReady(QString title);


private:
   QMap<QString, QVector<time_series_element>> timeSeriesData = {};

   xmlParser *parser_;
   Fingridhandler *fin_;
   FMIhandler *fmi_;


   QString currentLocation_{"Pirkkala"};

};


#endif // CHART_H
