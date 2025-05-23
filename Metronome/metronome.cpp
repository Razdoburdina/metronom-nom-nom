#include "metronome.h"
#include <QSoundEffect>
#include <QTimer>

Metronome::Metronome(QObject *parent) : QObject(parent)
{
    m_Sound.setSource(QUrl("qrc:/new/sound_1/materials/sounds/metronome.tick.wav"));

    m_timer = new QTimer(this);
    m_timer->setTimerType(Qt::PreciseTimer);
    connect(m_timer, &QTimer::timeout, this, &Metronome::onTimer);
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

void Metronome::paintEvent(QPaintEvent *)
{

}

void Metronome::onTimer()
{
    playSound();


}

void Metronome::playSound()
{
    m_Sound.play();
}
