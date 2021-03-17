#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QApplication>
#include "api_handler.h"

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);
    //W8AlS1jgxO7XygNLzms35afCiMEltmZL2ohQkmSP
    API_handler asd;
    QNetworkRequest request(QUrl("https://api.fingrid.fi/v1/variable/193/event/json"));
    request.setRawHeader("x-api-key", "W8AlS1jgxO7XygNLzms35afCiMEltmZL2ohQkmSP");
    asd.get(request);

    return app.exec();
}