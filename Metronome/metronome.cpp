#include "metronome.h"
#include <QSoundEffect>

Metronome::Metronome(QObject *parent) : QObject(parent)
{

}

void Metronome::setBpm(int bpm)
{
    m_bpm = bpm;
}

void Metronome::play()
{

}

void Metronome::pause()
{

}

bool Metronome::isRunning()
{
    return m_isRunning;
}
