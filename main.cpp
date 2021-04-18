#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QApplication>
#include <QQmlContext>
#include "fmihandler.h"
#include "fingridhandler.h"
#include "chart.h"

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QApplication app(argc, argv);

    QQmlApplicationEngine engine;

    xmlParser parser;
    FMIhandler fmi;
    Fingridhandler fin;

    Chart chart(nullptr, &parser, &fin, &fmi);
    engine.rootContext()->setContextProperty("chart", &chart);
    //qmlRegisterType<Chart>("Chart", 1, 0, "Chart");
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    QObject::connect(&fin, &Fingridhandler::sendData,
                     &chart, &Chart::receiveFingridData);
    QObject::connect(&fmi, &FMIhandler::sendData,
                     &chart, &Chart::receiveFMIData);


    return app.exec();
}
