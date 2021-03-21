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
        qDebug() << "Start time: " << i.start_time;
        qDebug() << "End time:   " << i.end_time;
        qDebug() << "Value:      " << i.value;
        cnt++;
    }
}

void DataHandler::printXml(const QByteArray &data)
{
    QDomDocument doc;
    doc.setContent(data);

    QDomElement docElem = doc.documentElement();

    QDomNode n = docElem.firstChild();
    while(!n.isNull()) {
        QDomElement e = n.toElement(); // try to convert the node to an element.
        if(!e.isNull()) {
            QDomElement child = e.firstChild().toElement();
            time_series_element tmp;
            while (!child.isNull()) {
                if (child.tagName() == "value") tmp.value = child.text();
                if (child.tagName() == "start_time") tmp.start_time = child.text();
                if (child.tagName() == "end_time") tmp.end_time = child.text();
                child = child.nextSibling().toElement();
            }
            values.push_back(tmp);
        }
        n = n.nextSibling();
    }

    printData();

    // just here for now, need to refactor this out

    //emit sendDataToChart(values);
}


void DataHandler::dataSignal()
{
    emit sendDataToChart(values);
}
