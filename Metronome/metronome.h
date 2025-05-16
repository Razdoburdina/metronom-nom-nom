#pragma once

#include<QObject>
#include <QTimer>
#include <QMediaPlayer>
#include <QSoundEffect>


class Metronome : public QObject
{
    Q_OBJECT
public:
    Metronome(QObject *parent = nullptr);
    void setBpm(int bpm); // установка темпа
    void play(); // запуск
    void pause(); // пауза
    bool isRunning(); //состояние
signals:
    void tick(); // сигнал при ударе
private:
    void playSound();
    int m_bpm = 100;
    QTimer *m_timer;
    bool m_isRunning = false;
    QSoundEffect m_Sound;
};


