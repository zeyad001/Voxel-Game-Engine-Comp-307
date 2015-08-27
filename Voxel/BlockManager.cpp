#include "BlockManager.h"
#include <algorithm>
#include <memory>

using namespace std;

BlockManager* BlockManager::manager = new BlockManager();

BlockManager::BlockManager()
{
}

BlockManager::~BlockManager()
{
}

void BlockManager::init()
{

    Block* grass = new Block("Grass");
    Side* dirtLook = new Side("../Resources/Dirt.jpg");
    Side* grassLook = new Side("../Resources/Grass.jpg");
    grass->setFront(dirtLook)
        ->setBack(dirtLook)
        ->setLeft(dirtLook)
        ->setRight(dirtLook)
        ->setBottom(dirtLook)
        ->setTop(grassLook)
        ->setSolid(true)
        ->setDurability(2);
    this->registerBlock("Grass", grass);

    Block* dirt = new Block("Dirt");

    dirt->setFront(dirtLook)
        ->setBack(dirtLook)
        ->setLeft(dirtLook)
        ->setRight(dirtLook)
        ->setBottom(dirtLook)
        ->setTop(dirtLook)
        ->setSolid(true)
        ->setDurability(2);
    this->registerBlock("Dirt", dirt);

    Block* stone = new Block("Stone");
    Side* stoneLook = new Side("../Resources/Stone.jpg");
    dirt->setFront(dirtLook)
        ->setBack(stoneLook)
        ->setLeft(stoneLook)
        ->setRight(stoneLook)
        ->setBottom(stoneLook)
        ->setTop(stoneLook)
        ->setSolid(true)
        ->setDurability(10);
    this->registerBlock("Stone", stone);

    Block* air = new Block("Air");
    air->setSolid(false);
    this->registerBlock("Air", air);

    Block* mantle = new Block("Mantle");
    Side* mantleLook = new Side("../Resources/Mantle.jpg");
    mantle->setFront(mantleLook)
        ->setBack(mantleLook)
        ->setLeft(mantleLook)
        ->setRight(mantleLook)
        ->setBottom(mantleLook)
        ->setTop(mantleLook)
        ->setSolid(true)
        ->setDurability(1000);
    this->registerBlock("Mantle", mantle);

    delete grassLook;
    delete dirtLook;
    delete stoneLook;
    delete mantleLook;
}

Block* BlockManager::getBlock(string name)
{
    // std::cout <<  blockMap.size() <<"1\n";

    Block* b = blockMap.at(name);
    //  std::cout <<"2\n";

    return new Block(b);
}

bool BlockManager::registerBlock(string s, Block* b)
{
    // transform(s.begin(),s.end(),s.begin(),::tolower);
    // if(blockMap.find(s) == blockMap.end())
    //  {
    //      return false;
    // }

    blockMap[s] = b;

    return true;
}

BlockManager* BlockManager::getBlockManager()
{
    if(!manager->flag) {

        manager->flag = true;
        manager->init();
    }

    return manager;
}
