#ifndef ADD_ITEM_H
#define ADD_ITEM_H

#include <QWidget>
#include <QTreeWidget>
#include <QSqlQuery>
#include <QListWidgetItem>
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
    void GetTypeObj(QListWidgetItem* _type_itm);
    ~add_item();

private slots:
    void on_cancel_pb_clicked();

    void on_ok_pb_clicked();

private:
    Ui::add_item *ui;
    QTreeWidget *tree;
    QString table;
    QListWidgetItem *type_itm;
    void FillCB();
};

#endif // ADD_ITEM_H
