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
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
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
    QAction *PredictionTests;
    QWidget *centralWidget;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *AddButton;
    QPushButton *DeleteButton;
    QTreeWidget *treeWidget;
    QGroupBox *groupBox;
    QPushButton *SaveButton;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QLabel *NameLabel;
    QLineEdit *NameLineEdit;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout_3;
    QLabel *DateLastTestLabel;
    QDateEdit *DateLastTest;
    QLabel *DateNextTestLabel;
    QDateEdit *DateNextTest;
    QMenuBar *menuBar;
    QMenu *menu;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(582, 456);
        actionAdd_row = new QAction(MainWindow);
        actionAdd_row->setObjectName(QStringLiteral("actionAdd_row"));
        PredictionTests = new QAction(MainWindow);
        PredictionTests->setObjectName(QStringLiteral("PredictionTests"));
        PredictionTests->setCheckable(false);
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
        AddButton->setEnabled(true);

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

        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(260, 40, 301, 351));
        SaveButton = new QPushButton(groupBox);
        SaveButton->setObjectName(QStringLiteral("SaveButton"));
        SaveButton->setGeometry(QRect(10, 320, 269, 23));
        layoutWidget1 = new QWidget(groupBox);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 21, 171, 61));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        NameLabel = new QLabel(layoutWidget1);
        NameLabel->setObjectName(QStringLiteral("NameLabel"));

        verticalLayout_2->addWidget(NameLabel);

        NameLineEdit = new QLineEdit(layoutWidget1);
        NameLineEdit->setObjectName(QStringLiteral("NameLineEdit"));

        verticalLayout_2->addWidget(NameLineEdit);

        layoutWidget2 = new QWidget(groupBox);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(10, 99, 171, 181));
        verticalLayout_3 = new QVBoxLayout(layoutWidget2);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        DateLastTestLabel = new QLabel(layoutWidget2);
        DateLastTestLabel->setObjectName(QStringLiteral("DateLastTestLabel"));

        verticalLayout_3->addWidget(DateLastTestLabel);

        DateLastTest = new QDateEdit(layoutWidget2);
        DateLastTest->setObjectName(QStringLiteral("DateLastTest"));

        verticalLayout_3->addWidget(DateLastTest);

        DateNextTestLabel = new QLabel(layoutWidget2);
        DateNextTestLabel->setObjectName(QStringLiteral("DateNextTestLabel"));

        verticalLayout_3->addWidget(DateNextTestLabel);

        DateNextTest = new QDateEdit(layoutWidget2);
        DateNextTest->setObjectName(QStringLiteral("DateNextTest"));

        verticalLayout_3->addWidget(DateNextTest);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 582, 21));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menu->addAction(PredictionTests);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionAdd_row->setText(QApplication::translate("MainWindow", "Add row", 0));
        PredictionTests->setText(QApplication::translate("MainWindow", "\320\237\321\200\320\265\320\264\321\201\320\272\320\260\320\267\320\260\320\275\320\270\320\265 \320\270\321\201\320\277\321\213\321\202\320\260\320\275\320\270\320\271", 0));
        AddButton->setText(QApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", 0));
        DeleteButton->setText(QApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", 0));
        groupBox->setTitle(QString());
        SaveButton->setText(QApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", 0));
        NameLabel->setText(QApplication::translate("MainWindow", "\320\235\320\260\320\270\320\274\320\265\320\275\320\276\320\262\320\260\320\275\320\270\320\265:", 0));
        DateLastTestLabel->setText(QApplication::translate("MainWindow", "\320\224\320\260\321\202\320\260 \320\277\320\276\321\201\320\273\320\265\320\264\320\275\320\265\320\263\320\276 \320\270\321\201\320\277\321\213\321\202\320\260\320\275\320\270\321\217:", 0));
        DateNextTestLabel->setText(QApplication::translate("MainWindow", "\320\224\320\260\321\202\320\260 \321\201\320\273\320\265\320\264\321\203\321\216\321\211\320\265\320\263\320\276 \320\270\321\201\320\277\321\213\321\202\320\260\320\275\320\270\321\217:", 0));
        menu->setTitle(QApplication::translate("MainWindow", "\320\234\320\265\320\275\321\216", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
