#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QApplication>
#include <QQmlContext>
#include "fmihandler.h"
#include "fingridhandler.h"
#include "datahandler.h"
#include "chart.h"

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QApplication app(argc, argv);

    QQmlApplicationEngine engine;
    Chart chart;
    engine.rootContext()->setContextProperty("chart", &chart);
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    Fingridhandler fin;
    DataHandler data;
    FMIhandler fmi;

    QObject::connect(&data, &DataHandler::sendDataToChart,
                     &chart, &Chart::receiveData);

    QObject::connect(&fin, &Fingridhandler::sendData, &data,
                     &DataHandler::receiveData);

    QObject::connect(&chart, &Chart::getData,
                     &data, &DataHandler::dataSignal);


    fmi.getTemperatureDetails("2021-01-19T09:00:00Z", "2021-01-19T14:00:00Z", "Pirkkala", fmi.AVERAGE_TEMPERATURE);
    fin.getFromFingrid(Fingridhandler::Electricity_consumption, "2021-03-15T13:11:51Z", "2021-03-18T13:11:51Z");

    return app.exec();
}
