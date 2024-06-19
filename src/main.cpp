#include "qcoreapplication.h"
#include "qdebug.h"
#include "qlogging.h"
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
    qDebug() << "Program has  started to run.";

    // Initialize Qt app manager for control stream and settings.
    QGuiApplication app(argc, argv);
    qDebug() << "Created QGuiApplication.";

    // Object to load, parse and manage QML files.
    QQmlApplicationEngine engine;
    qDebug() << "Created QQmlApplicationEngine. Loading QRC URL...";
    // Define the URL of the QRC file.
    const QUrl qml_url = QUrl(QStringLiteral("./qml.qrc"));
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
            if (!obj && qml_url == objUrl){
                qDebug() << "Failed to load startup QML file.";
                QCoreApplication::exit(-1);
            }
            else {
                qDebug() << "Loaded startup QML file successfully.";
            }
        },
        // The type of connection.
        Qt::QueuedConnection
    );
    qDebug() << "Loading startup QML file...";
    engine.load(QUrl(QStringLiteral("qrc:/ui/pages/start/screen.qml")));

    // Run the GUI app and deal with the events.
    qDebug() << "Running GUI app...";
    return app.exec();
}
