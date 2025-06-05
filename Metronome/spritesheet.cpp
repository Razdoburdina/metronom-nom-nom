#include "spritesheet.h"


SpriteSheet::SpriteSheet(QObject *parent) : QObject(parent)
{
    m_currentFrame = 0;
    m_totalFrames = 0;
    m_animationTimer =  new QTimer(this);
    m_animationTimer->setTimerType(Qt::PreciseTimer);
    connect(m_animationTimer, &QTimer::timeout, this, &SpriteSheet::onTimer);
}

bool SpriteSheet::load(const QString &filePath, int columns, int rows)
{
    if(!m_sheet.load(filePath))
{
        return false;            
}

    m_sheet = m_sheet.scaled(1500/2,1000/2, Qt::KeepAspectRatio);

    m_frameWidth = m_sheet.width()/columns;
    m_frameHeight = m_sheet.height()/rows;

    m_totalFrames = columns *  rows; // количество кадров

    return true;
}

QImage SpriteSheet::currentFrame()
{
    int framesPerRow = m_sheet.width() / m_frameWidth;
    int rowNum = m_currentFrame / framesPerRow;
    int colNum = m_currentFrame % framesPerRow;

    return m_sheet.copy(colNum * m_frameWidth, rowNum * m_frameHeight, m_frameWidth, m_frameHeight); //координаты(позиция левого верхнего угла), ширина и высота текущего кадра
}

void SpriteSheet::updateFrame()
{
    m_currentFrame = (m_currentFrame + 1) % m_totalFrames;
}

void SpriteSheet::startAnimation(int interval)
{
    //if(!m_animationTimer->isActive())
    m_currentFrame = 0;
    m_animationTimer->start(interval/m_totalFrames);

}

void SpriteSheet::stopAnimation()
{
    m_animationTimer->stop();
}

void SpriteSheet::setLabel(QLabel *newLabel)
{
    m_animatedLabel = newLabel;
    if (m_animatedLabel)
        m_animatedLabel->setPixmap(QPixmap::fromImage(currentFrame()));
}

void SpriteSheet::onTimer()
{
    updateFrame();
    m_animatedLabel->setPixmap(QPixmap::fromImage(currentFrame()));
}
