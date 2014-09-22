#include "add_item.h"
#include "ui_add_item.h"

add_item::add_item(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::add_item)
{
    ui->setupUi(this);
    this->setFixedSize(401, 239);
    ui->type_cb->setVisible(false);
    ui->type_label->setVisible(false);
}

void add_item::GetTree(QTreeWidget *_tree, QString _table)
{
    tree = _tree;
    table = _table;
    FillCB();
}

void add_item::FillCB()
{
    if (table == "object_types")
    {
        ui->type_cb->setVisible(true);
        ui->type_label->setVisible(true);
        QSqlQuery q;
        q.prepare("SELECT DISTINCT subtypes.id, subtypes.name FROM subtypes, object_types WHERE object_type_id = :id");
        q.bindValue(":id", tree->currentItem()->data(0, Qt::UserRole).toInt());
        q.exec();
        while (q.next())
            ui->type_cb->addItem(q.value(1).toString(), q.value(0).toInt());
    }
}

add_item::~add_item()
{
    delete ui;
}
