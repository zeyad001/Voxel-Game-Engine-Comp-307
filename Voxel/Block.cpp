#include "Block.h"

Block::Block(std::string name)
{
    this->blockName = name;
}

Block::Block(Block* obj)
{

    this->blockName = obj->blockName;
    this->solid = obj->solid;
    this->setFront(obj->getFront());
    this->setBack(obj->getBack());
    this->setLeft(obj->getLeft());
    this->setRight(obj->getRight());
    this->setTop(obj->getTop());
    this->setBottom(obj->getBottom());
}

Block::Block()
{
}
Block::~Block()
{
}

void Block::onTick()
{
}
