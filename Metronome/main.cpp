#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QIcon icon (":/images2/materials/images/icons8Metronome.png");
    w.setWindowIcon(icon);
    w.setWindowTitle("Metronome");
    w.show();
    return a.exec();
}
