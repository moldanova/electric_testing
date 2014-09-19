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
#include <QtWidgets/QDateEdit>
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
    QHBoxLayout *horizontalLayout;
    QLabel *name_label;
    QLineEdit *name_lineEdit;
    QHBoxLayout *horizontalLayout_3;
    QLabel *DateLastTestLabel;
    QDateEdit *DateLastTest;
    QHBoxLayout *horizontalLayout_4;
    QLabel *DateNextTestLabel;
    QDateEdit *DateNextTest;
    QHBoxLayout *horizontalLayout_2;
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
        widget->setGeometry(QRect(32, 22, 521, 341));
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

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        name_label = new QLabel(widget);
        name_label->setObjectName(QStringLiteral("name_label"));

        horizontalLayout->addWidget(name_label);

        name_lineEdit = new QLineEdit(widget);
        name_lineEdit->setObjectName(QStringLiteral("name_lineEdit"));

        horizontalLayout->addWidget(name_lineEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        DateLastTestLabel = new QLabel(widget);
        DateLastTestLabel->setObjectName(QStringLiteral("DateLastTestLabel"));

        horizontalLayout_3->addWidget(DateLastTestLabel);

        DateLastTest = new QDateEdit(widget);
        DateLastTest->setObjectName(QStringLiteral("DateLastTest"));

        horizontalLayout_3->addWidget(DateLastTest);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        DateNextTestLabel = new QLabel(widget);
        DateNextTestLabel->setObjectName(QStringLiteral("DateNextTestLabel"));

        horizontalLayout_4->addWidget(DateNextTestLabel);

        DateNextTest = new QDateEdit(widget);
        DateNextTest->setObjectName(QStringLiteral("DateNextTest"));

        horizontalLayout_4->addWidget(DateNextTest);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        ok_pushButton = new QPushButton(widget);
        ok_pushButton->setObjectName(QStringLiteral("ok_pushButton"));

        horizontalLayout_2->addWidget(ok_pushButton);

        cancel_pushButton = new QPushButton(widget);
        cancel_pushButton->setObjectName(QStringLiteral("cancel_pushButton"));

        horizontalLayout_2->addWidget(cancel_pushButton);


        verticalLayout->addLayout(horizontalLayout_2);

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
        name_label->setText(QApplication::translate("add_edit_table", "\320\230\320\274\321\217:", 0));
        DateLastTestLabel->setText(QApplication::translate("add_edit_table", "\320\224\320\260\321\202\320\260 \320\277\320\276\321\201\320\273\320\265\320\264\320\275\320\265\320\263\320\276 \320\270\321\201\320\277\321\213\321\202\320\260\320\275\320\270\321\217:", 0));
        DateNextTestLabel->setText(QApplication::translate("add_edit_table", "\320\224\320\260\321\202\320\260 \321\201\320\273\320\265\320\264\321\203\321\216\321\211\320\265\320\263\320\276 \320\270\321\201\320\277\321\213\321\202\320\260\320\275\320\270\321\217:", 0));
        ok_pushButton->setText(QApplication::translate("add_edit_table", "\320\236\320\272", 0));
        cancel_pushButton->setText(QApplication::translate("add_edit_table", "\320\236\321\202\320\274\320\265\320\275\320\260", 0));
    } // retranslateUi

};

namespace Ui {
    class add_edit_table: public Ui_add_edit_table {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADD_EDIT_TABLE_H
