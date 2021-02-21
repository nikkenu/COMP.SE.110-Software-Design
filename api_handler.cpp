#include "api_handler.h"

API_handler::API_handler(QObject *parent) : QObject(parent)
{
    connect(&m_manager, &QNetworkAccessManager::sslErrors, this, &API_handler::sslErrors);
}

void API_handler::get(QNetworkRequest request)
{
    qInfo() << "API request to: " + request.url().toString();
    QNetworkReply* reply = m_manager.get(request);
    connect(reply, &QNetworkReply::readyRead, this, &API_handler::readyRead);
}

void API_handler::readyRead()
{
    QNetworkReply* reply = qobject_cast<QNetworkReply*>(sender());
    qInfo() << reply->readAll();
}

void API_handler::sslErrors(QNetworkReply *reply, const QList<QSslError> &errors)
{
    Q_UNUSED(reply);
    qWarning() << "SSL Error occurred.";
    QSslError error;
    foreach(error, errors){
        qWarning() << error.errorString();
    }

}
