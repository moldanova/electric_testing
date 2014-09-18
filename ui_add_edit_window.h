/********************************************************************************
** Form generated from reading UI file 'add_edit_window.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADD_EDIT_WINDOW_H
#define UI_ADD_EDIT_WINDOW_H

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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_add_edit_window
{
public:
    QWidget *centralwidget;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *Ok_Button;
    QPushButton *Cancel_Button;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_4;
    QLabel *Table_Label;
    QHBoxLayout *horizontalLayout;
    QComboBox *cb_tables_items_1;
    QComboBox *cb_tables_items_2;
    QComboBox *cb_tables_items_3;
    QComboBox *cb_tables_items_4;
    QLabel *label;
    QLineEdit *Name_Edit;
    QLabel *Name_Label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *add_edit_window)
    {
        if (add_edit_window->objectName().isEmpty())
            add_edit_window->setObjectName(QStringLiteral("add_edit_window"));
        add_edit_window->resize(486, 414);
        centralwidget = new QWidget(add_edit_window);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(12, 189, 158, 25));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        Ok_Button = new QPushButton(layoutWidget);
        Ok_Button->setObjectName(QStringLiteral("Ok_Button"));
        Ok_Button->setCheckable(false);

        horizontalLayout_3->addWidget(Ok_Button);

        Cancel_Button = new QPushButton(layoutWidget);
        Cancel_Button->setObjectName(QStringLiteral("Cancel_Button"));

        horizontalLayout_3->addWidget(Cancel_Button);

        layoutWidget1 = new QWidget(centralwidget);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(13, 20, 403, 24));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        Table_Label = new QLabel(layoutWidget1);
        Table_Label->setObjectName(QStringLiteral("Table_Label"));

        horizontalLayout_4->addWidget(Table_Label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        cb_tables_items_1 = new QComboBox(layoutWidget1);
        cb_tables_items_1->setObjectName(QStringLiteral("cb_tables_items_1"));
        cb_tables_items_1->setEnabled(true);

        horizontalLayout->addWidget(cb_tables_items_1);

        cb_tables_items_2 = new QComboBox(layoutWidget1);
        cb_tables_items_2->setObjectName(QStringLiteral("cb_tables_items_2"));
        cb_tables_items_2->setEnabled(true);

        horizontalLayout->addWidget(cb_tables_items_2);

        cb_tables_items_3 = new QComboBox(layoutWidget1);
        cb_tables_items_3->setObjectName(QStringLiteral("cb_tables_items_3"));
        cb_tables_items_3->setEnabled(true);

        horizontalLayout->addWidget(cb_tables_items_3);

        cb_tables_items_4 = new QComboBox(layoutWidget1);
        cb_tables_items_4->setObjectName(QStringLiteral("cb_tables_items_4"));
        cb_tables_items_4->setEnabled(true);

        horizontalLayout->addWidget(cb_tables_items_4);


        horizontalLayout_4->addLayout(horizontalLayout);

        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setEnabled(true);
        label->setGeometry(QRect(13, 81, 401, 16));
        Name_Edit = new QLineEdit(centralwidget);
        Name_Edit->setObjectName(QStringLiteral("Name_Edit"));
        Name_Edit->setGeometry(QRect(43, 101, 133, 20));
        Name_Label = new QLabel(centralwidget);
        Name_Label->setObjectName(QStringLiteral("Name_Label"));
        Name_Label->setGeometry(QRect(14, 101, 23, 16));
        add_edit_window->setCentralWidget(centralwidget);
        menubar = new QMenuBar(add_edit_window);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 486, 21));
        add_edit_window->setMenuBar(menubar);
        statusbar = new QStatusBar(add_edit_window);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        add_edit_window->setStatusBar(statusbar);

        retranslateUi(add_edit_window);

        QMetaObject::connectSlotsByName(add_edit_window);
    } // setupUi

    void retranslateUi(QMainWindow *add_edit_window)
    {
        add_edit_window->setWindowTitle(QApplication::translate("add_edit_window", "MainWindow", 0));
        Ok_Button->setText(QApplication::translate("add_edit_window", "\320\236\320\272", 0));
        Cancel_Button->setText(QApplication::translate("add_edit_window", "\320\236\321\202\320\274\320\265\320\275\320\260", 0));
        Table_Label->setText(QApplication::translate("add_edit_window", "\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \321\202\320\260\320\261\320\273\320\270\321\206\321\203:", 0));
        label->setText(QString());
        Name_Label->setText(QApplication::translate("add_edit_window", "\320\230\320\274\321\217:", 0));
    } // retranslateUi

};

namespace Ui {
    class add_edit_window: public Ui_add_edit_window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADD_EDIT_WINDOW_H
