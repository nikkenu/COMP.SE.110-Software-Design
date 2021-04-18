#ifndef BASEAPIHANDLER_H
#define BASEAPIHANDLER_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>

/*
 * BaseAPIhandler is base class, which represent basic functionality of API request.
*/
class BaseAPIhandler : public QObject
{
    Q_OBJECT
public:
    explicit BaseAPIhandler(QObject *parent = nullptr);

signals:
    /*
     * sendData signal.
     * Parameters QByteArray data (contais request data, which we have received from the call),
     * QString ID, which represents ID e.g. "temperature".
    */
    void sendData(QByteArray data, QString ID);

public slots:
    /*
     * get slot.
     * Parameters: QNetworkRequest, which contains request URL and other data.
     * get function passed get request to QNetworkAccessManager.
    */
    void get(QNetworkRequest request);


private slots:
    /*
     * readyRead is useless in our current implementation.
    */
    void readyRead();

    /*
     *  finished slot.
     *  QNetworkAccessManager emits signal, when network reply is finished.
    */
    void finished(QNetworkReply *reply);

    /*
     *  sslErrors slot is called, if api request had problems with ssl certificate.
    */
    void sslErrors(QNetworkReply *reply, const QList<QSslError> &errors);

    /*
     *  error slot is called, if something went wrong during api request.
    */
    void error();

    /*
     *  requestCompleted slot is called, when QNetworkAccessManager is finished.
    */
    void requestCompleted(QNetworkReply* reply);

protected:
    QString m_baseUrl;
    QByteArray m_apikey;
    QString ID; // API are we calling? Also sends to ID info back to the chart for context.

private:
    QNetworkAccessManager m_manager;

};

#endif // BASEAPIHANDLER_H
