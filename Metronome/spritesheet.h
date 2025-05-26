#pragma once

#include <QObject>
#include <QImage>
#include <QTimer>
#include <QPainter>

class SpriteSheet : public QObject
{
    Q_OBJECT
public:
    SpriteSheet(QObject *parent = nullptr);
    bool load (QString &filePath, int frameWidth, int ftameHeight);
    QImage currentFrame();
    //void startAnimation(int interval);
    //void stopAnimation();
private slots:
    void updateFrame();
private:
    QImage m_sheet;
    int m_frameWidth;
    int m_frameHeight;
    int m_currentFrame;
    int m_totalFrames;
};
