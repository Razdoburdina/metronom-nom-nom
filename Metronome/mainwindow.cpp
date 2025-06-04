#include "mainwindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QTimer>

// поставить по дефолту значения темпа 90 и значения акцента 4. Они должны быть и в UI и в дефолтных переменных классов
// добавить возможность ввода значения темпа с клавиатуры
// поставить у ползунка темпа максимальное значение 200
// сделать кнопку Play/Pause сильно больше по Y
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
    QLabel *label = new QLabel;
    m_metronome->setLabel(label);

    //слайдер для ударов в минуту
    bpmSlider  = new QSlider(Qt::Horizontal, this);
    bpmSlider->setRange(40, 250);
    //bpmSlider->setValue(40);
    vbox->addWidget(bpmSlider);
    bpmLabel = new QLabel ("40", this);
    bpmLabel->setAlignment(Qt::AlignCenter);
    vbox->addWidget(bpmLabel);

    //слайдер для количества долей в такте
    timeSignatureSlider  = new QSlider(Qt::Horizontal, this);
    timeSignatureSlider->setRange(1, 8);
    //bpmSlider->setValue(40);
    vbox->addWidget(timeSignatureSlider);
    timeSignatureLabel = new QLabel ("1", this);
    timeSignatureLabel->setAlignment(Qt::AlignCenter);
    vbox->addWidget(timeSignatureLabel);

    //кнопки
    playPauseButton = new QPushButton("PLAY", this);
    vbox->addWidget(playPauseButton);

    vbox->addWidget(label);
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


















































































































































































































































