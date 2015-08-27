#ifndef BLOCKMANAGER_H
#define BLOCKMANAGER_H
#include "Block.h"
#include <map>
class BlockManager
{
public:
    BlockManager();
    ~BlockManager();

    static BlockManager* getBlockManager();

    Block* getBlock(std::string block);
    bool registerBlock(std::string, Block* b);
    void init();

private:
    std::map<std::string, Block*> blockMap;
    bool flag = false;
    static BlockManager* manager;
};

#endif // BLOCKMANAGER_H
