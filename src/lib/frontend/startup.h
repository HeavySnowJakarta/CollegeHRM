// This file is used to descibe the logic when the program starts.
// There are two operations of the startup screen: create a new database
// and open an existing database.

#pragma once
#include "qobject.h"
#include "qquickview.h"
#include "qtmetamacros.h"
#include <QString>
#include <QObject>
#include <QQuickView>

class Startup : public QObject{
    Q_OBJECT // The macro of QObject definitions.

private:
    // Open the page of operations after opening the database.
    void openNewWindow(QString db_path);
    // The pointer to the startup page to close it.
    QQuickView* startup_view;

public:
    // Recieve the `parent` parameter.
    explicit Startup(QQuickView* startup_view, QObject* parent = nullptr);

public slots:
    // Create a new database. Corresponding to the button `New`.
    void create();

    // Open an existing database. Corresponding to the button `Open`.
    void open();
};