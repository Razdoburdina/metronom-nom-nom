#include "spritesheet.h"


SpriteSheet::SpriteSheet(QObject *parent) : QObject(parent)
{
    m_currentFrame = 0;
    m_totalFrames = 0;
}

bool SpriteSheet::load(QString &filePath, int frameWidth, int ftameHeight)
{
    if(!m_sheet.load(filePath))
{
        return false;
}
}

QImage SpriteSheet::currentFrame()
{

}

void SpriteSheet::startAnimation(int interval)
{

}

void SpriteSheet::stopAnimation()
{

}

void SpriteSheet::updateFrame()
{

}
