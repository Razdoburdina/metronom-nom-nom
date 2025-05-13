#include "mainwindow.h"
#include <QMenu>
#include <QMenuBar>
#include <QStatusBar>
#include <QToolBar>
#include <QTextEdit>
#include <QIcon>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QListWidget>
#include <QLineEdit>
#include <QFormLayout>
#include <QLabel>
#include <QKeyEvent>
#include <QMoveEvent>
#include <QCheckBox>
#include <QTime>
#include <QFont>
#include <QStatusBar>
#include <QInputDialog>
#include <QProgressBar>
#include <QTimer>
#include <QPixmap>
#include <QSplitter>
#include <QTableWidget>
#include <QPainter>
#include <QPainterPath>


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    m_metronome = new Metronome (this);
}

MainWindow::~MainWindow()
{
    delete m_metronome;
}

void MainWindow::UI()
{
    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *vbox = new QVBoxLayout(centralWidget);

    //слайдер для ударов в минуту
    bpmSlider  = new QSlider(Qt::Horizontal, this);
    bpmSlider->setRange(40, 250);

    vbox->addWidget(bpmSlider);

    //кнопки
    QHBoxLayout *buttonLayout = new QHBoxLayout();

    playButton = new QPushButton("PLAY", this);
    pauseButton = new QPushButton("PAUSE", this);
    resetButton = new QPushButton("RESET", this);

    buttonLayout->addWidget(playButton);
    buttonLayout->addWidget(pauseButton);
    buttonLayout->addWidget(resetButton);

    //подключение сигналов
    connect(bpmSlider, &QSlider::valueChanged, this, &MainWindow::bpmChanged);
    connect(playButton, &QPushButton::clicked, this, &MainWindow::playClicked);
    connect(pauseButton, &QPushButton::clicked, this, &MainWindow::pauseClicked);
    connect(resetButton, &QPushButton::clicked, this, &MainWindow::resetClicked);

    setCentralWidget(centralWidget);
}

void MainWindow::playClicked()
{
    if(m_isRunning)
    {
        m_metronome->play();
    }
}

void MainWindow::pauseClicked()
{
    if(!m_isRunning)
    {
        m_metronome->pause();
    }
}

void MainWindow::resetClicked()
{
    if(m_isRunning)
    {
        m_metronome->pause();
        m_metronome->play();
    }
}

void MainWindow::bpmChanged(int bpm)
{
    m_metronome->setBpm(bpm);
}




















































































































































































































































