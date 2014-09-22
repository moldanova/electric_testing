#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "add_item.h"
#include "ui_add_item.h"
#include <QMessageBox>
#include <QTreeWidgetItem>
#include <QString>
#include <QDebug>
#include <QSqlQuery>
#include <QMap>

add_item::add_item(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::add_item)
{
    ui->setupUi(this);
    this->setWindowTitle("Выбор таблицы");
    //connect(ui->Cancel_Button, SIGNAL(clicked()), this, SLOT(close()));

    name_tables.insert("Районы", "areas");
    name_tables.insert("Подстанции", "substations");
    name_tables.insert("Типы объектов", "object_types");
    name_tables.insert("Объекты", "objects");
    name_tables.insert("Испытания объектов на подстанциях", "date_test");
    QStringList name;
    name << "Районы" << "Подстанции" << "Типы объектов" << "Объекты" << "Испытания объектов на подстанциях";
    //ui->table_list->addItems(name);

    new_ae_form = new add_edit_table();
    //connect(ui->Ok_Button, SIGNAL(clicked()), new_ae_form, SLOT(show()));// подключаем сигнал к слоту
    //connect(ui->Ok_Button, SIGNAL(clicked()), this, SLOT(onButtonSend())); // подключаем клик по кнопке к определенному нами слоту
    //connect(this, SIGNAL(sendData(QTreeWidget*, QString)), new_ae_form, SLOT(recieveData(QTreeWidget*, QString)));
    //connect(ui->Ok_Button, SIGNAL(clicked()), this, SLOT(close()));
}

add_item::~add_item()
{
    delete ui;
}

void add_item::recieveData(QTreeWidget *_tree)
{
    tree = _tree;
    //but_cl = _but_cl;
}

void add_item::onButtonSend()
{
    //QString temp = ui->table_list->currentItem()->text();
    //emit sendData(tree, name_tables.lowerBound(temp).value());
}
