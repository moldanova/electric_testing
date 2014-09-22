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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_select_object_type
{
public:
    QListWidget *listWidget;

    void setupUi(QWidget *select_object_type)
    {
        if (select_object_type->objectName().isEmpty())
            select_object_type->setObjectName(QStringLiteral("select_object_type"));
        select_object_type->resize(400, 382);
        listWidget = new QListWidget(select_object_type);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(10, 10, 371, 361));

        retranslateUi(select_object_type);

        QMetaObject::connectSlotsByName(select_object_type);
    } // setupUi

    void retranslateUi(QWidget *select_object_type)
    {
        select_object_type->setWindowTitle(QApplication::translate("select_object_type", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class select_object_type: public Ui_select_object_type {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELECT_OBJECT_TYPE_H
