/********************************************************************************
** Form generated from reading UI file 'loginwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWINDOW_H
#define UI_LOGINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginWindow
{
public:
    QWidget *centralwidget;
    QLineEdit *password;
    QPushButton *start;
    QLabel *passwordLabel;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *warning;
    QProgressBar *progressBar;
    QLabel *status;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *LoginWindow)
    {
        if (LoginWindow->objectName().isEmpty())
            LoginWindow->setObjectName("LoginWindow");
        LoginWindow->resize(1025, 648);
        LoginWindow->setMinimumSize(QSize(1025, 648));
        LoginWindow->setMaximumSize(QSize(1025, 648));
        LoginWindow->setToolButtonStyle(Qt::ToolButtonIconOnly);
        LoginWindow->setTabShape(QTabWidget::Rounded);
        centralwidget = new QWidget(LoginWindow);
        centralwidget->setObjectName("centralwidget");
        password = new QLineEdit(centralwidget);
        password->setObjectName("password");
        password->setGeometry(QRect(310, 380, 391, 41));
        password->setStyleSheet(QString::fromUtf8("padding:0 10px;\n"
"outline:none;"));
        password->setEchoMode(QLineEdit::Password);
        password->setCursorMoveStyle(Qt::LogicalMoveStyle);
        password->setClearButtonEnabled(true);
        start = new QPushButton(centralwidget);
        start->setObjectName("start");
        start->setGeometry(QRect(430, 460, 151, 51));
        QFont font;
        font.setFamilies({QString::fromUtf8("Utopia")});
        font.setPointSize(12);
        font.setBold(true);
        font.setItalic(false);
        start->setFont(font);
        passwordLabel = new QLabel(centralwidget);
        passwordLabel->setObjectName("passwordLabel");
        passwordLabel->setGeometry(QRect(100, 380, 211, 41));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Utopia")});
        font1.setPointSize(12);
        font1.setItalic(false);
        passwordLabel->setFont(font1);
        passwordLabel->setTextFormat(Qt::PlainText);
        passwordLabel->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(190, 110, 621, 111));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("URW Gothic [UKWN]")});
        font2.setPointSize(48);
        font2.setBold(true);
        font2.setItalic(true);
        label_2->setFont(font2);
        label_2->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(300, 190, 421, 71));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Utopia")});
        font3.setPointSize(28);
        font3.setBold(true);
        label_3->setFont(font3);
        label_3->setAlignment(Qt::AlignCenter);
        warning = new QLabel(centralwidget);
        warning->setObjectName("warning");
        warning->setGeometry(QRect(310, 423, 131, 17));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("NotoSerifTamilSlanted Condensed ExtraBold")});
        font4.setBold(true);
        warning->setFont(font4);
        warning->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);"));
        warning->setAlignment(Qt::AlignCenter);
        progressBar = new QProgressBar(centralwidget);
        progressBar->setObjectName("progressBar");
        progressBar->setGeometry(QRect(190, 410, 661, 20));
        progressBar->setValue(24);
        status = new QLabel(centralwidget);
        status->setObjectName("status");
        status->setGeometry(QRect(440, 430, 161, 20));
        status->setAlignment(Qt::AlignCenter);
        LoginWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(LoginWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1025, 22));
        LoginWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(LoginWindow);
        statusbar->setObjectName("statusbar");
        LoginWindow->setStatusBar(statusbar);

        retranslateUi(LoginWindow);

        QMetaObject::connectSlotsByName(LoginWindow);
    } // setupUi

    void retranslateUi(QMainWindow *LoginWindow)
    {
        LoginWindow->setWindowTitle(QCoreApplication::translate("LoginWindow", "MyFireWall", nullptr));
        password->setText(QString());
        start->setText(QCoreApplication::translate("LoginWindow", "Start", nullptr));
        passwordLabel->setText(QCoreApplication::translate("LoginWindow", "   Administrator Password  ", nullptr));
        label_2->setText(QCoreApplication::translate("LoginWindow", "My FireWall", nullptr));
        label_3->setText(QCoreApplication::translate("LoginWindow", "Block them all", nullptr));
        warning->setText(QCoreApplication::translate("LoginWindow", "Incorrect password", nullptr));
        status->setText(QCoreApplication::translate("LoginWindow", "Loading ...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginWindow: public Ui_LoginWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWINDOW_H
