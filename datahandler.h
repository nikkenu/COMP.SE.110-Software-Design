#ifndef DATAHANDLER_H
#define DATAHANDLER_H

#include <QObject>
#include <QXmlStreamReader>
#include <vector>
#include <QDateTime>

class DataHandler : public QObject
{
    Q_OBJECT
public:
    explicit DataHandler(QObject *parent = nullptr);

    void parseFingridData(const QByteArray &data);
    void parseFMIData(const QByteArray &data);

    struct time_series_element {
        QDateTime start_time;
        QDateTime end_time;
        QString value;
    };

    struct fmi_data_element {
        QDateTime time;
        QString value;
    };

public slots:
    void receiveFingridData(QByteArray data);
    void receiveFMIData(QByteArray data);

    void dataSignal();

signals:
    void sendDataToChart(std::vector<DataHandler::time_series_element> data);


private:

    // obviously this has to be reworked but works as a basis for the xml/json/whatever parsing
    QByteArray m_data;
};

#endif // DATAHANDLER_H
