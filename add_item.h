#ifndef ADD_ITEM_H
#define ADD_ITEM_H

#include <QWidget>
#include <QTreeWidget>
#include <QSqlQuery>

namespace Ui {
class add_item;
}

class add_item : public QWidget
{
    Q_OBJECT

public:
    explicit add_item(QWidget *parent = 0);
    void GetTree(QTreeWidget *_tree, QString _table);
    ~add_item();

private:
    Ui::add_item *ui;
    QTreeWidget *tree;
    QString table;
    void FillCB();
};

#endif // ADD_ITEM_H
