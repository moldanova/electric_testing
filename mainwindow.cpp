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
    //ui->treeWidget->setHeaderLabels(QStringList() << "one");


//    area_count = GetCount("areas");
//    substation_count = GetCount("substations");
//    object_types_count = GetCount("object_types");
//    objects_count = GetCount("obje"cts);




    new_st_form = new select_table();
    connect(ui->AddButton, SIGNAL(clicked()), new_st_form, SLOT(show()));// подключаем сигнал к слоту
    connect(ui->AddButton, SIGNAL(clicked()), this, SLOT(onButtonSend())); // подключаем клик по кнопке к определенному нами слоту
    connect(this, SIGNAL(sendData(QTreeWidget*)), new_st_form, SLOT(recieveData(QTreeWidget*))); // подключение сигнала к слоту нашей формы
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

void MainWindow::AddRoot(QString name)
{
    QTreeWidgetItem *itm = new QTreeWidgetItem(ui->treeWidget);
    itm->setText(0, name);
}

void MainWindow::AddChild(QTreeWidgetItem *parent, QString name)
{
    QTreeWidgetItem *itm = new QTreeWidgetItem();
    itm->setText(0, name);
    parent->addChild(itm);
}

//int MainWindow::GetCount(QString table)
//{
//    QSqlQuery query;
//    query.prepare("SELECT COUNT(*) FROM :table");
//    query.bindValue(":table", table);
//    query.exec();
//    query.next();
//    return query.value(0).toInt();
//}

void MainWindow::FillHash()
{
    QSqlQuery query;
    query.prepare(
        "SELECT DISTINCT "
           "areas.id, "
           "substations.id, "
           "object_types.id, "
           "objects.id "
        "FROM "
           "areas, "
           "substations, "
           "object_types, "
           "objects "
        "WHERE "
           "areas.id = substations.area_id AND "
           "objects.substation_id = substations.id AND "
           "objects.object_type_id = object_types.id;");
    query.exec();
//    int ***arr_db = new int **[area_count];
//    for (int i=0; i<query.size(); i++)
//    {
//        *arr_db[i] = new int *[substation_count];
//        for (int j=0; j<query.size(); i++)
//            arr_db[i][j] = new int [query.size()];
//    }
    qDebug() << query.lastError().text();
    while (query.next())
    {
        int id_area = query.value(0).toInt();
        int id_substation = query.value(1).toInt();
        int id_object_type = query.value(2).toInt();
        int id_object = query.value(3).toInt();
        area_subst[id_substation] = id_area;
        subst_type[id_object_type] = id_substation;
        type_obj[id_object] = id_object_type;
    }
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
    QStringList q;

    q << "SELECT name FROM areas";
    q << "SELECT "
            "areas.name, "
            "substations.name "
         "FROM "
            "areas, "
            "substations "
         "WHERE "
            "substations.area_id = areas.id;";
    q << "SELECT DISTINCT "
            "substations.name, "
            "object_types.name "
         "FROM "
            "substations, "
            "object_types, "
            "objects "
         "WHERE "
            "objects.substation_id = substations.id AND "
            "objects.object_type_id = object_types.id;";

    QString parent, child, area, substation, object_type, object;
    QTreeWidgetItem *new_itm;
    QList<QTreeWidgetItem*> items;

    for (int i=0; i < q.size(); i++)
    {
        query.exec(q.at(i));
        QSqlRecord rec = query.record();
        int column = rec.count();
        while (query.next())
        {
            //qDebug() << query.lastError().text();
            QStringList tree_column;
            for (int i=0; i < column; i++)
                tree_column << query.value(i).toString();
            //for (int i=0; i < 2; i++)
            //{
                parent = tree_column.at(0);
                if (column > 1)
                    child = tree_column.at(1);
                items = ui->treeWidget->findItems(parent, Qt::MatchExactly | Qt::MatchRecursive, 0);
                if (items.isEmpty())
                {
                    new_itm = new QTreeWidgetItem(ui->treeWidget);
                    new_itm->setText(0, parent);
                    if (child != "" && column > 1)
                        AddChild(new_itm, child);
                    ui->treeWidget->setCurrentItem(new_itm);
                }
                else
                {
                    AddChild(items.first(), child);
                }
            //}
            tree_column.clear();
        }
    }

    q << "SELECT DISTINCT "
            "areas.name, "
            "substations.name, "
            "object_types.name, "
            "objects.name "
         "FROM "
            "areas, "
            "substations, "
            "object_types, "
            "objects "
         "WHERE "
            "areas.id = substations.area_id AND "
            "objects.substation_id = substations.id AND "
            "objects.object_type_id = object_types.id;";
    query.exec(q.at(3));
    QSqlRecord rec = query.record();
    int column = rec.count();
    while (query.next())
    {
        QStringList tree_column;
        for (int i=0; i < column; i++)
            tree_column << query.value(i).toString();
        area = tree_column.at(0);
        substation = tree_column.at(1);
        object_type = tree_column.at(2);
        object = tree_column.at(3);
        items = ui->treeWidget->findItems(object_type, Qt::MatchExactly | Qt::MatchRecursive, 0);
        for (int i=0; i<items.length(); i++)
        {
            QTreeWidgetItem* substation_item = items.at(i)->parent();
            QTreeWidgetItem* area_item = substation_item->parent();
            QString area_text = area_item->text(0);
            QString substation_text = substation_item->text(0);
            if (area_text == area && substation_text == substation)
            {
                AddChild(items.at(i), object);
                break;
            }
        }

        tree_column.clear();
    }

    for (int i=0; i<q.size(); i++)
        ui->treeWidget->resizeColumnToContents(i);
    ui->treeWidget->setSortingEnabled(false);
}

void MainWindow::onButtonSend()
{
    emit sendData(ui->treeWidget); // вызываем сигнал, в котором передаём введённые данные
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

}
