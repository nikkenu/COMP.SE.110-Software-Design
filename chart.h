#ifndef CHART_H
#define CHART_H

#include <QBarSeries>
#include <QChart>
#include <QLineSeries>
#include <QObject>

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





signals:
    void timeSeriesSignal();


private:
    QtCharts::QLineSeries* timeSeries_;

    void randomData();


};


#endif // CHART_H
