#ifndef ADD_EDIT_TABLE_H
#define ADD_EDIT_TABLE_H

#include <QMainWindow>
#include <QString>
#include <QTreeWidget>

namespace Ui {
class add_edit_table;
}

class add_edit_table : public QMainWindow
{
    Q_OBJECT

public:
    explicit add_edit_table(QWidget *parent = 0);
    QMultiMap<int, QString> name_tables;
    int fa = 0;
    ~add_edit_table();

public slots:
    void recieveData(QTreeWidget* tree, QString name_of_table);

private slots:
    void change_substation();
    void change_object_type();

    void on_ok_pushButton_clicked();

private:
    Ui::add_edit_table *ui;
    QTreeWidget *tree;
    QString name_of_table;
};

#endif // ADD_EDIT_TABLE_H
