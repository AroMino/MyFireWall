#ifndef ADDWINDOW_H
#define ADDWINDOW_H

#include "systemenvironment.h"

#include <QMainWindow>
#include <QStringList>
#include <QProcess>
#include "rule.h"

namespace Ui {
class AddWindow;
}

class AddWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AddWindow(QWidget *parent = nullptr);
    ~AddWindow();
    void getAvailableInterface();

protected:
    void mousePressEvent(QMouseEvent* event) override;
    void keyPressEvent(QKeyEvent* event) override;

private slots:
    void on_addButton_clicked();
    void on_protocole_currentTextChanged(const QString &arg1);
    void on_port_clicked();
    void on_clear_clicked();

    void on_chain_currentTextChanged(const QString &arg1);

private:
    Ui::AddWindow *ui;
    Rule* rule;
    QStringList availableInterface;
    SystemEnvironment* system;

signals:
    void addSignal(const Rule* rule);
    void sigCloseEditor(const QString msg);

};

#endif // ADDWINDOW_H
