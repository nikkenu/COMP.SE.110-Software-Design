#include "baseapihandler.h"

BaseAPIhandler::BaseAPIhandler(QObject *parent) : QObject(parent)
{
    connect(&m_manager, &QNetworkAccessManager::sslErrors,this,&BaseAPIhandler::sslErrors);
    connect(&m_manager, &QNetworkAccessManager::finished, this, &BaseAPIhandler::requestCompleted);
}

void BaseAPIhandler::get(QNetworkRequest request)
{
    //qInfo() << "NetworkManager get";
    QNetworkReply *reply = m_manager.get(request);
    connect(reply, static_cast<void (QNetworkReply::*)(QNetworkReply::NetworkError)>(&QNetworkReply::error), this, &BaseAPIhandler::error);
}

void BaseAPIhandler::readyRead()
{
    //qInfo() << "NetworkManager::readyRead";

   // QNetworkReply *reply = qobject_cast<QNetworkReply*>(sender());
    //if(reply->error() == QNetworkReply::NoError) {
        //qInfo() << "Reply exists";
        //qInfo() << reply->readAll();
}

void BaseAPIhandler::finished(QNetworkReply *reply)
{
    //Q_UNUSED(reply);
    qInfo() << "NetworkManager reply finished.";
    qDebug() << reply->readAll();
    reply->deleteLater();
}

void BaseAPIhandler::sslErrors(QNetworkReply *reply, const QList<QSslError> &errors)
{
    Q_UNUSED(reply);
    qInfo() << "NetworkManager ssl error: " << errors;
}

void BaseAPIhandler::error()
{
    qInfo() << "Base API handler error!";
}

void BaseAPIhandler::requestCompleted(QNetworkReply *reply)
{
    QByteArray content{ reply->readAll() };
    emit sendData(content, ID);
    ID=""; //reset id
}

