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

void add_item::GetTypeObj(QListWidgetItem* _type_itm)
{
    type_itm = _type_itm;
    table = "object_types";
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
        if (type_itm->text() != "")
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
            QTreeWidgetItem *itm = new QTreeWidgetItem();
            itm->setText(0, ui->name_edit->text());
            itm->setData(0, Qt::UserRole, query.value(0).toInt());
            tree->currentItem()->addChild(itm);
        }
        else if (table == "substations")
        {
            int area_id, substation_id, object_type_id;
            area_id = tree->currentItem()->parent()->data(0, Qt::UserRole).toInt();
            substation_id = tree->currentItem()->data(0, Qt::UserRole).toInt();
            object_type_id = type_itm->data(Qt::UserRole).toInt();
            query.prepare("INSERT INTO objects "
                            "(substation_id, object_type_id, name) "
                          "VALUES "
                            "(:substation_id, :object_type_id, :name) "
                          "RETURNING id");
            query.bindValue(":substation_id", substation_id);
            query.bindValue(":object_type_id", object_type_id);
            query.bindValue(":name", ui->name_edit->text());
            query.exec();
            QTreeWidgetItem *itm = new QTreeWidgetItem();
            itm->setText(0, ui->name_edit->text());
            itm->setData(0, Qt::UserRole, query.value(0).toInt());
            for (int i=0; i<tree->currentItem()->childCount(); i++)
                if (tree->currentItem()->child(i)->text(0) == type_itm->text())
                {
                    tree->currentItem()->child(i)->addChild(itm);
                    break;
                }
        }
        else if (table == "object_types")
        {
            int area_id, substation_id, object_type_id;
            area_id = tree->currentItem()->parent()->parent()->data(0, Qt::UserRole).toInt();
            substation_id = tree->currentItem()->parent()->data(0, Qt::UserRole).toInt();
            object_type_id = tree->currentItem()->data(0, Qt::UserRole).toInt();
            query.prepare("INSERT INTO objects "
                            "(substation_id, object_type_id, name) "
                          "VALUES "
                            "(:substation_id, :object_type_id, :name);");
            query.bindValue(":substation_id", substation_id);
            query.bindValue(":object_type_id", object_type_id);
            query.bindValue(":name", ui->name_edit->text());
            query.exec();
            QTreeWidgetItem *itm = new QTreeWidgetItem();
            itm->setText(0, ui->name_edit->text());
            itm->setData(0, Qt::UserRole, query.value(0).toInt());
            tree->currentItem()->addChild(itm);
        }
        MainWindow mw;
        //mw.RefreshTree(tree);
        mw.FillHash();
        ui->type_cb->clear();
        this->close();
    }
    /*if (table == "date_test")
    {
        int id;
        QSqlQuery query;
        query.prepare("SELECT "
                        "id "
                      "FROM "
                        "objects "
                      "WHERE "
                        "name = :table");
        query.bindValue(":table", ui->table_value_cb_1->currentText());
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
        MainWindow mw;
        mw.RefreshTree(tree);
        ui->table_value_cb_1->clear();
        ui->DateLastTest->clear();
        ui->DateNextTest->clear();
        this->close();
    }*/
}
