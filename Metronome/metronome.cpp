#include "metronome.h"
#include <QString>

Metronome::Metronome(QObject *parent) : QObject(parent)
{
    m_Sound.setSource(QUrl("qrc:/new/sound_1/materials/sounds/metronome.tick.wav"));

    m_timer = new QTimer(this);
    m_timer->setTimerType(Qt::PreciseTimer);
    connect(m_timer, &QTimer::timeout, this, &Metronome::onTimer);

    m_SpriteSheet = new SpriteSheet(this);
    m_SpriteSheet->load(QString(":/images/materials/images/spriteSheet.jpg"), 4, 2);

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
    m_SpriteSheet->stopAnimation();
}

bool Metronome::isRunning()
{
    return m_isRunning;
}

void Metronome::setLabel(QLabel *newLabel)
{
    m_SpriteSheet->setLabel(newLabel);
}

void Metronome::onTimer()
{
    playSound();
    m_SpriteSheet->startAnimation(m_interval);

}

void Metronome::playSound()
{
    m_Sound.play();
}

