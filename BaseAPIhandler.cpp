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
}

void BaseAPIhandler::readyRead()
{
    qInfo() << "NetworkManager::readyRead";

    QNetworkReply *reply = qobject_cast<QNetworkReply*>(sender());
    if(reply) {
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
