#include "mainwindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QTimer>
#include <QFont>


// добавить возможность ввода значения темпа с клавиатуры
// добавить текст BPM и акцент над соответствующими  ползунками
// по коду : попробовать объединить файлы Resources в один (перед этим сделать коммит, чтобы потом откатиться если что)

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
    //sptitesheet
    QLabel *spriteSheetLabel = new QLabel;
    m_metronome->setLabel(spriteSheetLabel);
    spriteSheetLabel->setAlignment(Qt::AlignCenter);

    //слайдер для ударов в минуту
    bpmSlider  = new QSlider(Qt::Horizontal, this);
    bpmSlider->setRange(40, 200);
    bpmSlider->setValue(90);
    vbox->addWidget(bpmSlider);
    bpmLabel = new QLabel ("90", this);
    bpmLabel->setAlignment(Qt::AlignCenter);
    vbox->addWidget(bpmLabel);

    //слайдер для количества долей в такте
    timeSignatureSlider  = new QSlider(Qt::Horizontal, this);
    timeSignatureSlider->setRange(1, 8);
    timeSignatureSlider->setValue(4);
    vbox->addWidget(timeSignatureSlider);
    timeSignatureLabel = new QLabel ("4", this);
    timeSignatureLabel->setAlignment(Qt::AlignCenter);
    vbox->addWidget(timeSignatureLabel);

    //кнопки
    playPauseButton = new QPushButton("PLAY", this);
    playPauseButton->setFixedHeight(100);
    vbox->addWidget(playPauseButton);
    QFont font = playPauseButton->font();
    font.setPixelSize(25);
    playPauseButton->setFont(font);

    vbox->addWidget(spriteSheetLabel);
    //подключение сигналов
    connect(bpmSlider, &QSlider::valueChanged, bpmLabel, static_cast<void (QLabel::*)(int)>(&QLabel::setNum));
    connect(bpmSlider, &QSlider::valueChanged, m_metronome, &Metronome::setBpm);
    connect(playPauseButton, &QPushButton::clicked, this, &MainWindow::playPauseClicked);
    connect(timeSignatureSlider, &QSlider::valueChanged, timeSignatureLabel, static_cast<void (QLabel::*)(int)>(&QLabel::setNum));
    connect(timeSignatureSlider, &QSlider::valueChanged, m_metronome, &Metronome::setTimeSignature);

    setCentralWidget(centralWidget);
}

void MainWindow::playPauseClicked()
{
    if(!m_metronome->isRunning())
    {
        m_metronome->play();
        playPauseButton->setText("Pause");
    }
    else
    {
        m_metronome->pause();
        playPauseButton->setText("Play");
    }
}

 void MainWindow::bpmChanged(int bpm)
 {
     bpmEdit->setText(QString::number(bpm));
     bpmLabel->setText(QString::number(bpm));
     m_metronome->setBpm(bpm);
 }

 void MainWindow::timeSignatureChanged(int timeSignature)
 {
     timeSignatureEdit->setText(QString::number(timeSignature));
     timeSignatureLabel->setText(QString::number(timeSignature));
     m_metronome->setTimeSignature(timeSignature);
 }


















































































































































































































































