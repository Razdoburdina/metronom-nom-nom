#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow window;
    QIcon icon (":/images2/materials/images/icons8Metronome.png");
    window.setWindowIcon(icon);
    window.setWindowTitle("Metronome");
    window.resize(400,400);
    window.show();
    return a.exec();
}
