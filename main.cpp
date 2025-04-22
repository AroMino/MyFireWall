#include "mainwindow.h"
#include "loginwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LoginWindow loginWindow;
    loginWindow.show();
   // MainWindow* w = new MainWindow(nullptr,"arominoavotra");
   // w->show();
    return a.exec();
}
