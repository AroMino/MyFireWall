#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "mainwindow.h"

#include <QDebug>
#include "mythread.h"

LoginWindow::LoginWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
    ui->warning->hide();
    ui->progressBar->hide();
    ui->passwordLabel->hide();
    ui->status->hide();
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::keyPressEvent(QKeyEvent *event)
{

    if(event->key() == Qt::Key_Enter || event->key() == Qt::Key_Return){
        ui->start->setFocus();
        emit ui->start->click();
    }
}

void LoginWindow::on_start_clicked()
{

    this->password = ui->password->text();

    SystemEnvironment* system = new SystemEnvironment();
    ui->password->hide();
    ui->passwordLabel->hide();
    ui->start->hide();
    ui->warning->hide();

    if(password.isEmpty()){
        ui->password->show();
        ui->start->show();
        ui->password->setFocus();
    }

    else if(system->testPassword(password)){
        MainWindow* w;

        /// Timer
        QTimer* timer = new QTimer(this);

        int value = 0;
        ui->progressBar->setMaximum(100);
        ui->progressBar->setValue(value);

        ui->status->setText("Starting ...");
        ui->status->show();

        QTimer::singleShot(1000,this,[=]()mutable -> void{
            ui->progressBar->show();
            QTimer::singleShot(1000,this,[=]() mutable -> void {
                timer->setInterval(100);
                timer->start();
                ui->status->setText("Loading ...");
                w = new MainWindow(nullptr,password);

                MyThread* th = new MyThread(w);
                th->start();

                /// quand l'operation est terminée
                connect(th,&MyThread::finished,this,[=, &w](){
                    timer->stop();
                    ui->progressBar->setValue(100);
                    QTimer::singleShot(1000,this,[=,&w]()mutable -> void{
                        ui->status->hide();
                        QTimer::singleShot(1000,this,[=,&w]()mutable -> void{
                            ui->progressBar->hide();
                            this->hide();
                            QTimer::singleShot(500,this,[=, &w]()mutable -> void{
                                w->displayFilter(w->getSystemEnvironment()->getFilter());
                                w->show();
                            });
                        });
                    });
                });

                QObject::connect(timer, &QTimer::timeout, this, [=]()mutable -> void{
                    value += 1;
                    ui->progressBar->setValue(value);
                    if (value >= 100) {
                        timer->stop();
                    }
                });
            });
        });
    }
    else{
        ui->status->show();
        ui->status->setText("Starting ...");

        QTimer::singleShot(2000,this,[=](){
//            ui->passwordLabel->show();
            ui->status->hide();
            ui->password->show();
            ui->start->show();
            ui->warning->show();
        });
//        ui->warning->show();
        connect(ui->password,&QLineEdit::textChanged,ui->warning,[&](){
            ui->warning->hide();
        });
        ui->password->setFocus();
    }
}

