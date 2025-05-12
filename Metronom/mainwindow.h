#pragma once

#include <QMainWindow>
#include <QPushButton>
#include <QSlider>


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void playClicked();
    void pauseClicked();
    void resetClicked();
    void bpmChanged(int bpm);
    void metronomTick();

private:
    QPushButton *playButton;
    QPushButton *pauseButton;
    QPushButton *resetButton;
    QSlider *bpmSlider;
};

