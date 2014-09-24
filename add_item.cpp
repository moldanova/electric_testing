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

void add_item::GetTypeObj(QTreeWidget *_tree, QListWidgetItem* _type_itm)
{
    type_itm = _type_itm;
    table = "object_types";
    tree = _tree;
    sot = 1;
    FillCB();
}

void add_item::FillCB()
{
    int id;
    if (table == "object_types")
    {
        ui->type_cb->setVisible(true);
        ui->type_label->setVisible(true);
        QSqlQuery q;
        if (sot == 1)
        {
            q.prepare("SELECT id FROM object_types WHERE name = :type");
            q.bindValue(":type", type_itm->text());
            q.exec();
            q.next();
            id = q.value(0).toInt();
        }
        else
            id = tree->currentItem()->data(0, Qt::UserRole).toInt();
        q.prepare("SELECT DISTINCT subtypes.id, subtypes.name FROM subtypes, object_types WHERE object_type_id = :id");
        q.bindValue(":id", id);
        q.exec();
        while (q.next())
            ui->type_cb->addItem(q.value(1).toString(), q.value(0).toInt());
    }
}

add_item::~add_item()
{
    delete ui;
}

void add_item::on_cancel_pb_clicked()
{
    this->close();
}

void add_item::on_ok_pb_clicked()
{
    if (ui->name_edit->text() != "")
    {
        QSqlQuery query;
        MainWindow mw;
        if (table == "areas")
        {
            int id;
            id = tree->currentItem()->data(0, Qt::UserRole).toInt();
            query.prepare("INSERT INTO substations "
                            "(area_id, name) "
                          "VALUES "
                            "(:id, :name) "
                          "RETURNING id");
            query.bindValue(":id", id);
            query.bindValue(":name", ui->name_edit->text());
            query.exec();
            query.next();
            QTreeWidgetItem *itm = new QTreeWidgetItem();
            itm->setText(0, ui->name_edit->text());
            itm->setData(0, Qt::UserRole, query.value(0).toInt());
            tree->currentItem()->addChild(itm);
        }
        else if (table == "object_types" && sot == 1)
        {
            mw.FillHash();
            int index = -1;
            for (int i=0; i<tree->currentItem()->childCount(); i++)
                if (tree->currentItem()->child(i)->data(0, Qt::UserRole).toInt() ==
                        type_itm->data(Qt::UserRole).toInt())
                {
                    index = i;
                    tree->setCurrentItem(tree->currentItem()->child(index));
                    break;
                }
            if (index == -1)
            {
                QTreeWidgetItem *tree_itm = new QTreeWidgetItem();
                tree_itm->setText(0, type_itm->text());
                tree_itm->setData(0, Qt::UserRole, type_itm->data(Qt::UserRole).toInt());
                tree->currentItem()->addChild(tree_itm);
                tree->setCurrentItem(tree_itm);
            }

            AddObject();
            sot = 0;
        }
        else if (table == "object_types")
        {
            AddObject();
        }
        mw.FillHash();
        ui->type_cb->clear();
        this->close();
    }
}

void add_item::AddObject()
{
    QSqlQuery query;
    int area_id, substation_id, object_type_id;
    area_id = tree->currentItem()->parent()->parent()->data(0, Qt::UserRole).toInt();
    substation_id = tree->currentItem()->parent()->data(0, Qt::UserRole).toInt();
    object_type_id = tree->currentItem()->data(0, Qt::UserRole).toInt();
    query.prepare("INSERT INTO objects "
                    "(substation_id, object_type_id, name, subtype_id) "
                  "VALUES "
                    "(:substation_id, :object_type_id, :name, :subtype_id) "
                  "RETURNING id");
    query.bindValue(":substation_id", substation_id);
    query.bindValue(":object_type_id", object_type_id);
    query.bindValue(":name", ui->name_edit->text());
    query.bindValue(":subtype_id", ui->type_cb->currentData(Qt::UserRole).toInt());
    query.exec();
    query.next();
    QTreeWidgetItem *itm = new QTreeWidgetItem();
    itm->setText(0, ui->name_edit->text());
    itm->setData(0, Qt::UserRole, query.value(0).toInt());
    tree->currentItem()->addChild(itm);
}
