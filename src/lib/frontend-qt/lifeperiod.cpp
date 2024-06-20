#include "lifeperiod.h"

#include "qlogging.h"
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QDebug>
#include <QQmlContext>

#include "startup.h"

void App::debug(const char* msg){
    qDebug() << "\033[34m" << msg << "\033[0m";
}

App::App(int argc, char** argv):
    app(argc, argv), engine()
{
    debug("The program has started. Debug outputting works properly.");
    debug("Initialized debugger. Trying to load QML file...");

    // Get the QML url and connect the signal and slot function.
    const QUrl start_qml_url =
        QUrl(QStringLiteral("qrc:/ui/pages/start/StartScreen.qml"));
    QObject::connect(
        &engine, 
        &QQmlApplicationEngine::objectCreated,
        &app,
        [start_qml_url, this](QObject *obj, const QUrl &objUrl) {
            if (!obj && start_qml_url == objUrl) {
                this->debug("Failed to load QML file.");
                QCoreApplication::exit(-1);
            } else {
                this->debug("QML file loaded successfully.");
            }
        },
        Qt::QueuedConnection
    );

    // Use QQuick.view to show the startup window.
    QQuickView startup_view;
    startup_view.setSource(start_qml_url);
    startup_view.show();

    // Register the slot function of loading the database and opening the
    // opeation page.
    Startup startupManager = Startup(&startup_view);
    engine.rootContext()->setContextProperty("startup", &startupManager);

    // Load the QML file.
    // debug("Trying to load startup QML file...");
    // engine.load(start_qml_url);
}

int App::exec(){
    debug("Now application loop has started.");
    return app.exec();
}