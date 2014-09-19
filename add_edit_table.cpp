#include "add_edit_table.h"
#include "ui_add_edit_table.h"
#include "mainwindow.h"
#include <QTreeWidget>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>
#include <QSqlRecord>

add_edit_table::add_edit_table(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::add_edit_table)
{
    ui->setupUi(this);
    this->setWindowTitle("-");
    name_tables.insert(1, "areas");
    name_tables.insert(2, "substations");
    name_tables.insert(3, "object_types");
    name_tables.insert(4, "objects");
    name_tables.insert(5, "date_test");
    connect(ui->cancel_pushButton, SIGNAL(clicked()), this, SLOT(close()));
    connect(ui->table_value_cb_1, SIGNAL(currentIndexChanged(QString)), this, SLOT(change_substation()));
    connect(ui->table_value_cb_2, SIGNAL(currentIndexChanged(QString)), this, SLOT(change_object_type()));
    ui->table_value_cb_1->clear();
    ui->table_value_cb_2->clear();
    ui->table_value_cb_3->clear();
}

add_edit_table::~add_edit_table()
{
    delete ui;
}

void add_edit_table::change_substation()
{
    if (fa == 1)
    {
        fa = 0;
        QSqlQuery query;
        ui->table_value_cb_2->clear();
        query.prepare("SELECT "
                        "name "
                      "FROM "
                        "substations "
                      "WHERE "
                        "area_id = :id;");
        query.bindValue(":id", ui->table_value_cb_1->currentIndex()+1);
        query.exec();
        while (query.next())
        {
            ui->table_value_cb_2->addItem(query.value(0).toString());
        }
    }
}

void add_edit_table::change_object_type()
{
    if (fa == 1)
    {
        fa = 0;
        QSqlQuery query;
        ui->table_value_cb_3->clear();
        query.prepare("SELECT "
                        "name "
                      "FROM "
                        "object_types;");
        query.exec();
        while (query.next())
        {
            ui->table_value_cb_3->addItem(query.value(0).toString());
        }
    }
}

void add_edit_table::recieveData(QTreeWidget* _tree, QString _name_of_table)
{
    tree = _tree;
    name_of_table = _name_of_table;
    ui->name_label->setVisible(true);
    ui->name_lineEdit->setVisible(true);
    ui->table_value_cb_1->setVisible(false);
    ui->table_value_cb_2->setVisible(false);
    ui->table_value_cb_3->setVisible(false);
    ui->DateLastTest->setVisible(false);
    ui->DateLastTestLabel->setVisible(false);
    ui->DateNextTest->setVisible(false);
    ui->DateNextTestLabel->setVisible(false);
    ui->table_value_cb_1->clear();
    ui->table_value_cb_2->clear();
    ui->table_value_cb_3->clear();
    ui->name_lineEdit->setText("");
    QSqlQuery query;
    QString q;
    if (name_of_table == "substations")
    {
        fa = 0;
        ui->table_value_cb_1->setVisible(true);
        q = "SELECT name FROM areas";
        query.exec(q);
        while (query.next())
        {
            ui->table_value_cb_1->addItem(query.value(0).toString());
        }
    }
    else if (name_of_table == "objects")
    {
        fa = 0;
        ui->table_value_cb_1->setVisible(true);
        ui->table_value_cb_2->setVisible(true);
        ui->table_value_cb_3->setVisible(true);
        ui->table_value_cb_1->clear();
        ui->table_value_cb_2->clear();
        ui->table_value_cb_3->clear();;
        query.exec("SELECT name FROM areas");
        while (query.next())
        {
            ui->table_value_cb_1->addItem(query.value(0).toString());
        }
        query.prepare("SELECT "
                        "name "
                      "FROM "
                        "substations "
                      "WHERE "
                        "area_id = :id;");
        query.bindValue(":id", ui->table_value_cb_1->currentIndex()+1);
        query.exec();
        while (query.next())
        {
            ui->table_value_cb_2->addItem(query.value(0).toString());
        }
        query.prepare("SELECT "
                        "name "
                      "FROM "
                        "object_types");
        query.exec();
        while (query.next())
        {
            ui->table_value_cb_3->addItem(query.value(0).toString());
        }
    }
    else if (name_of_table == "object_types")
        fa = 0;
    else if (name_of_table == "date_test")
    {
        fa = 0;
        ui->name_label->setVisible(false);
        ui->name_lineEdit->setVisible(false);
        ui->DateLastTest->setVisible(true);
        ui->DateLastTestLabel->setVisible(true);
        ui->DateNextTest->setVisible(true);
        ui->DateNextTestLabel->setVisible(true);
        ui->table_value_cb_1->setVisible(true);
        ui->table_value_cb_1->clear();
        query.exec("SELECT name FROM objects ORDER BY id");
        while (query.next())
            ui->table_value_cb_1->addItem(query.value(0).toString());
    }
    else
        fa = 0;
    fa = 1;
}

void add_edit_table::on_ok_pushButton_clicked()
{
    if (ui->name_lineEdit->text() != "")
    {
        QSqlQuery query;
        if (name_of_table == "areas")
        {
            query.prepare("INSERT INTO areas "
                            "(name) "
                          "VALUES "
                            "(:name);");;
            query.bindValue(":name", ui->name_lineEdit->text());
            query.exec();
        }
        else if (name_of_table == "object_types")
        {
            query.prepare("INSERT INTO object_types "
                            "(name) "
                          "VALUES "
                            "(:name);");;
            query.bindValue(":name", ui->name_lineEdit->text());
            query.exec();
        }
        else if (name_of_table == "substations")
        {
            int id;
            query.prepare("SELECT "
                            "id "
                          "FROM "
                            "areas "
                          "WHERE "
                            "name = :name_of_table");
            query.bindValue(":name_of_table", ui->table_value_cb_1->currentText());
            query.exec();
            while (query.next())
                id = query.value(0).toInt();
            query.prepare("INSERT INTO substations "
                            "(area_id, name) "
                          "VALUES "
                            "(:id, :name);");
            query.bindValue(":id", id);
            query.bindValue(":name", ui->name_lineEdit->text());
            query.exec();
        }
        else if (name_of_table == "objects")
        {
            int area_id, substation_id, object_type_id;
            query.prepare("SELECT "
                            "id "
                          "FROM "
                            "areas "
                          "WHERE "
                            "name = :name_of_table");
            query.bindValue(":name_of_table", ui->table_value_cb_1->currentText());
            query.exec();
            while (query.next())
                area_id = query.value(0).toInt();
            query.prepare("SELECT "
                            "id "
                          "FROM "
                            "substations "
                          "WHERE "
                            "area_id = :area_id AND name = :substation_name");
            query.bindValue(":area_id", area_id);
            query.bindValue(":substation_name", ui->table_value_cb_2->currentText());
            query.exec();
            while (query.next())
                substation_id = query.value(0).toInt();
            query.prepare("SELECT "
                            "id "
                          "FROM "
                            "object_types "
                          "WHERE "
                            "name = :object_types_name");
            query.bindValue(":object_types_name", ui->table_value_cb_3->currentText());
            query.exec();
            while (query.next())
                object_type_id = query.value(0).toInt();
            query.prepare("INSERT INTO objects "
                            "(substation_id, object_type_id, name) "
                          "VALUES "
                            "(:substation_id, :object_type_id, :name);");
            query.bindValue(":substation_id", substation_id);
            query.bindValue(":object_type_id", object_type_id);
            query.bindValue(":name", ui->name_lineEdit->text());
            query.exec();
        }
        else if (name_of_table == "date_test")
        {
            int id;
            query.prepare("SELECT "
                            "id "
                          "FROM "
                            "objects "
                          "WHERE "
                            "name = :name_of_table");
            query.bindValue(":name_of_table", ui->table_value_cb_1->currentText());
            query.exec();
            while (query.next())
                id = query.value(0).toInt();
            query.prepare("INSERT INTO date_test "
                            "(objects_id, last_test, next_test) "
                          "VALUES "
                            "(:id, :last_test, :next_test);");
            query.bindValue(":id", id);
            query.bindValue(":last_test", ui->DateLastTest->date());
            query.bindValue(":next_test", ui->DateNextTest->date());
            query.exec();
        }
        MainWindow mw;
        mw.RefreshTree(tree);
        ui->table_value_cb_1->clear();
        ui->table_value_cb_2->clear();
        ui->table_value_cb_3->clear();
        this->close();
    }
}
