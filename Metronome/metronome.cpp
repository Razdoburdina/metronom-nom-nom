#include "metronome.h"
#include <QSoundEffect>
#include <QTimer>
#include <QString>
#include <QPainter>

Metronome::Metronome(QObject *parent) : QObject(parent)
{
    m_Sound.setSource(QUrl("qrc:/new/sound_1/materials/sounds/metronome.tick.wav"));

    m_timer = new QTimer(this);
    m_timer->setTimerType(Qt::PreciseTimer);
    connect(m_timer, &QTimer::timeout, this, &Metronome::onTimer);

    m_SpriteSheet.load(QString(":/images/materials/images/spriteSheet.jpg"), 700/8, 262/2);

    //connect(m_timer, &QTimer::timeout, this, &Metronome::paintEvent);

}

void Metronome::setBpm(int bpm)
{
    m_interval = 60000/bpm;
    m_timer->setInterval(m_interval);
}

void Metronome::play()
{
    m_isRunning = true;
    if(!m_timer->isActive())
    {
        m_timer->start(m_interval);
    }

}

void Metronome::pause()
{
    m_isRunning = false;
    m_timer->stop();
}

bool Metronome::isRunning()
{
    return m_isRunning;
}

void Metronome::SetLabel(QLabel *newLabel)
{
    m_animatedLabel = newLabel;
    if (m_animatedLabel)
        m_animatedLabel->setPixmap(QPixmap::fromImage(m_SpriteSheet.currentFrame()));
}

void Metronome::paintEvent(/*QPaintEvent *event*/)
{
    // Q_UNUSED(event);

}

void Metronome::onTimer()
{
    playSound();
    m_SpriteSheet.updateFrame();
    m_animatedLabel->setPixmap(QPixmap::fromImage(m_SpriteSheet.currentFrame()));
}

void Metronome::playSound()
{
    m_Sound.play();
}

