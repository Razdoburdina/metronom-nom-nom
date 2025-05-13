#pragma once

#include <QMainWindow>
#include <QPushButton>
#include <QSlider>
#include "metronome.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow(); //done

private slots:
    void playClicked(); //done
    void pauseClicked(); //done
    void resetClicked(); //done
    void bpmChanged(int bpm);// слайдер для ударов в минуту done
    void metronomTick();

private:
    void UI(); //интерфейс  done
    QPushButton *playButton;
    QPushButton *pauseButton;
    QPushButton *resetButton;
    QSlider *bpmSlider;
    Metronome *m_metronome;
    bool m_isRunning = false;
};

