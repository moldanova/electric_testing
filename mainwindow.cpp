#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "connect_to_db.h"
#include <QDialog>
#include <QtCore>
#include <QtGui>
#include <QWidget>
#include <QMessageBox>
#include <QDebug>
#include <QSqlError>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Испытания");
    ui->treeWidget->setColumnCount(1);

    ui->NameLabel->setVisible(false);
    ui->NameLineEdit->setVisible(false);
    ui->type_label->setVisible(false);
    ui->type_cb->setVisible(false);

    ui->date_test_gb->setVisible(false);
    ui->add_date_test_pb->setVisible(false);
    ui->add_dt_fin_pb->setVisible(false);
    ShowDateTest(false);

    ui->SaveButton->setVisible(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::ShowDateTest(bool on_off)
{
    ui->DateLastTest->setVisible(on_off);
    ui->DateLastTestLabel->setVisible(on_off);
    ui->DateNextTest->setVisible(on_off);
    ui->DateNextTestLabel->setVisible(on_off);
}

void MainWindow::AddRoot(QString name, int id)
{
    QTreeWidgetItem *itm = new QTreeWidgetItem(ui->treeWidget);
    itm->setData(0, Qt::UserRole, id);
    itm->setText(0, name);
}

void MainWindow::AddChild(QTreeWidgetItem *parent, QString name, int id)
{
    QTreeWidgetItem *itm = new QTreeWidgetItem();
    itm->setData(0, Qt::UserRole, id);
    itm->setText(0, name);
    parent->addChild(itm);
}

int MainWindow::GetCount(QString table)
{
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM :table");
    query.bindValue(":table", table);
    query.exec();
    query.next();
    return query.value(0).toInt();
}

void MainWindow::FillHash()
{
    QSqlQuery query;
    query.prepare("SELECT * from areas");
    query.exec();
    while (query.next())
        areas[query.value(0).toInt()] = query.value(1).toString();

    query.prepare("SELECT id, name from substations");
    query.exec();
    while (query.next())
        subst[query.value(0).toInt()] = query.value(1).toString();

    query.prepare("SELECT * from object_types");
    query.exec();
    while (query.next())
        obj_type[query.value(0).toInt()] = query.value(1).toString();

    query.prepare("SELECT id, name from objects");
    query.exec();
    while (query.next())
        obj[query.value(0).toInt()] = query.value(1).toString();
}

void MainWindow::DeleteItem(QString name_of_table, int id)
{
    QSqlQuery query;
    query.prepare("DELETE FROM " + name_of_table + " WHERE id = :id");
    query.bindValue(":id", id);
    query.exec();
    query.next();
}

void MainWindow::on_DeleteButton_clicked()
{
    int id = ui->treeWidget->currentItem()->data(0, Qt::UserRole).toInt();
    QString text = ui->treeWidget->currentItem()->text(0);
    if (areas[id] == text)
    {
        DeleteItem("areas", id);
        delete ui->treeWidget->currentItem();
    }
    else if (subst[id] == text)
    {
        DeleteItem("substations", id);
        delete ui->treeWidget->currentItem();
    }
    else if (obj[id] == text)
    {
        DeleteItem("objects", id);
        delete ui->treeWidget->currentItem();
        if (ui->treeWidget->currentItem()->text(0)
                == obj_type[ui->treeWidget->currentItem()->data(0, Qt::UserRole).toInt()])
            delete ui->treeWidget->currentItem();
    }
    if (ui->treeWidget->currentItem()->text(0) !=
            obj_type[ui->treeWidget->currentItem()->data(0, Qt::UserRole).toInt()])
    {
        ui->NameLineEdit->setText(ui->treeWidget->currentItem()->text(0));
        ui->treeWidget->clicked(ui->treeWidget->currentIndex());
    }
    else
    {
        ui->NameLabel->setVisible(false);
        ui->NameLineEdit->setVisible(false);
        ShowDateTest(false);
        ui->SaveButton->setVisible(false);
    }
    ui->date_test_gb->setVisible(false);
    FillHash();
}

void MainWindow::Information()
{
    QString name;
    int id = ui->treeWidget->currentItem()->data(0, Qt::UserRole).toInt();
    QString text = ui->treeWidget->currentItem()->text(0);
    if (ui->treeWidget->currentItem()->text(0) != "")
    {
        if (areas[id] == text)
        {
            name = ShowInf("areas", id);
            ui->NameLineEdit->setText(name);
        }
        else if (subst[id] == text)
        {
            name = ShowInf("substations", id);
            ui->NameLineEdit->setText(name);
        }
        else if (obj_type[id] == text)
        {
            ui->NameLabel->setVisible(false);
            ui->NameLineEdit->setVisible(false);
            ui->SaveButton->setVisible(false);
        }
        else if (obj[id] == text)
        {
            name = ShowInf("objects", id);
            ui->NameLineEdit->setText(name);
            QSqlQuery q;
            q.prepare("SELECT DISTINCT date_test.id FROM date_test, objects WHERE date_test.objects_id = :id");
            q.bindValue(":id", id);
            q.exec();
            q.next();
            QString date_test = q.value(0).toString();

            ui->type_label->setVisible(true);
            ui->type_cb->setVisible(true);
            q.prepare("SELECT DISTINCT subtypes.id, subtypes.name FROM subtypes, object_types WHERE subtypes.object_type_id = :id");
            q.bindValue(":id", ui->treeWidget->currentItem()->parent()->data(0, Qt::UserRole).toInt());
            q.exec();
            while (q.next())
                ui->type_cb->addItem(q.value(1).toString(), q.value(0).toInt());

            q.prepare("SELECT objects.subtype_id FROM objects WHERE objects.id = :id");
            q.bindValue(":id", ui->treeWidget->currentItem()->data(0, Qt::UserRole).toInt());
            q.exec();
            q.next();
            int subtype_id = q.value(0).toInt();
            q.prepare("SELECT DISTINCT name FROM subtypes WHERE subtypes.id = :id");
            q.bindValue(":id", subtype_id);
            q.exec();
            q.next();

            ui->type_cb->setCurrentText(q.value(0).toString());

            if (date_test != "")
            {
                ShowDateTest(true);
                ui->date_test_gb->setVisible(true);
                ui->DateLastTest->clear();
                ui->DateNextTest->clear();
                ui->add_date_test_pb->setVisible(false);
                FillDate(id);
            }
            else
            {
                ShowDateTest(false);
                ui->date_test_gb->setVisible(false);
                ui->add_date_test_pb->setVisible(true);
                //ui->SaveButton->setEnabled(false);
            }
        }
    }

}

void MainWindow::FillDate(int id)
{
    QSqlQuery query;
    query.prepare("SELECT "
                    "date_test.last_test, "
                    "date_test.next_test "
                  "FROM "
                    "objects, "
                    "date_test "
                  "WHERE "
                    "date_test.objects_id = :id;");
    query.bindValue(":id", id);
    query.exec();
    query.next();
    ui->DateLastTest->setDate(query.value(0).toDate());
    ui->DateNextTest->setDate(query.value(1).toDate());
}

QString MainWindow::ShowInf(QString name_of_table, int id)
{
    QSqlQuery query;
    query.prepare("SELECT name FROM " + name_of_table + " WHERE id = :id");
    query.bindValue(":id", id);
    query.exec();
    query.next();
    return query.value(0).toString();
}

void MainWindow::RefreshTree(QTreeWidget* _tree)
{
    ui->treeWidget = _tree;
    ShowTree();
}

void MainWindow::ShowTree()
{
    ui->DateLastTest->setVisible(false);
    ui->DateLastTestLabel->setVisible(false);
    ui->DateNextTest->setVisible(false);
    ui->DateNextTestLabel->setVisible(false);

    ui->treeWidget->clear();
    FillHash();
    QSqlQuery query;
    QString q;
    QList<QTreeWidgetItem*> items;
    QString area, substation, object_type, object;

    q = "SELECT * FROM areas";
    query.exec(q);
    while (query.next())
        AddRoot(query.value(1).toString(), query.value(0).toInt());

    q = "SELECT areas.name, substations.name, substations.id FROM areas, substations WHERE substations.area_id = areas.id";
    query.exec(q);
    while (query.next())
    {
        items = ui->treeWidget->findItems(query.value(0).toString(), Qt::MatchExactly | Qt::MatchRecursive, 0);
        AddChild(items.first(), query.value(1).toString(), query.value(2).toInt());
    }

    q = "SELECT DISTINCT substations.name, object_types.name, object_types.id FROM substations, object_types, objects "
            "WHERE objects.substation_id = substations.id AND objects.object_type_id = object_types.id;";
    query.exec(q);
    while (query.next())
    {
        items = ui->treeWidget->findItems(query.value(0).toString(), Qt::MatchExactly | Qt::MatchRecursive, 0);
        AddChild(items.first(), query.value(1).toString(), query.value(2).toInt());
    }

    q =
    "SELECT DISTINCT "
        "areas.name, "
        "substations.name, "
        "object_types.name, "
        "objects.name, "
        "objects.id "
    "FROM "
        "areas, "
        "substations, "
        "object_types, "
        "objects "
    "WHERE "
        "areas.id = substations.area_id AND "
        "objects.substation_id = substations.id AND "
        "objects.object_type_id = object_types.id;";
    query.exec(q);
    while (query.next())
    {
        area = query.value(0).toString();
        substation = query.value(1).toString();
        object_type = query.value(2).toString();
        object = query.value(3).toString();
        items = ui->treeWidget->findItems(object_type, Qt::MatchExactly | Qt::MatchRecursive, 0);
        for (int i=0; i<items.length(); i++)
        {
            QTreeWidgetItem* substation_item = items.at(i)->parent();
            QTreeWidgetItem* area_item = substation_item->parent();
            QString area_text = area_item->text(0);
            QString substation_text = substation_item->text(0);
            if (area_text == area && substation_text == substation)
            {
                AddChild(items.at(i), object, query.value(4).toInt());
                break;
            }
        }
    }

    for (int i=0; i<q.size(); i++)
        ui->treeWidget->resizeColumnToContents(i);
    ui->treeWidget->setSortingEnabled(false);
}

void MainWindow::on_treeWidget_clicked(const QModelIndex &index)
{
    ui->DeleteButton->setEnabled(true);
    ui->AddButton->setEnabled(true);
    int cur_item_id = ui->treeWidget->currentItem()->data(0, Qt::UserRole).toInt();
    QString cur_item_text = ui->treeWidget->currentItem()->text(0);
    if (obj_type[cur_item_id] == cur_item_text)
        ui->DeleteButton->setEnabled(false);
    else if (obj[cur_item_id] == cur_item_text)
        ui->AddButton->setEnabled(false);

    ui->NameLabel->setVisible(true);
    ui->NameLineEdit->setVisible(true);
    ui->type_label->setVisible(false);
    ui->type_cb->setVisible(false);
    ui->type_cb->clear();
    ui->SaveButton->setVisible(true);

    ShowDateTest(false);
    ui->date_test_gb->setVisible(false);

    FillHash();
    Information();
}

void MainWindow::UpdateItem(QString name_of_table, int id)
{
    QSqlQuery query;
    query.prepare("UPDATE " + name_of_table + " SET name = :update_item WHERE id = :id");
    query.bindValue(":update_item", ui->NameLineEdit->text());
    query.bindValue(":id", id);
    query.exec();
    query.next();
}

void MainWindow::on_SaveButton_clicked()
{
    int id = ui->treeWidget->currentItem()->data(0, Qt::UserRole).toInt();
    QString text = ui->treeWidget->currentItem()->text(0);
    if (ui->treeWidget->currentItem()->text(0) != "")
    {
        if (areas[id] == text)
            UpdateItem("areas", id);
        else if (subst[id] == text)
            UpdateItem("substations", id);
        else if (obj[id] == text)
        {
            UpdateItem("objects", id);
            UpdateDate(id);
        }
    }
    //ui->treeWidget->currentItem()->setText(0, ui->NameLineEdit->text());
    FillHash();
}

void MainWindow::UpdateDate(int id)
{
    QSqlQuery query;
    query.prepare("UPDATE date_test SET last_test = :last_test, next_test = :next_test WHERE objects_id = :id;");
    query.bindValue(":id", id);
    query.bindValue(":last_test", ui->DateLastTest->date());
    query.bindValue(":next_test", ui->DateNextTest->date());
    query.exec();
    query.next();
    qDebug() << id << ui->DateLastTest->date() << ui->DateNextTest->date();
}

void MainWindow::AddDate(int id)
{
    QSqlQuery query;
    query.prepare("INSERT INTO date_test "
                    "(objects_id, last_test, next_test) "
                  "VALUES "
                    "(:id, :last_test, :next_test);");
    query.bindValue(":id", id);
    query.bindValue(":last_test", ui->DateLastTest->date());
    query.bindValue(":next_test", ui->DateNextTest->date());
    query.exec();
    query.next();
}

void MainWindow::on_PredictionTests_triggered()
{
    prediction_tests *new_pt_form;
    new_pt_form = new prediction_tests();
    new_pt_form->show();
}

void MainWindow::on_AddButton_clicked()
{
    FillHash();
    add_item *add_item_form = new add_item();
    select_object_type *select_obj_type = new select_object_type();
    int cur_item_id = ui->treeWidget->currentItem()->data(0, Qt::UserRole).toInt();
    QString cur_item_text = ui->treeWidget->currentItem()->text(0);
    if (areas[cur_item_id] == cur_item_text)
    {
        add_item_form = new add_item();
        add_item_form->GetTree(ui->treeWidget, "areas");
        add_item_form->show();
    }
    else if (obj_type[cur_item_id] == cur_item_text)
    {
        add_item_form = new add_item();
        add_item_form->GetTree(ui->treeWidget, "object_types");
        add_item_form->show();
    }
    else if (subst[cur_item_id] == cur_item_text)
    {
        select_obj_type = new select_object_type();
        select_obj_type->GetTree(ui->treeWidget);
        select_obj_type->show();
    }
}

void MainWindow::on_add_date_test_pb_clicked()
{
    ui->add_date_test_pb->setVisible(false);
    ui->add_dt_fin_pb->setVisible(true);
    ui->date_test_gb->setVisible(true);
    ShowDateTest(true);
    QDate date = QDate::currentDate();
    ui->DateLastTest->setDate(date);
    ui->DateNextTest->setDate(date.addYears(2));
}

void MainWindow::on_add_dt_fin_pb_clicked()
{
    ui->add_dt_fin_pb->setVisible(false);
    int id = ui->treeWidget->currentItem()->data(0, Qt::UserRole).toInt();
    AddDate(id);
    FillHash();
    //ui->SaveButton->setEnabled(true);
}
