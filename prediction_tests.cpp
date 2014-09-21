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
}

prediction_tests::~prediction_tests()
{
    delete ui;
}

void prediction_tests::on_ok_pb_clicked()
{
    this->close();
}

void prediction_tests::on_represent_bt_clicked()
{
    ui->tableWidget->clear();
    QDateTime curr_date = QDateTime::currentDateTime();
    //qDebug() << curr_date;
    if (ui->dmy_cb->currentText() == "день")
        curr_date.addDays(ui->number_cb->currentText().toUInt());
    else if (ui->dmy_cb->currentText() == "месяц")
        curr_date.addMonths(ui->number_cb->currentText().toInt());
    else
        curr_date.addYears(ui->number_cb->currentText().toInt());
    //qDebug() << curr_date;

    QSqlQuery q;
    q.prepare("SELECT "
                "objects.name, "
                "date_test.last_test, "
                "date_test.next_test "
              "FROM "
                "objects, date_test "
              "WHERE "
                "date_test.objects_id = objects.id");
    q.exec();
    int query_str = 0;
    while (q.next())
    {
//        int day = q.value(2).toDate().day();
//        int month = q.value(2).toDate().month();
//        int year = q.value(2).toDate().year();
//        qDebug() << curr_date.date() << " " << q.value(2).toDate();
        if (curr_date.date() == q.value(2).toDate())
        {
            ui->tableWidget->setRowCount(q.size());
            QTableWidgetItem *object = new QTableWidgetItem(q.value(0).toString());
            QTableWidgetItem *last_test = new QTableWidgetItem(q.value(1).toString());
            QTableWidgetItem *next_test = new QTableWidgetItem(q.value(2).toString());
            ui->tableWidget->setItem(query_str, 0, object);
            ui->tableWidget->setItem(query_str, 1, last_test);
            ui->tableWidget->setItem(query_str, 2, next_test);
            query_str++;
        }
    }
}
