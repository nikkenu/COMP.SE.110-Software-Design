#ifndef API_HANDLER_H
#define API_HANDLER_H

#include <QObject>
#include <QDebug>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>

class API_handler : public QObject
{
    Q_OBJECT
public:
    explicit API_handler(QObject *parent = nullptr);

signals:

public slots:
    void get(QNetworkRequest request);

private slots:
    void readyRead();
    void sslErrors(QNetworkReply* reply, const QList<QSslError> &errors);

private:
    QNetworkAccessManager m_manager;

};

#endif // API_HANDLER_H
