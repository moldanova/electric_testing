#ifndef SELECT_OBJECT_TYPE_H
#define SELECT_OBJECT_TYPE_H

#include <QWidget>
#include <QSqlQuery>
#include <add_item.h>
#include <QListWidget>
#include <QListWidgetItem>
#include <QTreeWidget>

namespace Ui {
class select_object_type;
}

class select_object_type : public QWidget
{
    Q_OBJECT

public:
    explicit select_object_type(QWidget *parent = 0);
    void GetTree(QTreeWidget *_tree);
    ~select_object_type();

private slots:
    void on_back_pb_clicked();

    void on_next_pb_clicked();

private:
    Ui::select_object_type *ui;
    void FillList();
    QTreeWidget *tree;
};

#endif // SELECT_OBJECT_TYPE_H
