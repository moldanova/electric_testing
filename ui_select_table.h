/********************************************************************************
** Form generated from reading UI file 'select_table.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELECT_TABLE_H
#define UI_SELECT_TABLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_select_table
{
public:
    QWidget *centralwidget;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *Table_Label;
    QListWidget *table_list;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *Ok_Button;
    QPushButton *Cancel_Button;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *select_table)
    {
        if (select_table->objectName().isEmpty())
            select_table->setObjectName(QStringLiteral("select_table"));
        select_table->resize(486, 414);
        centralwidget = new QWidget(select_table);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(13, 21, 451, 351));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        Table_Label = new QLabel(widget);
        Table_Label->setObjectName(QStringLiteral("Table_Label"));

        verticalLayout->addWidget(Table_Label);

        table_list = new QListWidget(widget);
        table_list->setObjectName(QStringLiteral("table_list"));

        verticalLayout->addWidget(table_list);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        Ok_Button = new QPushButton(widget);
        Ok_Button->setObjectName(QStringLiteral("Ok_Button"));
        Ok_Button->setCheckable(false);

        horizontalLayout_3->addWidget(Ok_Button);

        Cancel_Button = new QPushButton(widget);
        Cancel_Button->setObjectName(QStringLiteral("Cancel_Button"));

        horizontalLayout_3->addWidget(Cancel_Button);


        verticalLayout->addLayout(horizontalLayout_3);

        select_table->setCentralWidget(centralwidget);
        menubar = new QMenuBar(select_table);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 486, 21));
        select_table->setMenuBar(menubar);
        statusbar = new QStatusBar(select_table);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        select_table->setStatusBar(statusbar);

        retranslateUi(select_table);

        QMetaObject::connectSlotsByName(select_table);
    } // setupUi

    void retranslateUi(QMainWindow *select_table)
    {
        select_table->setWindowTitle(QApplication::translate("select_table", "MainWindow", 0));
        Table_Label->setText(QApplication::translate("select_table", "\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \321\202\320\260\320\261\320\273\320\270\321\206\321\203:", 0));
        Ok_Button->setText(QApplication::translate("select_table", "\320\236\320\272", 0));
        Cancel_Button->setText(QApplication::translate("select_table", "\320\236\321\202\320\274\320\265\320\275\320\260", 0));
    } // retranslateUi

};

namespace Ui {
    class select_table: public Ui_select_table {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELECT_TABLE_H
