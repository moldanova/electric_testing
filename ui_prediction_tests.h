/********************************************************************************
** Form generated from reading UI file 'prediction_tests.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PREDICTION_TESTS_H
#define UI_PREDICTION_TESTS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_prediction_tests
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *InformationLabel;
    QHBoxLayout *horizontalLayout;
    QComboBox *number_cb;
    QComboBox *dmy_cb;
    QTableWidget *tableWidget;
    QPushButton *ok_pb;

    void setupUi(QWidget *prediction_tests)
    {
        if (prediction_tests->objectName().isEmpty())
            prediction_tests->setObjectName(QStringLiteral("prediction_tests"));
        prediction_tests->resize(475, 399);
        widget = new QWidget(prediction_tests);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(20, 20, 421, 341));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        InformationLabel = new QLabel(widget);
        InformationLabel->setObjectName(QStringLiteral("InformationLabel"));

        verticalLayout->addWidget(InformationLabel);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        number_cb = new QComboBox(widget);
        number_cb->setObjectName(QStringLiteral("number_cb"));

        horizontalLayout->addWidget(number_cb);

        dmy_cb = new QComboBox(widget);
        dmy_cb->setObjectName(QStringLiteral("dmy_cb"));

        horizontalLayout->addWidget(dmy_cb);


        verticalLayout->addLayout(horizontalLayout);

        tableWidget = new QTableWidget(widget);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));

        verticalLayout->addWidget(tableWidget);


        verticalLayout_2->addLayout(verticalLayout);

        ok_pb = new QPushButton(widget);
        ok_pb->setObjectName(QStringLiteral("ok_pb"));

        verticalLayout_2->addWidget(ok_pb);


        retranslateUi(prediction_tests);

        QMetaObject::connectSlotsByName(prediction_tests);
    } // setupUi

    void retranslateUi(QWidget *prediction_tests)
    {
        prediction_tests->setWindowTitle(QApplication::translate("prediction_tests", "Form", 0));
        InformationLabel->setText(QApplication::translate("prediction_tests", "\320\230\321\201\320\277\321\213\321\202\320\260\320\275\320\270\320\265 \320\277\321\200\320\276\320\262\320\276\320\264\320\270\321\202\321\214 \321\207\320\265\321\200\320\265\320\267:", 0));
        ok_pb->setText(QApplication::translate("prediction_tests", "Ok", 0));
    } // retranslateUi

};

namespace Ui {
    class prediction_tests: public Ui_prediction_tests {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PREDICTION_TESTS_H
