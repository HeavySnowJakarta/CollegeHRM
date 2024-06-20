#include "startup.h"
#include "qfiledialog.h"
#include "qmessagebox.h"
#include "qobject.h"
#include "qstringliteral.h"

#include <QString>
#include <QFileDialog>
#include <QGuiApplication>
#include <QMessageBox>
#include <QQuickView>
#include <QQmlContext>

Startup::Startup(QQuickView* startup_view, QObject* parent):
    QObject(parent), startup_view(startup_view){}

void Startup::create(){
    // Open a window and let the user to choose where to save the file.
    QString file_path = QFileDialog::getSaveFileName(
        nullptr,
        "Create a database",
        "",
        "Database Files (*.dat)"
    );

    openNewWindow(file_path);
}

void Startup::open(){
    // Open a dialog and let the user to select the file.
    QString file_path = QFileDialog::getOpenFileName(
        nullptr,
        "Open a database",
        "",
        "Database Files (*.dat)"
    );

    openNewWindow(file_path);
}

void Startup::openNewWindow(QString db_path){
    if (db_path.isEmpty()){
        // Show a message box to the user that we failed to open the
        // database.
        QMessageBox::critical(
            nullptr,
            "Failed to open the database",
            "The program is trying to open an invalid database."
        );
        return;
    }

    // Close the startup view and create a new page view.
    startup_view->close();
    QQuickView* view = new QQuickView();
    view->rootContext()->setContextProperty("dbPath", db_path);
    view->setSource(QUrl(QStringLiteral(
        "qrc:/ui/pages/operate/OperateScreen.qml"
    )));
    view->show();
}