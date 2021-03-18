#include "fingridhandler.h"

Fingridhandler::Fingridhandler()
{
    m_baseUrl = "https://api.fingrid.fi/v1/variable/";
    m_apikey = "W8AlS1jgxO7XygNLzms35afCiMEltmZL2ohQkmSP";
}

void Fingridhandler::getFromFingrid(int id, QString start_time, QString end_time)
{
    // id into a string
    QString string_id = QString::number(id);
    qDebug() << string_id;
    QNetworkRequest rq(QUrl(m_baseUrl + string_id + "/events/xml?start_time=" + start_time + "&end_time=" + end_time));
    rq.setRawHeader("x-api-key", m_apikey);
    qDebug() << rq.url();
    get(rq);
}
