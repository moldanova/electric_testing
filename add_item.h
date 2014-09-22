#ifndef ADD_ITEM_H
#define ADD_ITEM_H

#include <QMainWindow>
#include <QTreeWidgetItem>
#include "add_edit_table.h"

namespace Ui {
class add_item;
}

class add_item : public QMainWindow
{
    Q_OBJECT

public:
    explicit add_item(QWidget *parent = 0);
    Ui::add_item *get_st() {
        return ui;
    }
    QMultiMap<QString,QString> name_tables;
    ~add_item();

public slots:
    void recieveData(QTreeWidget *_tree);

private slots:
    void onButtonSend();

private:
    Ui::add_item *ui;
    QTreeWidget *tree;
    bool but_cl;
    add_edit_table *new_ae_form;

signals:
    void sendData(QTreeWidget*, QString);
};

#endif // add_item_H
