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
    ~MainWindow();

private slots:
    void playPauseClicked();
    void bpmChanged();// слайдер для ударов в минуту done
    void timeSignatureChanged(int timeSignature);
    void showInfo();

private:
    void UI(); //интерфейс
    void toolBar();
    void openGitHubLink();
    QPushButton *playPauseButton;
    QLineEdit *bpmEdit;
    QLineEdit *timeSignatureEdit;
    QLabel *bpmLabel;
    QLabel *timeSignatureLabel;
    QSlider *bpmSlider;
    QSlider *timeSignatureSlider;
    Metronome *m_metronome;
};

