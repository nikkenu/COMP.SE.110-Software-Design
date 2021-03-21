#include "datahandler.h"
#include <QDebug>
#include <QDomDocument>

DataHandler::DataHandler(QObject *parent) : QObject(parent)
{

}

void DataHandler::receiveData(QByteArray data)
{
    m_data = data;
    printXml(data);
}

void DataHandler::printData()
{
    int cnt=0;
    for (const auto& i : values)
    {
        //if (cnt > 15) break;
        cnt++;
        qDebug() << "Start time: " << i.start_time;
        qDebug() << "End time:   " << i.end_time;
        qDebug() << "Value:      " << i.value;
    }
}

void DataHandler::printXml(const QByteArray &data)
{

    QString alku = QString(data);
    //qDebug() << alku;

    QDomDocument doc;
    doc.setContent(data);

    QDomElement docElem = doc.documentElement();

    QDomNode n = docElem.firstChild();
    //qDebug() << n.nodeValue();

    QString value;
    QString start_time;
    QString end_time;
    while (!n.isNull()) {
        QDomElement e = n.toElement();
        if (!e.isNull()) {


            QDomElement child = e.firstChild().toElement();
            while (!child.isNull())
            {
                if (child.tagName() == "value") value=child.text();
                if (child.tagName() == "start_time") start_time=child.text();
                if (child.tagName() == "end_time") end_time=child.text();

                time_series_element tmp = {.start_time=start_time, .end_time=end_time, .value=value};
                values.push_back(tmp);
                child = child.nextSibling().toElement();
            }
        }
        n = n.nextSibling();
    }


    printData();

}
