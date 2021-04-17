#ifndef XMLPARSER_H
#define XMLPARSER_H

#include <QObject>
#include <QDateTime>

struct time_series_element {
    QDateTime time;
    QString value;
};

class xmlParser : public QObject
{
    Q_OBJECT
public:
    explicit xmlParser(QObject *parent = nullptr);

    QVector<time_series_element> parseFingridData(const QByteArray &data);
    QVector<time_series_element> parseFMIData(const QByteArray &data);

signals:

};

#endif // XMLPARSER_H
