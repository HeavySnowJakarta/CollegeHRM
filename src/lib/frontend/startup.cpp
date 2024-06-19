#include "startup.h"
#include "qfiledialog.h"

#include <QString>
#include <QFileDialog>
#include <QGuiApplication>

void Startup::create(){
    // Open a dialog and let the user to choose where to save the file.
    QString file_path = QFileDialog::getSaveFileName(
        nullptr,
        "Create a database",
        "",
        "Database Files (*.dat)"
    );
}

void Startup::open(){
    // Open a dialog and let the user to select the file.
    QString file_path = QFileDialog::getOpenFileName(
        nullptr,
        "Open a database",
        "",
        "Database Files (*.dat)"
    );
}