#include "prediction_tests.h"
#include "ui_prediction_tests.h"
#define NUM 100

prediction_tests::prediction_tests(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::prediction_tests)
{
    ui->setupUi(this);
    this->setWindowTitle("Проведение испытаний");
    this->setFixedSize(475, 399);
    QStringList num;
    for (int i=0; i<NUM; i++)
        num << QString::number(i+1);
    ui->number_cb->addItems(num);
    QStringList dmy;
    dmy << "день" << "месяц" << "год";
    ui->dmy_cb->addItems(dmy);
    ui->tableWidget->setColumnCount(3);
    QStringList table_header;
    table_header << "Объект" << "Дата последнего испытания" << "Дата следующего испытания";
    ui->tableWidget->setHorizontalHeaderLabels(table_header);
    ui->tableWidget->resizeColumnsToContents();
}

prediction_tests::~prediction_tests()
{
    delete ui;
}

void prediction_tests::on_ok_pb_clicked()
{
    QDate start_date = QDate::currentDate();
    QDate *date = new QDate();

    if (ui->dmy_cb->currentText() == "день")
        date->setDate(start_date.year(), start_date.month(), start_date.day() + ui->number_cb->currentText().toInt(0));
    else if (ui->dmy_cb->currentText() == "месяц")
        date->setDate(start_date.year(), start_date.month() + ui->number_cb->currentText().toInt(0), start_date.day());
    else if (ui->dmy_cb->currentText() == "год")
        date->setDate(start_date.year() + ui->number_cb->currentText().toInt(0), start_date.month(), start_date.day());
    start_date.setDate(date->year(), date->month(), date->day());
    QSqlQuery q;
    q.prepare("SELECT * FROM date_test WHERE next_test = :start_date;");
    q.bindValue(":start_date", start_date);
    q.exec();
    int j = 0;
    while (q.next())
    {
        MainWindow mw;
        mw.FillHash();
        QTableWidgetItem *object = new QTableWidgetItem(mw.obj[q.value(3).toInt(0)]);
        QTableWidgetItem *last_test = new QTableWidgetItem(q.value(1).toString());
        QTableWidgetItem *next_test = new QTableWidgetItem(q.value(2).toString());
        ui->tableWidget->insertRow(j);
        ui->tableWidget->setItem(j, 0, object);
        ui->tableWidget->setItem(j, 1, last_test);
        ui->tableWidget->setItem(j, 2, next_test);
        j++;
    }
}
