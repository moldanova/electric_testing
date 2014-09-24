#ifndef ADD_ITEM_H
#define ADD_ITEM_H

#include <QWidget>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QSqlQuery>
#include <QListWidgetItem>
#include <QDebug>
#include <QSqlError>
#include <mainwindow.h>

namespace Ui {
class add_item;
}

class add_item : public QWidget
{
    Q_OBJECT

public:
    explicit add_item(QWidget *parent = 0);
    void GetTree(QTreeWidget *_tree, QString _table);
    void GetTypeObj(QTreeWidget *_tree, QListWidgetItem* _type_itm);
    ~add_item();

private slots:
    void on_cancel_pb_clicked();

    void on_ok_pb_clicked();

private:
    Ui::add_item *ui;
    QTreeWidget *tree;
    QString table;
    QListWidgetItem *type_itm;
    bool sot = 0;
    void FillCB();
    void AddObject();
};

#endif // ADD_ITEM_H
