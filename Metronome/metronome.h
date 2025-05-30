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
private slots:
    void onTimer();
private:
    SpriteSheet* m_SpriteSheet;
    void playSound();
    int m_interval = 1000;
    QTimer *m_timer;
    bool m_isRunning = false;
    QSoundEffect m_Sound;
};


