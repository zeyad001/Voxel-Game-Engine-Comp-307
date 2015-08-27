#ifndef CHUNK_H
#define CHUNK_H
#include "Block.h"
#include <GL/glew.h>
#include <glm/vec3.hpp>
#include <glm/glm.hpp>
#include "onTick.h"
#include "FlatArray.h"
#include <vector>

class Chunk
{
public:
    // Chunk(FlatArray<Block*>* area, int x, int y);
    ~Chunk();
    // Chunk();
    Chunk(int x, int y);
    glm::vec3 referencePoint = { 0, 0, -64 };
    FlatArray<Block*> area;
    std::vector<glm::vec3> vertices;

    GLuint vboV;
    GLuint vboF;

    int sizeV;
    int sizeN;
    bool recreateMesh = true;

    void init();
    void render();
    void onTick();
    bool loaded = false;
    Chunk* load(int x, int y);
    void unload(Chunk* c, int x, int y);
    bool exists(int x, int y);
    Block* replacement(int x, int y, int z, Block* b);
    glm::vec3 blockToOpenglCo(int x, int y, int z);
    FlatArray<Block*>& getFlatArray();
    // template<class Archive>
    // void serialize(Archive & ar, const unsigned int version);

public:
    void deleteVBO();

    static const int xsize = 32;
    static const int ysize = 32;
    static const int zsize = 128;
    static const int length = 1;
};

#endif // CHUNK_H
