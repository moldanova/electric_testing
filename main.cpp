#include "mainwindow.h"
#include "connect_to_db.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    Database db_;
    db_.Connect();
    w.ShowTree();
    w.show();
    return a.exec();
}
