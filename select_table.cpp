#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "select_table.h"
#include "ui_select_table.h"
#include <QMessageBox>
#include <QTreeWidgetItem>
#include <QString>
#include <QDebug>
#include <QSqlQuery>
#include <QMap>

select_table::select_table(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::select_table)
{
    ui->setupUi(this);
    this->setWindowTitle("Выбор таблицы");
    connect(ui->Cancel_Button, SIGNAL(clicked()), this, SLOT(close()));

    name_tables.insert("Районы", "areas");
    name_tables.insert("Подстанции", "substations");
    name_tables.insert("Типы объектов", "object_types");
    name_tables.insert("Объекты", "objects");
    QStringList name;
    name << "Районы" << "Подстанции" << "Типы объектов" << "Объекты";
    ui->table_list->addItems(name);

    new_ae_form = new add_edit_table();
    connect(ui->Ok_Button, SIGNAL(clicked()), new_ae_form, SLOT(show()));// подключаем сигнал к слоту
    connect(ui->Ok_Button, SIGNAL(clicked()), this, SLOT(onButtonSend())); // подключаем клик по кнопке к определенному нами слоту
    connect(this, SIGNAL(sendData(QTreeWidget*, QString)), new_ae_form, SLOT(recieveData(QTreeWidget*, QString)));
    //connect(ui->Ok_Button, SIGNAL(clicked()), this, SLOT(close()));
}

select_table::~select_table()
{
    delete ui;
}

void select_table::recieveData(QTreeWidget *_tree)
{
    tree = _tree;
    //but_cl = _but_cl;
}

void select_table::onButtonSend()
{
    QString temp = ui->table_list->currentItem()->text();
    emit sendData(tree, name_tables.lowerBound(temp).value());
}
