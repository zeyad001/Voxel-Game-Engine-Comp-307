#ifndef MISCELLANEOUS_H
#define MISCELLANEOUS_H
#include <vector>
#include <iostream>
#include <glm/glm.hpp>
#include "Chunk.h"

class Miscellaneous
{
public:
    Miscellaneous();
    static std::vector<glm::vec3> getVector();
    static std::vector<glm::vec3> getGreedyMesh(Chunk& c);
    static void fillblock(int i, int j, int k, std::vector<glm::vec3>& vertices);

protected:
private:
};

#endif // MISCELLANEOUS_H
