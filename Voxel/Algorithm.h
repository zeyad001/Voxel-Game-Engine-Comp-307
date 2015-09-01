#ifndef Algorithm_H
#define Algorithm_H
#include <vector>
#include <iostream>
#include <glm/glm.hpp>
#include "Chunk.h"

class Algorithm
{
public:
    Algorithm();
    static std::vector<glm::vec3> getVector();
    static std::vector<glm::vec3> getGreedyMesh(Chunk& c);
    static void fillblock(int i, int j, int k, std::vector<glm::vec3>& vertices);

protected:
private:
};

#endif // MISCELLANEOUS_H
