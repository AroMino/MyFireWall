/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNewFilter;
    QAction *actionOpenFilter;
    QAction *actionSave;
    QAction *actionSaveAs;
    QAction *actionAbout;
    QAction *actionSecurity;
    QAction *actionStatus;
    QAction *actionSecurity_2;
    QAction *actionReset;
    QAction *actionClear;
    QAction *actionQuit;
    QWidget *centralwidget;
    QTableView *tableView;
    QComboBox *forward;
    QLabel *label_11;
    QLabel *label;
    QComboBox *input;
    QLabel *label_2;
    QComboBox *output;
    QPushButton *add;
    QPushButton *remove;
    QPushButton *apply;
    QMenuBar *menubar;
    QMenu *menuMenu;
    QMenu *menuHelp;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1025, 648);
        MainWindow->setMinimumSize(QSize(1025, 648));
        MainWindow->setMaximumSize(QSize(1025, 648));
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        actionNewFilter = new QAction(MainWindow);
        actionNewFilter->setObjectName("actionNewFilter");
        actionOpenFilter = new QAction(MainWindow);
        actionOpenFilter->setObjectName("actionOpenFilter");
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName("actionSave");
        actionSaveAs = new QAction(MainWindow);
        actionSaveAs->setObjectName("actionSaveAs");
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName("actionAbout");
        actionSecurity = new QAction(MainWindow);
        actionSecurity->setObjectName("actionSecurity");
        actionStatus = new QAction(MainWindow);
        actionStatus->setObjectName("actionStatus");
        actionSecurity_2 = new QAction(MainWindow);
        actionSecurity_2->setObjectName("actionSecurity_2");
        actionReset = new QAction(MainWindow);
        actionReset->setObjectName("actionReset");
        actionClear = new QAction(MainWindow);
        actionClear->setObjectName("actionClear");
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName("actionQuit");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        tableView = new QTableView(centralwidget);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(30, 150, 961, 371));
        tableView->setMinimumSize(QSize(800, 0));
        tableView->setMaximumSize(QSize(16777215, 16777215));
        tableView->setStyleSheet(QString::fromUtf8("QScrollBar:vertical {\n"
"    background: #FFFFFF; /* Couleur de fond */\n"
"    width: 15px; /* Largeur de la barre de d\303\251filement */\n"
"    margin: 22px 0 22px 0; /* Marge autour de la barre de d\303\251filement */\n"
"}\n"
"\n"
"QScrollBar::handle:vertical {\n"
"    background: #A9A9A9; /* Couleur de la poign\303\251e de la barre de d\303\251filement */\n"
"    min-height: 30px; /* Hauteur minimale de la poign\303\251e */\n"
"}\n"
"\n"
"QScrollBar::add-line:vertical {\n"
"    background: #FFFFFF; /* Couleur de fond du bouton de d\303\251filement vers le bas */\n"
"    height: 20px; /* Hauteur du bouton de d\303\251filement vers le bas */\n"
"    subcontrol-position: bottom;\n"
"    subcontrol-origin: margin;\n"
"}\n"
"\n"
"QScrollBar::sub-line:vertical {\n"
"    background: #FFFFFF; /* Couleur de fond du bouton de d\303\251filement vers le haut */\n"
"    height: 20px; /* Hauteur du bouton de d\303\251filement vers le haut */\n"
"    subcontrol-position: top;\n"
"    subcontrol-origin: margin;\n"
"}\n"
""
                        "\n"
"QScrollBar::up-arrow:vertical, QScrollBar::down-arrow:vertical {\n"
"    background: #FFFFFF; /* Couleur de fond de la fl\303\250che */\n"
"}\n"
"\n"
"QScrollBar::add-page:vertical, QScrollBar::sub-page:vertical {\n"
"    background: none; /* Couleur de fond de la zone de page */\n"
"}"));
        tableView->setFrameShape(QFrame::StyledPanel);
        tableView->setFrameShadow(QFrame::Raised);
        tableView->setMidLineWidth(1);
        tableView->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        tableView->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        tableView->setTabKeyNavigation(true);
        tableView->setDragEnabled(false);
        tableView->setDragDropOverwriteMode(true);
        tableView->setDragDropMode(QAbstractItemView::DragDrop);
        tableView->setDefaultDropAction(Qt::IgnoreAction);
        tableView->setAlternatingRowColors(true);
        tableView->setSelectionMode(QAbstractItemView::ExtendedSelection);
        tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableView->setTextElideMode(Qt::ElideNone);
        tableView->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
        tableView->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
        tableView->setShowGrid(false);
        tableView->setGridStyle(Qt::NoPen);
        tableView->setSortingEnabled(true);
        tableView->setCornerButtonEnabled(false);
        forward = new QComboBox(centralwidget);
        QIcon icon;
        QString iconThemeName = QString::fromUtf8("emblem-default");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon = QIcon::fromTheme(iconThemeName);
        } else {
            icon.addFile(QString::fromUtf8("."), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        }
        forward->addItem(icon, QString());
        QIcon icon1;
        iconThemeName = QString::fromUtf8("window-close");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon1 = QIcon::fromTheme(iconThemeName);
        } else {
            icon1.addFile(QString::fromUtf8("."), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        }
        forward->addItem(icon1, QString());
        forward->setObjectName("forward");
        forward->setGeometry(QRect(480, 60, 101, 41));
        forward->setMinimumSize(QSize(0, 0));
        forward->setMaximumSize(QSize(16777215, 16777215));
        label_11 = new QLabel(centralwidget);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(680, 60, 71, 41));
        label_11->setAlignment(Qt::AlignCenter);
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(140, 60, 61, 41));
        label->setAlignment(Qt::AlignCenter);
        input = new QComboBox(centralwidget);
        input->addItem(icon, QString());
        input->addItem(icon1, QString());
        input->setObjectName("input");
        input->setGeometry(QRect(200, 60, 101, 41));
        input->setMinimumSize(QSize(0, 0));
        input->setMaximumSize(QSize(16777215, 16777215));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(400, 60, 81, 41));
        label_2->setAlignment(Qt::AlignCenter);
        output = new QComboBox(centralwidget);
        output->addItem(icon, QString());
        output->addItem(icon1, QString());
        output->setObjectName("output");
        output->setGeometry(QRect(750, 60, 101, 41));
        output->setMinimumSize(QSize(0, 0));
        output->setMaximumSize(QSize(16777215, 16777215));
        add = new QPushButton(centralwidget);
        add->setObjectName("add");
        add->setGeometry(QRect(480, 550, 71, 41));
        remove = new QPushButton(centralwidget);
        remove->setObjectName("remove");
        remove->setGeometry(QRect(570, 550, 71, 41));
        apply = new QPushButton(centralwidget);
        apply->setObjectName("apply");
        apply->setEnabled(false);
        apply->setGeometry(QRect(830, 550, 111, 41));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1025, 22));
        menuMenu = new QMenu(menubar);
        menuMenu->setObjectName("menuMenu");
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName("menuHelp");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuMenu->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menuMenu->addAction(actionNewFilter);
        menuMenu->addAction(actionOpenFilter);
        menuMenu->addSeparator();
        menuMenu->addAction(actionSave);
        menuMenu->addAction(actionSaveAs);
        menuMenu->addSeparator();
        menuMenu->addAction(actionStatus);
        menuMenu->addAction(actionReset);
        menuMenu->addAction(actionClear);
        menuMenu->addSeparator();
        menuMenu->addAction(actionQuit);
        menuHelp->addAction(actionAbout);
        menuHelp->addAction(actionSecurity);
        menuHelp->addSeparator();
        menuHelp->addAction(actionSecurity_2);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MyFireWall", nullptr));
        actionNewFilter->setText(QCoreApplication::translate("MainWindow", "New Filter", nullptr));
        actionOpenFilter->setText(QCoreApplication::translate("MainWindow", "Open Filter", nullptr));
        actionSave->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        actionSaveAs->setText(QCoreApplication::translate("MainWindow", "Save As", nullptr));
        actionAbout->setText(QCoreApplication::translate("MainWindow", "About MyFireWall", nullptr));
        actionSecurity->setText(QCoreApplication::translate("MainWindow", "Technical Support", nullptr));
        actionStatus->setText(QCoreApplication::translate("MainWindow", "Status", nullptr));
        actionSecurity_2->setText(QCoreApplication::translate("MainWindow", "Security", nullptr));
        actionReset->setText(QCoreApplication::translate("MainWindow", "Reset", nullptr));
        actionClear->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
        actionQuit->setText(QCoreApplication::translate("MainWindow", "Quit", nullptr));
        forward->setItemText(0, QCoreApplication::translate("MainWindow", "ACCEPT", nullptr));
        forward->setItemText(1, QCoreApplication::translate("MainWindow", "DROP", nullptr));

        label_11->setText(QCoreApplication::translate("MainWindow", "OUTPUT :", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "INPUT :", nullptr));
        input->setItemText(0, QCoreApplication::translate("MainWindow", "ACCEPT", nullptr));
        input->setItemText(1, QCoreApplication::translate("MainWindow", "DROP", nullptr));

        label_2->setText(QCoreApplication::translate("MainWindow", "FORWARD :", nullptr));
        output->setItemText(0, QCoreApplication::translate("MainWindow", "ACCEPT", nullptr));
        output->setItemText(1, QCoreApplication::translate("MainWindow", "DROP", nullptr));

        add->setText(QCoreApplication::translate("MainWindow", "Add", nullptr));
        remove->setText(QCoreApplication::translate("MainWindow", "Remove", nullptr));
        apply->setText(QCoreApplication::translate("MainWindow", "Apply", nullptr));
        menuMenu->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("MainWindow", "Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
