#include "mainwindow.h"
#include <QMenu>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QTime>
#include <QTimer>


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    m_metronome = new Metronome (this);
    UI();
}

MainWindow::~MainWindow()
{
    delete m_metronome;
}

void MainWindow::UI()
{
    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *vbox = new QVBoxLayout(centralWidget);
    QHBoxLayout *hbox = new QHBoxLayout(this);

    //слайдер для ударов в минуту
    bpmSlider  = new QSlider(Qt::Horizontal, this);
    bpmSlider->setRange(40, 250);
    bpmSlider->setValue(40);
    vbox->addWidget(bpmSlider);
    bpmLabel = new QLabel ("40", this);
    bpmLabel->setAlignment(Qt::AlignCenter);
    vbox->addWidget(bpmLabel);

    //кнопки
    QHBoxLayout *buttonLayout = new QHBoxLayout();

    playPauseButton = new QPushButton("PLAY", this);

    vbox->addWidget(playPauseButton);

    //подключение сигналов
    connect(bpmSlider, &QSlider::valueChanged, this, &MainWindow::bpmChanged);
    connect(playPauseButton, &QPushButton::clicked, this, &MainWindow::playPauseClicked);

    setCentralWidget(centralWidget);
}

void MainWindow::playPauseClicked()
{
    if(m_metronome->isRunning())
    {
        m_metronome->play();
        playPauseButton->setText("Play");
    }
    else
    {
        m_metronome->pause();
        playPauseButton->setText("Pause");
    }

}

void MainWindow::bpmChanged(int bpm)
{
    bpmEdit->setText(QString::number(bpm));
    bpmLabel->setText(QString::number(bpm));
    m_metronome->setBpm(bpm);
}




















































































































































































































































