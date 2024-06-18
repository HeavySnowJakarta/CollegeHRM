#include "qcoreapplication.h"
#include "qnamespace.h"
#include "qobject.h"
#include "qqmlapplicationengine.h"
#include "qstringliteral.h"
#include "qurl.h"
#include <QGuiApplication>
#include <QQmlApplicationEngine>

int main(int argc, char *argv[])
{
    // No need to enable hight DPI support for Qt6+.

    // Initialize Qt app manager for control stream and settings.
    QGuiApplication app(argc, argv);

    // Object to load, parse and manage QML files.
    QQmlApplicationEngine engine;
    // Define the URL of the QRC file.
    const QUrl qml_url = QUrl(QStringLiteral("qrc:main.qml"));
    // Connect signals with slots.
    QObject::connect(
        // The signal sender, `engine` here.
        &engine,
        // The signal to be sent, whose parameters are the object created
        // and the URL.
        &QQmlApplicationEngine::objectCreated,
        // The reciever of the signal, here it acts like where the signal
        // and slot are connected.
        &app,
        // Slot function, which checks if the QML object has been created
        // properly.
        [qml_url](QObject *obj, const QUrl &objUrl){
            if (!obj && qml_url == objUrl)
                QCoreApplication::exit(-1);
        },
        // The type of connection.
        Qt::QueuedConnection
    );
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    // Run the GUI app and deal with the events.
    return app.exec();
}
