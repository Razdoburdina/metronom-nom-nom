#pragma once

#include <QObject>
#include <QImage>
#include <QTimer>
#include <QPainter>
#include <QLabel>

class SpriteSheet : public QObject
{
    Q_OBJECT
public:
    SpriteSheet(QObject *parent = nullptr);
    bool load (const QString &filePath, int frameWidth, int ftameHeight);
    QImage currentFrame();
    void updateFrame();
    void startAnimation(int interval);
    void stopAnimation();
    void setLabel(QLabel *newLabel);
signals:
    void frameChanged();
private slots:
    void onTimer();
private:
    QImage m_sheet;
    int m_frameWidth;
    int m_frameHeight;
    int m_currentFrame;
    int m_totalFrames;
    QLabel *m_animatedLabel = nullptr;
    QTimer *m_animationTimer;
};
