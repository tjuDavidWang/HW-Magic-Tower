#include "Entity.h"

void Entity::bindSprite(Sprite* sprite) {
    m_sprite = sprite;
    this->addChild(m_sprite);
}


bool Entity::setTagPosition(int x, int y)
{
    this->setPosition(x, y);
    return true;
}

Point Entity::getTagPosition()
{
    return getPosition();
}
