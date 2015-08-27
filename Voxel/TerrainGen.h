#ifndef TERRAINGEN_H
#define TERRAINGEN_H
#include "Chunk.h"
#include "BlockManager.h"

class Block;
class TerrainGen
{
public:
    TerrainGen();
    ~TerrainGen();
    void generate(Chunk& c);
    void generateFlatSurface(Chunk&);
    void generateAllAir(Chunk& c);
    void generateMantle(Chunk& c);

    static TerrainGen* getTerrainManager();

private:
    static TerrainGen* gen;
};

#endif // TERRAINGEN_H
