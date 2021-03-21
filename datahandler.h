#ifndef DATAHANDLER_H
#define DATAHANDLER_H

#include <QObject>
#include <QXmlStreamReader>

#include <vector>


class DataHandler : public QObject
{
    Q_OBJECT
public:
    explicit DataHandler(QObject *parent = nullptr);

    void printXml(const QByteArray &data);


public slots:
    void receiveData(QByteArray data);

signals:

private:

    struct time_series_element {
        QString start_time;
        QString end_time;
        QString value;
    };

    void printData();
    // obviously this has to be reworked but works as a basis for the xml/json/whatever parsing
    QByteArray m_data;
    std::vector<time_series_element> values;
};

#endif // DATAHANDLER_H
