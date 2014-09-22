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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_add_item
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *ok_pb;
    QPushButton *cancel_pb;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *name_label;
    QLabel *type_label;
    QWidget *widget1;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *name_edit;
    QComboBox *type_cb;

    void setupUi(QWidget *add_item)
    {
        if (add_item->objectName().isEmpty())
            add_item->setObjectName(QStringLiteral("add_item"));
        add_item->resize(401, 239);
        layoutWidget = new QWidget(add_item);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(50, 140, 301, 61));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        ok_pb = new QPushButton(layoutWidget);
        ok_pb->setObjectName(QStringLiteral("ok_pb"));

        horizontalLayout->addWidget(ok_pb);

        cancel_pb = new QPushButton(layoutWidget);
        cancel_pb->setObjectName(QStringLiteral("cancel_pb"));

        horizontalLayout->addWidget(cancel_pb);

        widget = new QWidget(add_item);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(30, 40, 91, 51));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        name_label = new QLabel(widget);
        name_label->setObjectName(QStringLiteral("name_label"));

        verticalLayout->addWidget(name_label);

        type_label = new QLabel(widget);
        type_label->setObjectName(QStringLiteral("type_label"));

        verticalLayout->addWidget(type_label);

        widget1 = new QWidget(add_item);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(130, 40, 241, 51));
        verticalLayout_2 = new QVBoxLayout(widget1);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        name_edit = new QLineEdit(widget1);
        name_edit->setObjectName(QStringLiteral("name_edit"));

        verticalLayout_2->addWidget(name_edit);

        type_cb = new QComboBox(widget1);
        type_cb->setObjectName(QStringLiteral("type_cb"));

        verticalLayout_2->addWidget(type_cb);


        retranslateUi(add_item);

        QMetaObject::connectSlotsByName(add_item);
    } // setupUi

    void retranslateUi(QWidget *add_item)
    {
        add_item->setWindowTitle(QApplication::translate("add_item", "Form", 0));
        ok_pb->setText(QApplication::translate("add_item", "\320\236\320\272", 0));
        cancel_pb->setText(QApplication::translate("add_item", "\320\236\321\202\320\274\320\265\320\275\320\260", 0));
        name_label->setText(QApplication::translate("add_item", "\320\235\320\260\320\270\320\274\320\265\320\275\320\276\320\262\320\260\320\275\320\270\320\265", 0));
        type_label->setText(QApplication::translate("add_item", "\320\242\320\270\320\277", 0));
    } // retranslateUi

};

namespace Ui {
    class add_item: public Ui_add_item {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADD_ITEM_H
