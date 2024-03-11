#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QString>
#include <QMainWindow>
#include <QTimer>
#include <QKeyEvent>

#include "systemenvironment.h"

namespace Ui {
class LoginWindow;
}

class LoginWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit LoginWindow(QWidget *parent = nullptr);
    ~LoginWindow();

protected:
    void keyPressEvent(QKeyEvent* event) override;

private slots:
    void on_start_clicked();

private:
    Ui::LoginWindow *ui;
    QString password;
};

#endif // LOGINWINDOW_H
