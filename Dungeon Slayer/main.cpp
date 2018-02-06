#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon(":/Resources/Resources/battle_icon.ico"));
    MainWindow w;
    w.show();
    return a.exec();
}
