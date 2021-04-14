#ifndef BASEAPIHANDLER_H
#define BASEAPIHANDLER_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>

class BaseAPIhandler : public QObject
{
    Q_OBJECT
public:
    explicit BaseAPIhandler(QObject *parent = nullptr);

signals:
    void sendData(QByteArray data);

public slots:
    void get(QNetworkRequest request);


private slots:
    void readyRead();
    void finished(QNetworkReply *reply);
    void sslErrors(QNetworkReply *reply, const QList<QSslError> &errors);
    void error();
    void requestCompleted(QNetworkReply* reply);

protected:
    QString m_baseUrl;
    QByteArray m_apikey;

private:
    QNetworkAccessManager m_manager;

};

#endif // BASEAPIHANDLER_H
