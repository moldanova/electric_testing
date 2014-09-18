/********************************************************************************
** Form generated from reading UI file 'add_edit_table.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADD_EDIT_TABLE_H
#define UI_ADD_EDIT_TABLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_add_edit_table
{
public:
    QWidget *centralwidget;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QComboBox *table_value_cb_1;
    QComboBox *table_value_cb_2;
    QComboBox *table_value_cb_3;
    QLabel *information_label;
    QHBoxLayout *horizontalLayout;
    QLabel *name_label;
    QLineEdit *name_lineEdit;
    QPushButton *ok_pushButton;
    QPushButton *cancel_pushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *add_edit_table)
    {
        if (add_edit_table->objectName().isEmpty())
            add_edit_table->setObjectName(QStringLiteral("add_edit_table"));
        add_edit_table->resize(572, 425);
        centralwidget = new QWidget(add_edit_table);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(52, 33, 471, 351));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        table_value_cb_1 = new QComboBox(widget);
        table_value_cb_1->setObjectName(QStringLiteral("table_value_cb_1"));

        verticalLayout->addWidget(table_value_cb_1);

        table_value_cb_2 = new QComboBox(widget);
        table_value_cb_2->setObjectName(QStringLiteral("table_value_cb_2"));

        verticalLayout->addWidget(table_value_cb_2);

        table_value_cb_3 = new QComboBox(widget);
        table_value_cb_3->setObjectName(QStringLiteral("table_value_cb_3"));

        verticalLayout->addWidget(table_value_cb_3);

        information_label = new QLabel(widget);
        information_label->setObjectName(QStringLiteral("information_label"));

        verticalLayout->addWidget(information_label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        name_label = new QLabel(widget);
        name_label->setObjectName(QStringLiteral("name_label"));

        horizontalLayout->addWidget(name_label);

        name_lineEdit = new QLineEdit(widget);
        name_lineEdit->setObjectName(QStringLiteral("name_lineEdit"));

        horizontalLayout->addWidget(name_lineEdit);


        verticalLayout->addLayout(horizontalLayout);

        ok_pushButton = new QPushButton(widget);
        ok_pushButton->setObjectName(QStringLiteral("ok_pushButton"));

        verticalLayout->addWidget(ok_pushButton);

        cancel_pushButton = new QPushButton(widget);
        cancel_pushButton->setObjectName(QStringLiteral("cancel_pushButton"));

        verticalLayout->addWidget(cancel_pushButton);

        add_edit_table->setCentralWidget(centralwidget);
        menubar = new QMenuBar(add_edit_table);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 572, 21));
        add_edit_table->setMenuBar(menubar);
        statusbar = new QStatusBar(add_edit_table);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        add_edit_table->setStatusBar(statusbar);

        retranslateUi(add_edit_table);

        QMetaObject::connectSlotsByName(add_edit_table);
    } // setupUi

    void retranslateUi(QMainWindow *add_edit_table)
    {
        add_edit_table->setWindowTitle(QApplication::translate("add_edit_table", "MainWindow", 0));
        information_label->setText(QString());
        name_label->setText(QApplication::translate("add_edit_table", "\320\230\320\274\321\217:", 0));
        ok_pushButton->setText(QApplication::translate("add_edit_table", "\320\236\320\272", 0));
        cancel_pushButton->setText(QApplication::translate("add_edit_table", "\320\236\321\202\320\274\320\265\320\275\320\260", 0));
    } // retranslateUi

};

namespace Ui {
    class add_edit_table: public Ui_add_edit_table {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADD_EDIT_TABLE_H
