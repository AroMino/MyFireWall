/********************************************************************************
** Form generated from reading UI file 'addwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDWINDOW_H
#define UI_ADDWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *sourceLabel;
    QLabel *portLabel;
    QPushButton *addButton;
    QComboBox *chain;
    QComboBox *target;
    QComboBox *interface_2;
    QComboBox *protocole;
    QLineEdit *source;
    QLineEdit *destination;
    QLabel *sourceLabel_2;
    QPushButton *port;
    QLineEdit *machine_mac;
    QLabel *machineLabel;
    QFrame *line;
    QFrame *line_2;
    QPushButton *clear;
    QRadioButton *intern;
    QRadioButton *extern_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *AddWindow)
    {
        if (AddWindow->objectName().isEmpty())
            AddWindow->setObjectName("AddWindow");
        AddWindow->setWindowModality(Qt::WindowModal);
        AddWindow->setEnabled(true);
        AddWindow->resize(570, 391);
        AddWindow->setMinimumSize(QSize(466, 269));
        AddWindow->setMaximumSize(QSize(1000, 1000));
        centralwidget = new QWidget(AddWindow);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(50, 50, 51, 31));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(200, 50, 61, 31));
        label_2->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(20, 140, 81, 31));
        label_3->setAlignment(Qt::AlignCenter);
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(360, 50, 71, 31));
        label_4->setAlignment(Qt::AlignCenter);
        sourceLabel = new QLabel(centralwidget);
        sourceLabel->setObjectName("sourceLabel");
        sourceLabel->setGeometry(QRect(80, 230, 61, 31));
        sourceLabel->setAlignment(Qt::AlignCenter);
        portLabel = new QLabel(centralwidget);
        portLabel->setObjectName("portLabel");
        portLabel->setEnabled(false);
        portLabel->setGeometry(QRect(200, 140, 61, 31));
        portLabel->setAlignment(Qt::AlignCenter);
        addButton = new QPushButton(centralwidget);
        addButton->setObjectName("addButton");
        addButton->setGeometry(QRect(430, 320, 91, 41));
        chain = new QComboBox(centralwidget);
        chain->addItem(QString());
        chain->addItem(QString());
        chain->addItem(QString());
        chain->setObjectName("chain");
        chain->setGeometry(QRect(100, 50, 91, 31));
        target = new QComboBox(centralwidget);
        target->addItem(QString());
        target->addItem(QString());
        target->setObjectName("target");
        target->setGeometry(QRect(260, 50, 91, 31));
        interface_2 = new QComboBox(centralwidget);
        interface_2->setObjectName("interface_2");
        interface_2->setGeometry(QRect(430, 50, 91, 31));
        protocole = new QComboBox(centralwidget);
        protocole->addItem(QString());
        protocole->addItem(QString());
        protocole->addItem(QString());
        protocole->addItem(QString());
        protocole->addItem(QString());
        protocole->addItem(QString());
        protocole->setObjectName("protocole");
        protocole->setGeometry(QRect(100, 140, 91, 31));
        source = new QLineEdit(centralwidget);
        source->setObjectName("source");
        source->setGeometry(QRect(140, 230, 111, 31));
        source->setClearButtonEnabled(true);
        destination = new QLineEdit(centralwidget);
        destination->setObjectName("destination");
        destination->setGeometry(QRect(350, 230, 111, 31));
        destination->setClearButtonEnabled(true);
        sourceLabel_2 = new QLabel(centralwidget);
        sourceLabel_2->setObjectName("sourceLabel_2");
        sourceLabel_2->setGeometry(QRect(260, 230, 91, 31));
        sourceLabel_2->setAlignment(Qt::AlignCenter);
        port = new QPushButton(centralwidget);
        port->setObjectName("port");
        port->setEnabled(false);
        port->setGeometry(QRect(260, 140, 81, 31));
        machine_mac = new QLineEdit(centralwidget);
        machine_mac->setObjectName("machine_mac");
        machine_mac->setGeometry(QRect(140, 280, 111, 31));
        machine_mac->setClearButtonEnabled(true);
        machineLabel = new QLabel(centralwidget);
        machineLabel->setObjectName("machineLabel");
        machineLabel->setGeometry(QRect(40, 280, 101, 31));
        machineLabel->setAlignment(Qt::AlignCenter);
        line = new QFrame(centralwidget);
        line->setObjectName("line");
        line->setGeometry(QRect(40, 100, 491, 20));
        line->setFrameShape(QFrame::Shape::HLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);
        line_2 = new QFrame(centralwidget);
        line_2->setObjectName("line_2");
        line_2->setGeometry(QRect(40, 190, 491, 20));
        line_2->setFrameShape(QFrame::Shape::HLine);
        line_2->setFrameShadow(QFrame::Shadow::Sunken);
        clear = new QPushButton(centralwidget);
        clear->setObjectName("clear");
        clear->setEnabled(false);
        clear->setGeometry(QRect(350, 140, 31, 31));
        QIcon icon;
        QString iconThemeName = QString::fromUtf8("edit-delete");
        if (QIcon::hasThemeIcon(iconThemeName)) {
            icon = QIcon::fromTheme(iconThemeName);
        } else {
            icon.addFile(QString::fromUtf8("."), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        }
        clear->setIcon(icon);
        intern = new QRadioButton(centralwidget);
        intern->setObjectName("intern");
        intern->setEnabled(false);
        intern->setGeometry(QRect(410, 132, 51, 16));
        intern->setChecked(true);
        extern_2 = new QRadioButton(centralwidget);
        extern_2->setObjectName("extern_2");
        extern_2->setEnabled(false);
        extern_2->setGeometry(QRect(410, 162, 51, 16));
        AddWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(AddWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 570, 22));
        AddWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(AddWindow);
        statusbar->setObjectName("statusbar");
        AddWindow->setStatusBar(statusbar);

        retranslateUi(AddWindow);

        QMetaObject::connectSlotsByName(AddWindow);
    } // setupUi

    void retranslateUi(QMainWindow *AddWindow)
    {
        AddWindow->setWindowTitle(QCoreApplication::translate("AddWindow", "Add Window", nullptr));
        label->setText(QCoreApplication::translate("AddWindow", "Chain  :", nullptr));
        label_2->setText(QCoreApplication::translate("AddWindow", "Target  :  ", nullptr));
        label_3->setText(QCoreApplication::translate("AddWindow", "Protocole  :", nullptr));
        label_4->setText(QCoreApplication::translate("AddWindow", "Interface  : ", nullptr));
        sourceLabel->setText(QCoreApplication::translate("AddWindow", "Source  :", nullptr));
        portLabel->setText(QCoreApplication::translate("AddWindow", "Ports  :", nullptr));
        addButton->setText(QCoreApplication::translate("AddWindow", "Add", nullptr));
        chain->setItemText(0, QCoreApplication::translate("AddWindow", "INPUT", nullptr));
        chain->setItemText(1, QCoreApplication::translate("AddWindow", "FORWARD", nullptr));
        chain->setItemText(2, QCoreApplication::translate("AddWindow", "OUTPUT", nullptr));

        target->setItemText(0, QCoreApplication::translate("AddWindow", "ACCEPT", nullptr));
        target->setItemText(1, QCoreApplication::translate("AddWindow", "DROP", nullptr));

#if QT_CONFIG(tooltip)
        interface_2->setToolTip(QCoreApplication::translate("AddWindow", "<html><head/><body><p align=\"center\"><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        protocole->setItemText(0, QString());
        protocole->setItemText(1, QCoreApplication::translate("AddWindow", "UDP", nullptr));
        protocole->setItemText(2, QCoreApplication::translate("AddWindow", "TCP", nullptr));
        protocole->setItemText(3, QCoreApplication::translate("AddWindow", "DDP", nullptr));
        protocole->setItemText(4, QCoreApplication::translate("AddWindow", "ICMP", nullptr));
        protocole->setItemText(5, QCoreApplication::translate("AddWindow", "SCTP", nullptr));

        destination->setText(QString());
        sourceLabel_2->setText(QCoreApplication::translate("AddWindow", "Destination  :", nullptr));
        port->setText(QString());
        machineLabel->setText(QCoreApplication::translate("AddWindow", "Machine MAC  : ", nullptr));
        clear->setText(QString());
        intern->setText(QCoreApplication::translate("AddWindow", "Int", nullptr));
        extern_2->setText(QCoreApplication::translate("AddWindow", "Ext", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddWindow: public Ui_AddWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDWINDOW_H
