#include "prediction_tests.h"
#include "ui_prediction_tests.h"
#define NUM 100

prediction_tests::prediction_tests(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::prediction_tests)
{
    ui->setupUi(this);
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
    QSqlQuery q;
    q.prepare("SELECT");
//    for (int i=0; i<3; i++)
//        ui->tableWidget->horizontalHeader()->resizeSection(i, ui->tableWidget->horizontalHeader()->width()/3);
}

prediction_tests::~prediction_tests()
{
    delete ui;
}

void prediction_tests::on_ok_pb_clicked()
{
    this->close();
}
