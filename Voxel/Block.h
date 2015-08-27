#ifndef BLOCK_H
#define BLOCK_H
#include "Side.h"
#include "OnTick.h"
#include <string>
#include <iostream>
#include <memory>
class Block
{
public:
    Block(std::string);
    Block(Block* b);
    Block();
    ~Block();

    Side* top = new Side();
    Side* bottom = new Side();
    Side* front = new Side();
    Side* back = new Side();
    Side* left = new Side();
    Side* right = new Side();

    void onTick();

    std::string blockName = "";
    bool solid = false;
    int durability = 1;

    const std::string& getBlockName() const
    {
        return blockName;
    }
    bool isSolid()
    {
        return solid;
    }
    Block* setSolid(bool flag)
    {
        solid = flag;
        return this;
    }

    Block* setDurability(int dur)
    {
        durability = dur;
        return this;
    }

    Block* setBack(Side* back)
    {
        delete this->back;
        this->back = new Side(back);
        return this;
    }
    Block* setBottom(Side* bottom)
    {
        delete this->bottom;
        this->bottom = new Side(bottom);
        return this;
    }
    Block* setFront(Side* front)
    {
        delete this->front;
        this->front = new Side(front);
        return this;
    }
    Block* setLeft(Side* left)
    {
        delete this->left;
        this->left = new Side(left);
        return this;
    }
    Block* setRight(Side* right)
    {
        delete this->right;
        this->right = new Side(right);
        return this;
    }
    Block* setTop(Side* top)
    {
        delete this->top;
        this->top = new Side(top);
        return this;
    }
    Side* getBack() const
    {
        return back;
    }
    Side* getBottom() const
    {
        return bottom;
    }
    Side* getFront() const
    {
        return front;
    }
    Side* getLeft() const
    {
        return left;
    }
    Side* getRight() const
    {
        return right;
    }
    Side* getTop() const
    {
        return top;
    }
};

#endif // BLOCK_H
