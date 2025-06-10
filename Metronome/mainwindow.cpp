#include "mainwindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QTimer>
#include <QFont>
#include <QIntValidator>
#include <QMenu>
#include <QMenuBar>
#include <QMessageBox>
#include <QToolBar>
#include <QProcess>
#include <QIcon>

const int defaultBpm = 90;

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    m_metronome = new Metronome (this);
    m_metronome->setBpm(defaultBpm);
    setWindowIcon(QIcon(":/new/image_2/materials/images/icons8Metronome.png"));
    setWindowTitle("Metronome");
    resize(400,400);
    UI();
    toolBar();
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
    QHBoxLayout *bpmLayout = new QHBoxLayout();
    bpmSlider  = new QSlider(Qt::Horizontal, this);
    bpmSlider->setFixedSize(300, 30);
    bpmSlider->setRange(40, 200);
    bpmSlider->setValue(defaultBpm);
    bpmLayout->addWidget(bpmSlider);
    //vbox->addWidget(bpmSlider);

    //ручной ввод
    bpmEdit = new QLineEdit ("90", this);
    bpmEdit->setMaximumWidth(50);
    QLabel *bpmLabel = new QLabel ("BPM", this);
    bpmLayout->addWidget(bpmEdit);
    bpmLayout->addWidget(bpmLabel);
    vbox->addLayout(bpmLayout);

    //слайдер для количества долей в такте
    QHBoxLayout *timeSignatureLayout = new QHBoxLayout();
    timeSignatureSlider  = new QSlider(Qt::Horizontal, this);
    timeSignatureSlider->setFixedSize(300, 30);
    timeSignatureSlider->setRange(1, 8);
    timeSignatureSlider->setValue(4);
    timeSignatureLayout->addWidget(timeSignatureSlider);
    timeSignatureLabel = new QLabel ("4", this);
    QLabel *accentLabel = new QLabel ("ACCENT", this);
    timeSignatureLabel->setAlignment(Qt::AlignCenter);
    timeSignatureLayout->addWidget(timeSignatureLabel);
    timeSignatureLayout->addWidget(accentLabel);
    vbox->addLayout(timeSignatureLayout);

    //кнопки
    playPauseButton = new QPushButton("PLAY", this);
    playPauseButton->setFixedHeight(100);
    vbox->addWidget(playPauseButton);
    QFont font = playPauseButton->font();
    font.setPixelSize(25);
    playPauseButton->setFont(font);

    vbox->addWidget(spriteSheetLabel);

    //подключение сигналов
    connect(bpmSlider, &QSlider::valueChanged, bpmEdit, [this](int value)
            {
                bpmEdit->setText(QString::number(value));
            });
    connect(bpmEdit, &QLineEdit::returnPressed, this, &MainWindow::bpmChanged);
    connect(bpmSlider, &QSlider::valueChanged, m_metronome, &Metronome::setBpm);
    connect(playPauseButton, &QPushButton::clicked, this, &MainWindow::playPauseClicked);
    connect(timeSignatureSlider, &QSlider::valueChanged, timeSignatureLabel, static_cast<void (QLabel::*)(int)>(&QLabel::setNum));
    connect(timeSignatureSlider, &QSlider::valueChanged, m_metronome, &Metronome::setTimeSignature);

    setCentralWidget(centralWidget);
}

void MainWindow::toolBar()
{
    QPixmap infoIcon(":/new/image_3/materials/images/icons8info.png");
    QToolBar *toolBar = addToolBar("Main toolbar");
    QAction *info = new QAction(infoIcon, "&Info", this);
    toolBar->addAction(info);
    toolBar->addSeparator();
    connect(info, &QAction::triggered, this, &MainWindow::showInfo);
}

void MainWindow::openGitHubLink()
{
    QProcess::startDetached("cmd", {"/c", "start", "https://github.com/Razdoburdina/metronome"});
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

 void MainWindow::bpmChanged()
 {
    int bpm = bpmEdit->text().toInt();

    if (bpm < 40)
    {
        bpm = 40;
    }
    else if (bpm > 200)
    {
        bpm = 200;
    }

    bpmSlider->setValue(bpm);
    m_metronome->setBpm(bpm);
 }

 void MainWindow::timeSignatureChanged(int timeSignature)
 {
     timeSignatureEdit->setText(QString::number(timeSignature));
     timeSignatureLabel->setText(QString::number(timeSignature));
     m_metronome->setTimeSignature(timeSignature);
 }

 void MainWindow::showInfo()
 {
     QMessageBox msgBox;
     //QPixmap msgBoxIcon(":/images2/materials/images/icons8Metronome.png");
     //msgBox.setIconPixmap(msgBoxIcon);
     msgBox.setWindowIcon(QIcon(":/new/image_2/materials/images/icons8Metronome.png"));
     msgBox.setWindowTitle("About App");
     msgBox.setText("Metronome v1.0.\n"
                    "Developed with Qt/C++.\n"
                    "Developer: Razdoburdina Nadezhda.\n"
                    "Do you want to go to the GitHub repository?");
     msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);

     if (msgBox.exec() == QMessageBox::Ok)
     {
         openGitHubLink();
     }
 }


















































































































































































































































