#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMouseEvent>
#include <QStandardItemModel>
#include <QStringList>
#include <QScrollArea>
#include <QMessageBox>
#include "rule.h"
#include "systemenvironment.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    MainWindow(QWidget *parent = nullptr, QString password = "");
    ~MainWindow();

    void addRuleToModel(const Rule* r);
    void displayFilter(QList<Rule *> rules);
    void setPassword(QString password);
    void setMenuConnections();

    QString getPassword();
    SystemEnvironment* getSystemEnvironment();

protected:
    void mousePressEvent(QMouseEvent* event) override;

private slots:
    void on_remove_clicked();
    void on_add_clicked();
    void on_apply_clicked();

    void on_input_currentTextChanged(const QString &arg1);
    void on_forward_currentTextChanged(const QString &arg1);
    void on_output_currentTextChanged(const QString &arg1);

public slots:
    void receiveRule(const Rule* r);

private:
    Ui::MainWindow *ui;
    QStandardItemModel* model;
    QScrollArea* portScrollArea;
    SystemEnvironment* system;
    QString password;

};
#endif // MAINWINDOW_H

