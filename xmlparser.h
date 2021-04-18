#ifndef XMLPARSER_H
#define XMLPARSER_H

#include <QObject>
#include <QDateTime>

/*
 * Struct holds specific data points (time and value).
*/
struct time_series_element {
    QDateTime time;
    QString value;
};


/*
 * XmlParser class is used to parser api request data.
 */
class xmlParser : public QObject
{
    Q_OBJECT
public:
    explicit xmlParser(QObject *parent = nullptr);

    /*
     * parseFingridData function
     * Parameters: QByteArray (api request data).
     * Responsiblity: Parse XML data to vector.
     */
    QVector<time_series_element> parseFingridData(const QByteArray &data);

    /*
     * parseFMIdata function
     * Parameters: QByteArray (api request data).
     * Responsiblity: Parse XML data to vector.
     */
    QVector<time_series_element> parseFMIData(const QByteArray &data);

signals:

};

#endif // XMLPARSER_H
