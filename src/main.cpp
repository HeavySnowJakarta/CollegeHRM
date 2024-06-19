#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QDebug>
#include <iostream>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    qDebug() << "This is qDebug output.";
    std::cout << "This is std::cout output." << std::endl;

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/ui/pages/start/screen.qml")));

    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
