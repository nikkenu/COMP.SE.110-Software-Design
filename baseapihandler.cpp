#include "BaseAPIhandler.h"

BaseAPIhandler::BaseAPIhandler(QObject *parent) : QObject(parent)
{
    connect(&m_manager, &QNetworkAccessManager::sslErrors,this,&BaseAPIhandler::sslErrors);
}

void BaseAPIhandler::get(QNetworkRequest request)
{
    qInfo() << "NetworkManager get";
    QNetworkReply *reply = m_manager.get(request);
    connect(reply, &QNetworkReply::readyRead,this,&BaseAPIhandler::readyRead);
    connect(reply, static_cast<void (QNetworkReply::*)(QNetworkReply::NetworkError)>(&QNetworkReply::error), this, &BaseAPIhandler::error);
}

void BaseAPIhandler::readyRead()
{
    qInfo() << "NetworkManager::readyRead";

    QNetworkReply *reply = qobject_cast<QNetworkReply*>(sender());
    if(reply->error() != QNetworkReply::NoError) {
        qInfo() << "Reply exists";
        qInfo() << reply->readAll();
    }
}

void BaseAPIhandler::finished(QNetworkReply *reply)
{
    Q_UNUSED(reply);
    qInfo() << "NetworkManager reply finished.";
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
