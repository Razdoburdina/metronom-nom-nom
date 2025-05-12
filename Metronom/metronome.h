#pragma once

#include<QObject>
#include <QTimer>

class Metronome : public QObject
{
    Q_OBJECT
public:
    Metronome(QObject *parent = nullptr);
    void setBpm(int bpm); // установка темпа
    void play(); // запуск
    void pause(); // пауза
    void reset(); // перезапуск
    bool isRunning(); //состояние
signals:
    void tick(); // сигнал при ударе
private:
    int m_bmp = 100;
    QTimer *m_timer;
    bool m_isRunning = false;
};


