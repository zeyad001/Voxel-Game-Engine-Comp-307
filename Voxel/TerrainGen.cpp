#include "TerrainGen.h"
#include "FlatArray.h"
#include <memory>
#include <stdlib.h>
TerrainGen* TerrainGen::gen = new TerrainGen();
TerrainGen::TerrainGen()
{
}

TerrainGen::~TerrainGen()
{
}

void TerrainGen::generate(Chunk& c)
{
}
void TerrainGen::generateFlatSurface(Chunk& c)
{
    // FlatArray<Block*>* array = new FlatArray<Block*>(Chunk::xsize, Chunk::xsize, Chunk::zsize);

    FlatArray<Block*>& array = c.getFlatArray();

    for(int i = 0; i < Chunk::xsize; i++) {

        for(int j = 0; j < Chunk::ysize; j++) {

            for(int k = 0; k < Chunk::zsize; k++) {

                if(k <= 64) {
                    if(k == 0) {

                        array.setElement(i, j, k, BlockManager::getBlockManager()->getBlock("Mantle"));
                    } else {
                        if(k <= Chunk::zsize / 4) {

                            array.setElement(i, j, k, BlockManager::getBlockManager()->getBlock("Stone"));
                        } else {

                            array.setElement(i, j, k, BlockManager::getBlockManager()->getBlock("Dirt"));
                        }
                    }

                } else {
                    // array->setElement(i, j, k, BlockManager::getBlockManager()->getBlock("Air"));

                    if(rand() % 100 < 99) {
                        array.setElement(i, j, k, BlockManager::getBlockManager()->getBlock("Air"));

                    } else {
                        array.setElement(i, j, k, BlockManager::getBlockManager()->getBlock("Dirt"));
                    }
                }
            }
        }
    }
}

TerrainGen* TerrainGen::getTerrainManager()
{

    return gen;
}

void TerrainGen::generateAllAir(Chunk& c)
{

    FlatArray<Block*>& array = c.getFlatArray();

    for(int i = 0; i < Chunk::xsize; i++) {
        for(int j = 0; j < Chunk::ysize; j++) {
            for(int k = 0; k < Chunk::zsize; k++) {
                array.setElement(i, j, k, BlockManager::getBlockManager()->getBlock("Air"));
            }
        }
    }
}
void TerrainGen::generateMantle(Chunk& c)
{

    FlatArray<Block*>& array = c.getFlatArray();

    for(int i = 0; i < Chunk::xsize; i++) {
        for(int j = 0; j < Chunk::ysize; j++) {
            array.setElement(i, j, 0, BlockManager::getBlockManager()->getBlock("Mantle"));
        }
    }
}
