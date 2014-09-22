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

//    new_st_form = new add_item();
//    new_st_form->setFixedSize(486, 414);
//    connect(ui->AddButton, SIGNAL(clicked()), new_st_form, SLOT(show()));// подключаем сигнал к слоту
//    connect(ui->AddButton, SIGNAL(clicked()), this, SLOT(onButtonSend())); // подключаем клик по кнопке к определенному нами слоту
//    connect(this, SIGNAL(sendData(QTreeWidget*)), new_st_form, SLOT(recieveData(QTreeWidget*))); // подключение сигнала к слоту нашей формы



    ui->NameLabel->setVisible(false);
    ui->NameLineEdit->setVisible(false);
    ui->DateLastTest->setVisible(false);
    ui->DateLastTestLabel->setVisible(false);
    ui->DateNextTest->setVisible(false);
    ui->DateNextTestLabel->setVisible(false);
    ui->SaveButton->setVisible(false);
}

MainWindow::~MainWindow()
{
    delete ui;
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
//    query.prepare(
//        "SELECT DISTINCT "
//           "areas.id, "
//           "substations.id, "
//           "object_types.id, "
//           "objects.id "
//        "FROM "
//           "areas, "
//           "substations, "
//           "object_types, "
//           "objects "
//        "WHERE "
//           "areas.id = substations.area_id AND "
//           "objects.substation_id = substations.id AND "
//           "objects.object_type_id = object_types.id;");
//    query.exec();
//    qDebug() << query.lastError().text();
//    while (query.next())
//    {
//        int id_area = query.value(0).toInt();
//        int id_substation = query.value(1).toInt();
//        int id_object_type = query.value(2).toInt();
//        int id_object = query.value(3).toInt();
//        area_subst[id_substation] = id_area;
//        subst_type[id_object_type] = id_substation;
//        type_obj[id_object] = id_object_type;
//    }
}

void MainWindow::DeleteItem(QString name_of_table, int id)
{
    QSqlQuery query;
    query.prepare("DELETE FROM " + name_of_table + " WHERE id = :id");
    query.bindValue(":id", id);
    query.exec();
    query.next();
}

int MainWindow::Search(QString name_of_table)
{
    QSqlQuery query;
    query.prepare("SELECT id FROM " + name_of_table + " WHERE name = :current_item");
    query.bindValue(":current_item", ui->treeWidget->currentItem()->text(0));
    query.exec();
    query.next();
    if (query.value(0).toString() != "")
        return query.value(0).toInt();
    else
        return NULL;

}

void MainWindow::on_DeleteButton_clicked()
{
    if (ui->treeWidget->currentItem()->text(0) != "")
    {
        int id = Search("areas");
        if (id != NULL)
            DeleteItem("areas", id);
        else
        {
            id = Search("substations");
            if (id != NULL)
                DeleteItem("substations", id);
            else
            {
                id = Search("objects");
                if (id != NULL)
                {
                    DeleteItem("objects", id);
                    ShowTree();
                }
            }
        }
        delete ui->treeWidget->currentItem();
    }
    ui->NameLineEdit->setText(ui->treeWidget->currentItem()->text(0));
}

void MainWindow::Information()
{
    QString name;
    if (ui->treeWidget->currentItem()->text(0) != "")
    {
        int id = Search("areas");
        if (id != NULL)
        {
            name = ShowInf("areas", id);
            ui->NameLineEdit->setText(name);
        }
        else
        {
            id = Search("substations");
            if (id != NULL)
            {
                name = ShowInf("substations", id);
                ui->NameLineEdit->setText(name);
            }
            else
            {
                id = Search("object_types");
                if (id != NULL)
                {
                    ui->NameLabel->setVisible(false);
                    ui->NameLineEdit->setVisible(false);
                    ui->SaveButton->setVisible(false);
                }
                else
                {
                    id = Search("objects");
                    if (id != NULL)
                    {
                        name = ShowInf("objects", id);
                        ui->NameLineEdit->setText(name);
                        QSqlQuery q;
                        q.prepare("SELECT DISTINCT date_test.id FROM date_test, objects WHERE date_test.objects_id = :id");
                        q.bindValue(":id", id);
                        q.exec();
                        q.next();
                        if (q.value(0).toString() != "")
                        {
                            ui->DateLastTest->setVisible(true);
                            ui->DateLastTestLabel->setVisible(true);
                            ui->DateNextTest->setVisible(true);
                            ui->DateNextTestLabel->setVisible(true);
                            ui->DateLastTest->clear();
                            ui->DateNextTest->clear();
                            FillDate(id);
                        }
                        else
                        {
                            qDebug() << "ffffff";
                            ui->DateLastTest->setVisible(false);
                            ui->DateLastTestLabel->setVisible(false);
                            ui->DateNextTest->setVisible(false);
                            ui->DateNextTestLabel->setVisible(false);
                        }
                    }
                }
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

void MainWindow::onButtonSend()
{
    /*area_count = GetCount("areas");
    substation_count = GetCount("substations");
    object_types_count = GetCount("object_types");
    objects_count = GetCount("objects");
    for (int i=0; i<substation_count; i++)*/
    //if (areas[ui->treeWidget->currentItem()->data(0, Qt::UserRole)] == ui->treeWidget->currentItem()->text())
    //emit sendData(ui->treeWidget); // вызываем сигнал, в котором передаём введённые данные
}

void MainWindow::on_treeWidget_clicked(const QModelIndex &index)
{
    ui->NameLabel->setVisible(true);
    ui->NameLineEdit->setVisible(true);
    ui->SaveButton->setVisible(true);
    ui->DateLastTest->setVisible(false);
    ui->DateLastTestLabel->setVisible(false);
    ui->DateNextTest->setVisible(false);
    ui->DateNextTestLabel->setVisible(false);
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
    if (ui->treeWidget->currentItem()->text(0) != "")
    {
        int id = Search("areas");
        if (id != NULL)
            UpdateItem("areas", id);
        else
        {
            id = Search("substations");
            if (id != NULL)
                UpdateItem("substations", id);
            else
            {
                id = Search("objects");
                if (id != NULL)
                    UpdateItem("objects", id);
                UpdateDate(id);
            }
        }
    }
    ui->treeWidget->currentItem()->setText(0, ui->NameLineEdit->text());
}

void MainWindow::UpdateDate(int id)
{
    QSqlQuery query;
    query.prepare("UPDATE "
                    "date_test "
                  "SET "
                    "last_test = :last_test, "
                    "next_test = :next_test "
                  "WHERE "
                    "objects_id = :id");
    query.bindValue(":last_test", ui->DateLastTest->date());
    query.bindValue(":next_test", ui->DateNextTest->date());
    query.bindValue(":id", id);
    query.exec();
    query.next();
    qDebug() << query.lastError().text();
}

void MainWindow::on_PredictionTests_triggered()
{
    prediction_tests *new_pt_form;
    new_pt_form = new prediction_tests();
    new_pt_form->show();
}

void MainWindow::on_AddButton_clicked()
{
    int cur_item_id = ui->treeWidget->currentItem()->data(0, Qt::UserRole).toInt();
    QString cur_item_text = ui->treeWidget->currentItem()->text(0);
    if (areas[cur_item_id] == cur_item_text);
    //new_st_form = new add_item();
    //new_st_form->setFixedSize(486, 414);
}
