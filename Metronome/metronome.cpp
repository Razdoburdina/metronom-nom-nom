#include "metronome.h"
#include <QSoundEffect>

Metronome::Metronome(QObject *parent) : QObject(parent)
{
    m_Sound.setSource(QUrl("qrc:/new/sound_1/materials/sounds/metronome.tick.wav"));
}

void Metronome::setBpm(int bpm)
{
    m_bpm = bpm;
}

void Metronome::play()
{
    m_isRunning = true;

    //добавить таймер который будет воспроизводсть функцию playSound()
}

void Metronome::pause()
{
    m_isRunning = false;
}

bool Metronome::isRunning()
{
    return m_isRunning;
}

void Metronome::playSound()
{
    m_Sound.play();
}
