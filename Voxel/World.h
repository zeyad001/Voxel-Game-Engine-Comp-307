#ifndef WORLD_H
#define WORLD_H
#include <vector>
#include "Chunk.h"
#include "TerrainGen.h"
struct Pos {
    int x;
    int y;
};

class World
{
public:
    World();
    ~World();
    void render();
    void loadChunks();
    std::vector<Pos> loadedChunks;
    std::vector<Pos> allChunks;
    void setPlayerPostion(int x, int y, int z);
    void unloadChunks(int x, int y);
    void deleteFiles();
    // std::vector<Chunk*> world;
    std::vector<Chunk*> world;
    std::vector<Chunk*> activeChunks;

private:
    void loadConfigs();
    std::vector<Pos> chunkCoordinates(int x, int y);

    int chunkRadius = 3;
};
#endif // WORLD_H
