#include "metronome.h"
#include <QString>

Metronome::Metronome(QObject *parent) : QObject(parent)
{
    m_Sound.setSource(QUrl("qrc:/new/sound_1/materials/sounds/metronome.tick.wav"));
    m_AccentSound.setSource(QUrl("qrc:/new/sound2/materials/sounds/metronome.accent.wav"));
    m_AccentSound.setVolume(0.9f);
    m_Sound.setVolume(0.3f);

    m_timer = new QTimer(this);
    m_timer->setTimerType(Qt::PreciseTimer);
    connect(m_timer, &QTimer::timeout, this, &Metronome::onTimer);

    m_SpriteSheet = new SpriteSheet(this);
    m_SpriteSheet->load(QString(":/images/materials/images/spriteSheet.jpg"), 4, 2);

}

void Metronome::setBpm(int bpm)
{
    if (bpm <= 0)
    {
        return;
    }
    currentBpm = bpm;
    m_interval = 60000/bpm;
    m_timer->setInterval(m_interval);
}

void Metronome::play()
{
    m_isRunning = true;
    m_CurrentBeat = 0;
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
    if(m_CurrentBeat == 0)
    {
        playAccentSound();
    } else
    {
        playSound();
    }
    m_SpriteSheet->startAnimation(m_interval);
    m_CurrentBeat = (m_CurrentBeat + 1) % m_TimeSignature;
}

void Metronome::playSound()
{
    m_Sound.play();
}

void Metronome::playAccentSound()
{
    m_AccentSound.play();
}

void Metronome::setTimeSignature(int beats)
{
    m_TimeSignature = beats;
}

