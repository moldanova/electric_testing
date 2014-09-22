/********************************************************************************
** Form generated from reading UI file 'select_object_type.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELECT_OBJECT_TYPE_H
#define UI_SELECT_OBJECT_TYPE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_select_object_type
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QListWidget *type_list;
    QHBoxLayout *horizontalLayout;
    QPushButton *back_pb;
    QPushButton *next_pb;

    void setupUi(QWidget *select_object_type)
    {
        if (select_object_type->objectName().isEmpty())
            select_object_type->setObjectName(QStringLiteral("select_object_type"));
        select_object_type->resize(391, 418);
        widget = new QWidget(select_object_type);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 10, 371, 401));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        type_list = new QListWidget(widget);
        type_list->setObjectName(QStringLiteral("type_list"));

        verticalLayout->addWidget(type_list);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        back_pb = new QPushButton(widget);
        back_pb->setObjectName(QStringLiteral("back_pb"));

        horizontalLayout->addWidget(back_pb);

        next_pb = new QPushButton(widget);
        next_pb->setObjectName(QStringLiteral("next_pb"));

        horizontalLayout->addWidget(next_pb);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(select_object_type);

        QMetaObject::connectSlotsByName(select_object_type);
    } // setupUi

    void retranslateUi(QWidget *select_object_type)
    {
        select_object_type->setWindowTitle(QApplication::translate("select_object_type", "Form", 0));
        back_pb->setText(QApplication::translate("select_object_type", "\320\235\320\260\320\267\320\260\320\264", 0));
        next_pb->setText(QApplication::translate("select_object_type", "\320\224\320\260\320\273\320\265\320\265", 0));
    } // retranslateUi

};

namespace Ui {
    class select_object_type: public Ui_select_object_type {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELECT_OBJECT_TYPE_H
