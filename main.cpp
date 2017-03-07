#include "mainwindow.h"
#include <QApplication>
#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    //w.show();

    QPushButton button ("Hello, world!");
    button.setText("some text");
    button.setToolTip("A hint...");


    QPushButton button1("hi.", &button);
    button.show();

    return a.exec();
}
