// This file is used to descibe the logic when the program starts.
// There are two operations of the startup screen: create a new database
// and open an existing database.

#pragma once
#include "qobject.h"
#include "qtmetamacros.h"
#include <QString>
#include <QObject>

class Startup : public QObject{
    Q_OBJECT // The macro of QObject definitions.

private:
    // Open the page of operations after opening the database.
    void openNewWindow(QObject* window, QString db_path);

public:
    // Recieve the `parent` parameter.
    explicit Startup(QObject* parent = nullptr) : QObject(parent){}

public slots:
    // Create a new database. Corresponding to the button `New`.
    void create(QObject* current_window_ptr);

    // Open an existing database. Corresponding to the button `Open`.
    void open(QObject* current_window_ptr);
};