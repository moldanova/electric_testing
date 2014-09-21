#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCore>
#include <QtGui>
#include <QTreeWidgetItem>
#include <connect_to_db.h>
#include <QSqlQuery>
#include <QSql>
#include <QLabel>
#include <QLineEdit>
#include <QDateEdit>
#include <QSqlRecord>
#include <QDateEdit>
#include <QHash>
#include "select_table.h"
#include "prediction_tests.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    Ui::MainWindow *get_mw() {
        return ui;
    }

    ~MainWindow();

    void AddRoot(QString name);
    void AddChild(QTreeWidgetItem *parent, QString name);
    void ShowTree();
    void RefreshTree(QTreeWidget *_tree);
    void DeleteItem(QString, int);
    void Information();
    QString ShowInf(QString, int);
    int Search(QString);
    void UpdateItem(QString, int);
    void FillDate(int);
    void UpdateDate(int);

private slots:
    void on_DeleteButton_clicked();
    void onButtonSend();
    void on_treeWidget_clicked(const QModelIndex &index);
    void on_SaveButton_clicked();

    void on_PredictionTests_triggered();

    void on_AddButton_clicked();

private:
    Ui::MainWindow *ui;
    select_table *new_st_form;
    //int*** arr_db;
    QHash<int, int> area_subst;
    QHash<int, int> subst_type;
    QHash<int, int> type_obj;
    void FillHash();
    //int GetCount(QString table);
//    int area_count;
//    int substation_count;
//    int object_types_count;
//    int objects_count;

signals:
    void sendData(QTreeWidget*);
};

#endif // MAINWINDOW_H
