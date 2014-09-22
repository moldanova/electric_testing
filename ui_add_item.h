/********************************************************************************
** Form generated from reading UI file 'add_item.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADD_ITEM_H
#define UI_ADD_ITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
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

class Ui_add_item
{
public:
    QWidget *centralwidget;
    QWidget *widget;
    QVBoxLayout *verticalLayout_3;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QLabel *name_label;
    QLabel *typer_label;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *name_edit;
    QComboBox *type_edit;
    QHBoxLayout *horizontalLayout;
    QPushButton *ok_button;
    QPushButton *cancel_button;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *add_item)
    {
        if (add_item->objectName().isEmpty())
            add_item->setObjectName(QStringLiteral("add_item"));
        add_item->resize(314, 282);
        centralwidget = new QWidget(add_item);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(30, 40, 241, 161));
        verticalLayout_3 = new QVBoxLayout(widget);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        name_label = new QLabel(widget);
        name_label->setObjectName(QStringLiteral("name_label"));

        verticalLayout->addWidget(name_label);

        typer_label = new QLabel(widget);
        typer_label->setObjectName(QStringLiteral("typer_label"));

        verticalLayout->addWidget(typer_label);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        name_edit = new QLineEdit(widget);
        name_edit->setObjectName(QStringLiteral("name_edit"));

        verticalLayout_2->addWidget(name_edit);

        type_edit = new QComboBox(widget);
        type_edit->setObjectName(QStringLiteral("type_edit"));

        verticalLayout_2->addWidget(type_edit);


        gridLayout->addLayout(verticalLayout_2, 0, 1, 1, 1);


        verticalLayout_3->addLayout(gridLayout);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        ok_button = new QPushButton(widget);
        ok_button->setObjectName(QStringLiteral("ok_button"));
        ok_button->setCheckable(false);

        horizontalLayout->addWidget(ok_button);

        cancel_button = new QPushButton(widget);
        cancel_button->setObjectName(QStringLiteral("cancel_button"));

        horizontalLayout->addWidget(cancel_button);


        verticalLayout_3->addLayout(horizontalLayout);

        add_item->setCentralWidget(centralwidget);
        menubar = new QMenuBar(add_item);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 314, 21));
        add_item->setMenuBar(menubar);
        statusbar = new QStatusBar(add_item);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        add_item->setStatusBar(statusbar);

        retranslateUi(add_item);

        QMetaObject::connectSlotsByName(add_item);
    } // setupUi

    void retranslateUi(QMainWindow *add_item)
    {
        add_item->setWindowTitle(QApplication::translate("add_item", "MainWindow", 0));
        name_label->setText(QApplication::translate("add_item", "\320\235\320\260\320\270\320\274\320\265\320\275\320\276\320\262\320\260\320\275\320\270\320\265", 0));
        typer_label->setText(QApplication::translate("add_item", "\320\242\320\270\320\277", 0));
        ok_button->setText(QApplication::translate("add_item", "\320\236\320\272", 0));
        cancel_button->setText(QApplication::translate("add_item", "\320\236\321\202\320\274\320\265\320\275\320\260", 0));
    } // retranslateUi

};

namespace Ui {
    class add_item: public Ui_add_item {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADD_ITEM_H
