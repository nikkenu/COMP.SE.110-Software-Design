#include "datahandler.h"
#include <QDebug>
#include <QDomDocument>

DataHandler::DataHandler()
{

}

void DataHandler::receiveFMIData(QByteArray data)
{
    parseFMIData(data);
}

void DataHandler::parseFingridData(const QByteArray &data)
{
    std::vector<time_series_element> values = {};
    QDomDocument doc;
    doc.setContent(data);

    QDomElement docElem = doc.documentElement();

    QDomNode n = docElem.firstChild();
    while(!n.isNull()) {
        QDomElement e = n.toElement(); // try to convert the node to an element.
        if(!e.isNull()) {
            QDomElement child = e.firstChild().toElement();
            time_series_element tmp = {};
            while (!child.isNull()) {
                if (child.tagName() == "value") tmp.value = child.text();
                if (child.tagName() == "start_time") {
                    tmp.start_time = QDateTime::fromString(child.text(), Qt::ISODate);
                }
                if (child.tagName() == "end_time") {
                    tmp.end_time = QDateTime::fromString(child.text(), Qt::ISODate);
                }
                child = child.nextSibling().toElement();
            }
            values.push_back(tmp);
        }
        n = n.nextSibling();
    }
    // just here for now, need to refactor this out

    qDebug();
    qDebug() << "---Fingrid Data---";
    for(const auto& i : values) {
        qDebug() << "Start_time: " << i.start_time << ", " << "End_time: " << i.end_time << ", " << "value: " << i.value;
    }
    qDebug() << "---Fingrid End---";

    emit sendDataToChart(values);
}

void DataHandler::parseFMIData(const QByteArray &data)
{
    std::vector<fmi_data_element> values = {};

    QDomDocument doc;
    doc.setContent(data);

    QDomElement docElem = doc.documentElement();

    QDomNode wfsMember = docElem.firstChild();

    // While wfs:member attributes exists.
    while(!wfsMember.isNull()) {
       QDomElement bswfsElement = wfsMember.toElement().firstChild().toElement();
       if(!bswfsElement.isNull()) {
           QDomElement child = bswfsElement.firstChild().toElement();
           fmi_data_element tmp = {};
           while(!child.isNull()) {
               if(child.tagName() == "BsWfs:Time") {
                   tmp.time = QDateTime::fromString(child.text(), Qt::ISODate);
               }
               if(child.tagName() == "BsWfs:ParameterValue") tmp.value = child.text();
               child = child.nextSibling().toElement();
           }
           if(tmp.value != "NaN") {
               values.push_back(tmp);
           }
       }
       wfsMember = wfsMember.nextSibling();
    }

    qDebug();
    qDebug() << "---FMI Data---";
    for(const auto& i : values) {
        qDebug() << "Time: " << i.time << ", " << "value: " << i.value;
    }
    qDebug() << "---FMI End---";
}

void DataHandler::receiveFingridData(QByteArray data)
{
    parseFingridData(data);
}

void DataHandler::dataSignal()
{
    //emit sendDataToChart(values);
}


DataHandler *DataHandler::instance = 0;
