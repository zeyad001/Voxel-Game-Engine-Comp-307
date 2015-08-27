#include "Miscellaneous.h"

Miscellaneous::Miscellaneous()
{
    // ctor
}
std::vector<glm::vec3> Miscellaneous::getVector()
{
    std::vector<glm::vec3> vertices;

    for(int i = 0; i < 32; i++) {
        for(int j = 0; j < 32; j++) {
            for(int k = -64; k < 64; k++) {
                // std::cout<<i<<std::endl;
                // Bottom
                vertices.push_back(glm::vec3(i, j, k));
                vertices.push_back(glm::vec3(i + 1, j, k));
                vertices.push_back(glm::vec3(i + 1, j + 1, k));
                vertices.push_back(glm::vec3(i, j + 1, k));
                // Top

                vertices.push_back(glm::vec3(i, j, k + 1));
                vertices.push_back(glm::vec3(i + 1, j, k + 1));
                vertices.push_back(glm::vec3(i + 1, j + 1, k + 1));
                vertices.push_back(glm::vec3(i, j + 1, k + 1));
                // Sides
                vertices.push_back(glm::vec3(i, j, k));
                vertices.push_back(glm::vec3(i, j, k + 1));
                vertices.push_back(glm::vec3(i, j + 1, k + 1));
                vertices.push_back(glm::vec3(i, j + 1, k));

                vertices.push_back(glm::vec3(i + 1, j, k));
                vertices.push_back(glm::vec3(i + 1, j, k + 1));
                vertices.push_back(glm::vec3(i + 1, j + 1, k + 1));
                vertices.push_back(glm::vec3(i + 1, j + 1, k));

                vertices.push_back(glm::vec3(i, j, k));
                vertices.push_back(glm::vec3(i + 1, j, k));
                vertices.push_back(glm::vec3(i + 1, j, k + 1));
                vertices.push_back(glm::vec3(i, j, k + 1));

                vertices.push_back(glm::vec3(i, j + 1, k));
                vertices.push_back(glm::vec3(i + 1, j + 1, k));
                vertices.push_back(glm::vec3(i + 1, j + 1, k + 1));
                vertices.push_back(glm::vec3(i, j + 1, k + 1));
            }
        }
    }
    return vertices;
}

void Miscellaneous::fillblock(int i, int j, int k, std::vector<glm::vec3>& vertices)
{

    vertices.push_back(glm::vec3(i, j, k));
    vertices.push_back(glm::vec3(i, j + 1, k));
    // Bottom

    vertices.push_back(glm::vec3(i, j, k));
    vertices.push_back(glm::vec3(i + 1, j, k));
    vertices.push_back(glm::vec3(i + 1, j, k));
    vertices.push_back(glm::vec3(i + 1, j + 1, k));
    vertices.push_back(glm::vec3(i + 1, j + 1, k));
    vertices.push_back(glm::vec3(i, j + 1, k));
    // Top

    vertices.push_back(glm::vec3(i, j, k + 1));
    vertices.push_back(glm::vec3(i + 1, j, k + 1));
    vertices.push_back(glm::vec3(i + 1, j, k + 1));
    vertices.push_back(glm::vec3(i + 1, j + 1, k + 1));
    vertices.push_back(glm::vec3(i + 1, j + 1, k + 1));
    vertices.push_back(glm::vec3(i, j + 1, k + 1));

    // left
    vertices.push_back(glm::vec3(i, j, k));
    vertices.push_back(glm::vec3(i, j, k + 1));
    vertices.push_back(glm::vec3(i, j, k + 1));
    vertices.push_back(glm::vec3(i, j + 1, k + 1));
    vertices.push_back(glm::vec3(i, j + 1, k + 1));
    vertices.push_back(glm::vec3(i, j + 1, k));

    vertices.push_back(glm::vec3(i + 1, j, k));
    vertices.push_back(glm::vec3(i + 1, j, k + 1));
    vertices.push_back(glm::vec3(i + 1, j, k + 1));
    vertices.push_back(glm::vec3(i + 1, j + 1, k + 1));
    vertices.push_back(glm::vec3(i + 1, j + 1, k + 1));
    vertices.push_back(glm::vec3(i + 1, j + 1, k));

    vertices.push_back(glm::vec3(i, j, k));
    vertices.push_back(glm::vec3(i + 1, j, k));
    vertices.push_back(glm::vec3(i + 1, j, k));
    vertices.push_back(glm::vec3(i + 1, j, k + 1));
    vertices.push_back(glm::vec3(i + 1, j, k + 1));
    vertices.push_back(glm::vec3(i, j, k + 1));

    vertices.push_back(glm::vec3(i, j + 1, k));
    vertices.push_back(glm::vec3(i + 1, j + 1, k));
    vertices.push_back(glm::vec3(i + 1, j + 1, k));
    vertices.push_back(glm::vec3(i + 1, j + 1, k + 1));
    vertices.push_back(glm::vec3(i + 1, j + 1, k + 1));
    vertices.push_back(glm::vec3(i, j + 1, k + 1));
}

std::vector<glm::vec3> Miscellaneous::getGreedyMesh(Chunk& c)
{

    std::vector<glm::vec3> vertices;

    for(int i = 0; i < Chunk::xsize - 1; i++) {
        for(int j = 0; j < Chunk::ysize - 1; j++) {
            for(int k = 0; k < Chunk::zsize - 1; k++) {

                // find only non air blocks
                if(c.area.getElement(i, j, k)->blockName != "Air") {

                    // fill blocks if they next to a air block
                    glm::vec3 openglpoint = c.blockToOpenglCo(i, j, k);

                    if(c.area.getElement(i + 1, j, k)->blockName == "Air" ||
                       c.area.getElement(i + 1, j + 1, k)->blockName == "Air" ||
                       c.area.getElement(i, j + 1, k)->blockName == "Air" ||
                       c.area.getElement(i, j, k + 1)->blockName == "Air" ||
                       c.area.getElement(i + 1, j, k + 1)->blockName == "Air" ||
                       c.area.getElement(i + 1, j + 1, k + 1)->blockName == "Air" ||
                       c.area.getElement(i, j + 1, k + 1)->blockName == "Air") {

                        fillblock(openglpoint[0], openglpoint[1], openglpoint[2], vertices);
                    }
                }
            }
        }
    }

    return vertices;
}
