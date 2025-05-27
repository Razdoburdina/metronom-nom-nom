#include "spritesheet.h"


SpriteSheet::SpriteSheet(QObject *parent) : QObject(parent)
{
    m_currentFrame = 0;
    m_totalFrames = 0;
}

bool SpriteSheet::load(const QString &filePath, int frameWidth, int frameHeight)
{
    if(!m_sheet.load(filePath))
{
        return false;            
}
    m_frameWidth = frameWidth;
    m_frameHeight = frameHeight;

    m_sheet = m_sheet.scaled(700,262, Qt::KeepAspectRatio);

    m_totalFrames = (m_sheet.width() / frameWidth) * (m_sheet.height() / frameHeight); // количество кадров

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
    // emit frameChanged();
}
