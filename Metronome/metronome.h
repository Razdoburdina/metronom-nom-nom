#pragma once

#include <QObject>
#include <QTimer>
#include <QSoundEffect>
#include "spritesheet.h"


class Metronome : public QObject
{
    Q_OBJECT
public:
    Metronome(QObject *parent = nullptr);
    void setBpm(int bpm); // установка темпа
    void play(); // запуск
    void pause(); // пауза
    bool isRunning(); //состояние
    void setLabel(QLabel *newLabel);
    void setTimeSignature(int beats);
private slots:
    void onTimer();
private:
    SpriteSheet* m_SpriteSheet;
    void playSound();
    void playAccentSound();
    int m_interval;
    QTimer *m_timer;
    int currentBpm;
    bool m_isRunning = false;
    QSoundEffect m_Sound;//тик
    QSoundEffect m_AccentSound;//сильная доля
    int m_CurrentBeat = 4;//текущая доля
    int m_TimeSignature = 4;//размер такта
};


