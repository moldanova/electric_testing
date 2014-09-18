/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionAdd_row;
    QWidget *centralWidget;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *AddButton;
    QPushButton *DeleteButton;
    QTreeWidget *treeWidget;
    QWidget *formLayoutWidget;
    QFormLayout *InformationLayout;
    QLabel *NameLabel;
    QLineEdit *NameLineEdit;
    QLabel *DateTestLabel;
    QDateEdit *DateTestEdit;
    QPushButton *SaveButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(582, 456);
        actionAdd_row = new QAction(MainWindow);
        actionAdd_row->setObjectName(QStringLiteral("actionAdd_row"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(11, 14, 241, 371));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        AddButton = new QPushButton(layoutWidget);
        AddButton->setObjectName(QStringLiteral("AddButton"));

        horizontalLayout->addWidget(AddButton);

        DeleteButton = new QPushButton(layoutWidget);
        DeleteButton->setObjectName(QStringLiteral("DeleteButton"));

        horizontalLayout->addWidget(DeleteButton);


        verticalLayout->addLayout(horizontalLayout);

        treeWidget = new QTreeWidget(layoutWidget);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QStringLiteral("1"));
        treeWidget->setHeaderItem(__qtreewidgetitem);
        treeWidget->setObjectName(QStringLiteral("treeWidget"));
        treeWidget->setHeaderHidden(true);

        verticalLayout->addWidget(treeWidget);

        formLayoutWidget = new QWidget(centralWidget);
        formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(269, 49, 281, 331));
        InformationLayout = new QFormLayout(formLayoutWidget);
        InformationLayout->setSpacing(6);
        InformationLayout->setContentsMargins(11, 11, 11, 11);
        InformationLayout->setObjectName(QStringLiteral("InformationLayout"));
        InformationLayout->setContentsMargins(0, 0, 0, 0);
        NameLabel = new QLabel(formLayoutWidget);
        NameLabel->setObjectName(QStringLiteral("NameLabel"));

        InformationLayout->setWidget(0, QFormLayout::LabelRole, NameLabel);

        NameLineEdit = new QLineEdit(formLayoutWidget);
        NameLineEdit->setObjectName(QStringLiteral("NameLineEdit"));

        InformationLayout->setWidget(0, QFormLayout::FieldRole, NameLineEdit);

        DateTestLabel = new QLabel(formLayoutWidget);
        DateTestLabel->setObjectName(QStringLiteral("DateTestLabel"));

        InformationLayout->setWidget(2, QFormLayout::LabelRole, DateTestLabel);

        DateTestEdit = new QDateEdit(formLayoutWidget);
        DateTestEdit->setObjectName(QStringLiteral("DateTestEdit"));

        InformationLayout->setWidget(2, QFormLayout::FieldRole, DateTestEdit);

        SaveButton = new QPushButton(formLayoutWidget);
        SaveButton->setObjectName(QStringLiteral("SaveButton"));

        InformationLayout->setWidget(3, QFormLayout::LabelRole, SaveButton);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 582, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionAdd_row->setText(QApplication::translate("MainWindow", "Add row", 0));
        AddButton->setText(QApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", 0));
        DeleteButton->setText(QApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", 0));
        NameLabel->setText(QApplication::translate("MainWindow", "\320\235\320\260\320\270\320\274\320\265\320\275\320\276\320\262\320\260\320\275\320\270\320\265:", 0));
        DateTestLabel->setText(QApplication::translate("MainWindow", "\320\224\320\260\321\202\320\260 \320\270\321\201\320\277\320\260\321\202\321\213\320\275\320\270\321\217:", 0));
        SaveButton->setText(QApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
