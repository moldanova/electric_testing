#ifndef PREDICTION_TESTS_H
#define PREDICTION_TESTS_H

#include <QWidget>
#include <QTableWidget>
#include <QSqlQuery>
#include <QDebug>
#include <QTableWidgetItem>
#include <QDate>
#include <QDateTime>

namespace Ui {
class prediction_tests;
}

class prediction_tests : public QWidget
{
    Q_OBJECT

public:
    explicit prediction_tests(QWidget *parent = 0);
    ~prediction_tests();

private slots:
    void on_ok_pb_clicked();

    //void on_represent_clicked();

    void on_represent_bt_clicked();

private:
    Ui::prediction_tests *ui;
};

#endif // PREDICTION_TESTS_H
