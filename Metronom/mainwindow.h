#pragma once

#include <QMainWindow>
#include <QPushButton>
#include <QSlider>
#include <QLineEdit>
#include <QLabel>
#include "metronome.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();//done

private slots:
    void playPauseClicked(); //done
    void bpmChanged(int bpm);// слайдер для ударов в минуту done

private:
    void UI(); //интерфейс  done
    QPushButton *playPauseButton;
    QLineEdit *bpmEdit;
    QLabel *bpmLabel;
    QSlider *bpmSlider;
    Metronome *m_metronome;
};

