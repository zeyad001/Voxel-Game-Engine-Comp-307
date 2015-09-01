#define GLEW_STATIC
#include "Chunk.h"
#include <GL/glew.h>
#include <GL/glut.h>
#include <iostream>
#include <fstream>
#include <ios>
#include <sstream>
#include <string>
#include <cstdio>

#include "Algorithm.h"
//#include <stdio.h>

//#include <boost/serialization/serialization.hpp>
//#include <boost/archive/text_iarchive.hpp>
//#include <boost/archive/text_oarchive.hpp>

using namespace std;
/*
Chunk::Chunk(FlatArray<Block*>* arr, int x, int y)
{

    this->area = arr;
    referencePoint.x = x;
    referencePoint.y = y;
    referencePoint.z = -64;
    init();
}
*/
/*
Chunk::Chunk() : area(Chunk::xsize,Chunk::ysize,Chunk::zsize)
{
    // init();
}
*/
Chunk::Chunk(int x, int y)

{
    area = new FlatArray<Block*>(xsize, ysize, zsize);
    referencePoint.x = x;
    referencePoint.y = y;
    referencePoint.z = -64;
}

Chunk::~Chunk()
{
}

void Chunk::onTick()
{

    for(Block* b : *area) {
        b->onTick();
    }
}

Chunk* Chunk::load(int x, int y)
{
    std::cout << "Loading" << std::endl;
    string xT;
    string yT;
    ostringstream convert;
    convert << x;
    xT = convert.str();
    convert << y;
    yT = convert.str();
    std::string s = "Chunks_stored_" + xT + "_" + yT + ".vx";
    const char* filename = s.c_str();

    Chunk* c;
    /*
        std::ifstream ifs("Chunks_stored.vx", std::ios::binary);
        boost::archive::text_iarchive ia(ifs);
        ///ia >> c;
        ifs.close();
        //c->dump();
        loaded = true;
        return c;

    */
    cout << filename << endl;
    FILE* f = fopen(filename, "rb");
    fread((char*)&c, sizeof(c), 1, f);
    fclose(f);
    return c;
}

void Chunk::unload(Chunk* c, int x, int y)
{
    string xT;
    string yT;
    ostringstream convert;
    convert << x;
    xT = convert.str();
    convert << y;
    yT = convert.str();
    std::string s = "Chunks_stored_" + xT + "_" + yT + ".vx";
    const char* filename = s.c_str();

    /*
    std::ofstream ofs(filename,std::ios::app);
    boost::archive::text_oarchive oa(ofs);
    //oa << c;
    ofs.close();

    loaded = false;

    */
    FILE* f = fopen(filename, "wb");
    fwrite((char*)&c, sizeof(c), 1, f);
    fclose(f);
}

bool Chunk::exists(int x, int y)
{
    string xT;
    string yT;
    ostringstream convert;
    convert << x;
    xT = convert.str();
    convert << y;
    yT = convert.str();
    std::string s = "Chunks_stored_" + xT + "_" + yT + ".vx";
    const char* filename = s.c_str();

    bool found = false;

    ifstream file(filename);

    if(file.good()) {
        found = true;
        std::cout << found << std::endl;
    }
    file.close();
    return found;
}

Block* Chunk::replacement(int x, int y, int z, Block* b)
{

    recreateMesh = true;

    return area->replaceElement(x, y, z, b);
}
void Chunk::removeBlock(int x, int y, int z)
{
    Block* b = replacement(x, y, z, BlockManager::getBlockManager()->getBlock("Air"));
    delete b;
}
Block* Chunk::getAboveBlock(int x, int y, int z)
{

    if(z + 1 < Chunk::zsize) {
        return area->getElement(x, y, z + 1);
    } else {
        std::cout << "Array out of bounds\n";
        return nullptr;
    }
}
Block* Chunk::getBelowBlock(int x, int y, int z)
{

    if(z - 1 >= 0) {
        return area->getElement(x, y, z - 1);
    } else {
        std::cout << "Array out of bounds\n";
        return nullptr;
    }
}
Block* Chunk::getFrontBlock(int x, int y, int z)
{

    if(y + 1 < Chunk::ysize) {
        return area->getElement(x, y + 1, z);
    } else {
        std::cout << "Array out of bounds\n";
        return nullptr;
    }
}
Block* Chunk::getBehindBlock(int x, int y, int z)
{

    if(y - 1 >= 0) {
        return area->getElement(x, y - 1, z);
    } else {
        std::cout << "Array out of bounds\n";
        return nullptr;
    }
}
Block* Chunk::getLeftBlock(int x, int y, int z)
{

    if(x - 1 >= 0) {
        return area->getElement(x - 1, y, z);
    } else {
        std::cout << "Array out of bounds\n";
        return nullptr;
    }
}
Block* Chunk::getRightBlock(int x, int y, int z)
{

    if(x + 1 < Chunk::xsize) {
        return area->getElement(x + 1, y, z);
    } else {
        std::cout << "Array out of bounds\n";
        return nullptr;
    }
}

void Chunk::init()
{

    glGenBuffers(1, &vboV);

    glBindBuffer(GL_ARRAY_BUFFER, vboV);

    Algorithm m;

    vertices = m.getGreedyMesh(*this);

    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(glm::vec3), vertices.data(), GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    /*
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,vboF);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(faces),faces,GL_STATIC_DRAW);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,0);
        */
}

void Chunk::render()
{

    if(recreateMesh) {
        init();
        recreateMesh = false;
    }

    // std::cout<<glutGet(GLUT_ELAPSED_TIME)<<std::endl;
    glBindBuffer(GL_ARRAY_BUFFER, vboV);

    glEnableClientState(GL_VERTEX_ARRAY);

    glVertexPointer(3, GL_FLOAT, 0, NULL);

    glPushMatrix();
    // glTranslatef(referencePoint.x,referencePoint.y,referencePoint.z);

    // glDrawArrays(GL_LINE_LOOP, 0, 3072 );
    // glDrawArrays(GL_LINE_LOOP, 0, 10401864 );
    glDrawArrays(GL_LINES, 0, vertices.size());
    // glDrawArrays(GL_LINE_LOOP, 0, 32*32*128*12 );
    // glDrawArrays(GL_LINE_LOOP, 0, vertices.size());
    glPopMatrix();

    glDisableClientState(GL_VERTEX_ARRAY); // disable vertex arrays

    // Good practise to release or unbind the buffer, id 0 is reserved for the "NULL" buffer
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    // std::cout<<glutGet(GLUT_ELAPSED_TIME)<<std::endl;
}

void Chunk::deleteVBO()
{
    glDeleteBuffers(1, &vboV);
}

FlatArray<Block*>& Chunk::getFlatArray()
{
    return *area;
}

glm::vec3 Chunk::blockToOpenglCo(int x, int y, int z)
{

    glm::vec3 vec(referencePoint[0] + x * Chunk::length,
                  referencePoint[1] + y * Chunk::length,
                  referencePoint[2] + z * Chunk::length);

    return vec;
}

/*
 template<class Archive>
 void Chunk::serialize(Archive & ar, const unsigned int version)
    {

    ar &referencePoint;
    ar &*area;

    }



*/
