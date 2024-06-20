// This file contains necessary Qt related objects and maintain the whole
// life period.

#pragma once
#include <QGuiApplication>
#include <QQmlApplicationEngine>

class App{
private:
    QGuiApplication app;
    QQmlApplicationEngine engine;
public:
    // The function to output debug strings on this project.
    inline void debug(const char* msg);

    App(int argc, char** argv);

    // Call and return the result of `app.exec()`.
    int exec();
};