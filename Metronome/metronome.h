#pragma once

#include <QObject>
#include <QLabel>
#include <QTimer>
#include <QMediaPlayer>
#include <QSoundEffect>
#include <QPaintEvent>
#include <QVector>
#include <QColor>
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
    void SetLabel(QLabel *newLabel);
protected:
    void paintEvent(/*QPaintEvent **/);
private slots:
    void onTimer();
private:
    SpriteSheet m_SpriteSheet;
    void playSound();
    int m_interval = 1000;
    QTimer *m_timer;
    bool m_isRunning = false;
    QSoundEffect m_Sound;
    QLabel *m_animatedLabel = nullptr;
    //QPaintEvent m_event;
};


