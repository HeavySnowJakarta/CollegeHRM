#include "qlogging.h"
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QDebug>

// Print debug info in blue texts.
void debug(const char* msg){
    qDebug() << "\033[34m" << msg << "\033[0m";
}

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    debug("The program has started. Debug outputting works properly.");

    QQmlApplicationEngine engine;
    debug("Initialized debugger. Trying to load QML file...");

    // Get the QML URL and connect signal and slot function.
    const QUrl start_qml_url =
        QUrl(QStringLiteral("qrc:/ui/pages/start/StartScreen.qml"));
    QObject::connect(
        &engine, 
        &QQmlApplicationEngine::objectCreated,
        &app,
        [start_qml_url](QObject *obj, const QUrl &objUrl) {
            if (!obj && start_qml_url == objUrl) {
                debug("Failed to load QML file.");
                QCoreApplication::exit(-1);
            } else {
                debug("QML file loaded successfully.");
            }
        },
        Qt::QueuedConnection
    );

    // Load the QML file.
    debug("Trying to load startup QML file...");
    engine.load(start_qml_url);

    debug("Now application loop has started.");
    return app.exec();
}
