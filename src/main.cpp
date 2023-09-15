////
/// Credits to https://github.com/bricke/Qt-AES for the encryption code.
/// Credits to QT for the software used to develop this.

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "threadmanager.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    //Create encryption thingy (Will be threaded later)
    threadmanager core;

    QQmlApplicationEngine engine;

    //Connect encryption system to UI
    engine.rootContext()->setContextProperty("core", &core);

    const QUrl url(u"qrc:/EncryptionTool/main.qml"_qs);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
        &app, [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        }, Qt::QueuedConnection);
    engine.load(url);



    return app.exec();
}
