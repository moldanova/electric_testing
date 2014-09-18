#ifndef SELECT_TABLE_H
#define SELECT_TABLE_H

#include <QMainWindow>
#include <QTreeWidgetItem>
#include "add_edit_table.h"

namespace Ui {
class select_table;
}

class select_table : public QMainWindow
{
    Q_OBJECT

public:
    explicit select_table(QWidget *parent = 0);
    Ui::select_table *get_st() {
        return ui;
    }
    QMultiMap<QString,QString> name_tables;
    ~select_table();

public slots:
    void recieveData(QTreeWidget *_tree);

private slots:
    void onButtonSend();

private:
    Ui::select_table *ui;
    QTreeWidget *tree;
    bool but_cl;
    add_edit_table *new_ae_form;

signals:
    void sendData(QTreeWidget*, QString);
};

#endif // SELECT_TABLE_H
