#include "World.h"
#include <iostream>
#include <fstream>
#include <ios>
#include <sstream>
#include <string>
#include <cstdio>

using namespace std;

World::World()
{
    // Chunk* c = TerrainGen::getTerrainManager()->generateFlatSurface(0, 0, -64);
    loadConfigs();
}

World::~World()
{
}

void World::render()
{
    for(unsigned int i = 0; i < loadedChunks.size(); i++) {
        // std::cout<<loadedChunks[i].x<<" "<<loadedChunks[i].y<<std::endl;
    }

    // for(Chunk* c : world)
    for(Chunk* c : world) {

        c->render();
    }
}

void World::loadChunks()
{
    Pos p = { 0, 0 };
    loadedChunks.push_back(p);
    // world.push_back(new Chunk(0,0));

    Chunk* c = new Chunk(0, 0);
    TerrainGen::getTerrainManager()->generateFlatSurface(*c);
   // TerrainGen::getTerrainManager()->generateAllAir(*c);
   // TerrainGen::getTerrainManager()->generateMantle(*c);

    world.push_back(c);
}

vector<Pos> World::chunkCoordinates(int x, int y)
{
    vector<Pos> tempChunks;

    int dist = (chunkRadius - 1) / 2;

    for(int i = y + dist; i >= y - dist; i--) {
        for(int j = x + dist; j >= x - dist; j--) {
            Pos p = { j, i };
            tempChunks.push_back(p);
        }
    }

    return tempChunks;
}

void World::setPlayerPostion(int x, int y, int z)
{
    // std::cout<<world.size()<<std::endl;

    int chunkX = x / 32;
    int chunkY = y / 32;

    // std::cout<<chunkX<<" "<<chunkY<<std::endl;
    // std::cout<<loadedChunks.size()<<" X: "<<x<<" Y: "<<y<<std::endl;
    vector<Pos> cPos = chunkCoordinates(chunkX, chunkY);

    // cout<<cPos.size();
    // cout<<"  "<<chunkRadius*chunkRadius<<endl;

    unsigned int temp[chunkRadius * chunkRadius];

    for(unsigned int i = 0; i < chunkRadius * chunkRadius; i++)
        temp[i] = 1;

    for(unsigned int i = 0; i < loadedChunks.size(); i++) {
        for(unsigned int j = 0; j < cPos.size(); j++) {
            if(loadedChunks[i].x == cPos[j].x) {
                if(loadedChunks[i].y == cPos[j].y) {
                    temp[j] = 0;
                }
            }
        }
    }

    // int temp[9] = {1,1,1,1,1,1,1,1,1};
    /*
    for(unsigned int i = 0; i < loadedChunks.size(); i++)
    {
        if(loadedChunks[i].x == chunkX + 1)
        {
            if(loadedChunks[i].y == chunkY + 1)
            {
                temp[0] = 0;
                //break;
            }
            else if(loadedChunks[i].y == chunkY)
            {
                temp[1] = 0;
                //break;
            }
            else if(loadedChunks[i].y == chunkY - 1)
            {
                temp[2] = 0;
                //break;
            }
        }
        else if(loadedChunks[i].x == chunkX)
        {
            if(loadedChunks[i].y == chunkY + 1)
            {
                temp[3] = 0;
                //break;
            }
            else if(loadedChunks[i].y == chunkY)
            {
                temp[4] = 0;
                //break;
            }
            else if(loadedChunks[i].y == chunkY - 1)
            {
                temp[5] = 0;
                //break;
            }
        }

        else if(loadedChunks[i].x == chunkX - 1)
        {
            if(loadedChunks[i].y == chunkY + 1)
            {
                temp[6] = 0;
                //break;
            }
            else if(loadedChunks[i].y == chunkY)
            {
                temp[7] = 0;
                //break;
            }
            else if(loadedChunks[i].y == chunkY - 1)
            {
                temp[8] = 0;
                //break;
            }
        }
    }
*/
    // std::cout<<world.size()<<std::endl;
    /*
    Chunk c = Chunk();
    //
    std::cout<<temp[0]<<temp[1]<<temp[2]<<std::endl<<temp[3]<<temp[4]<<temp[5]<<std::endl<<temp[6]<<temp[7]<<temp[8]<<std::endl;

    for(unsigned int i = 0; i < cPos.size(); i++) {
        if(temp[i] == 1) {
            Pos p = cPos[i];
            loadedChunks.push_back(p);
            if(c.exists(p.x, p.y))
                world.push_back(c.load(p.x, p.y));
            else
                world.push_back(TerrainGen::getTerrainManager()->generateFlatSurface((p.x) * 32, (p.y) * 32));
            // world.push_back(new Chunk((p.x)*32,(p.y)*32));
        }
    }
     */
    /*
        if(temp[0] == 1)
        {
            Pos p = {chunkX+1,chunkY+1};
            loadedChunks.push_back(p);
            if(c.exists(chunkX+1,chunkY+1))
                world.push_back(c.load(p.x,p.y));
            else
                world.push_back(new Chunk((chunkX+1)*32,(chunkY+1)*32));
        }
        if(temp[1] == 1)
        {
            Pos p = {chunkX+1,chunkY};
            loadedChunks.push_back(p);
            if(c.exists(chunkX+1,chunkY))
                world.push_back(c.load(p.x,p.y));
            else
                world.push_back(new Chunk((chunkX+1)*32,(chunkY)*32));
        }

        if(temp[2] == 1)
        {
            Pos p = {chunkX+1,chunkY-1};
            loadedChunks.push_back(p);
            if(c.exists(p.x,p.y))
                world.push_back(c.load(p.x,p.y));
            else
                world.push_back(new Chunk((chunkX+1)*32,(chunkY-1)*32));
        }

        if(temp[3] == 1)
        {
            Pos p = {chunkX,chunkY+1};
            loadedChunks.push_back(p);
            if(c.exists(p.x,p.y))
                world.push_back(c.load(p.x,p.y));
            else
                world.push_back(new Chunk((chunkX)*32,(chunkY+1)*32));
        }
        if(temp[4] == 1)
        {
            Pos p = {chunkX,chunkY};
            loadedChunks.push_back(p);
            if(c.exists(p.x,p.y))
                world.push_back(c.load(p.x,p.y));
            else
                world.push_back(new Chunk((chunkX)*32,(chunkY)*32));
        }
        if(temp[5] == 1)
        {
            Pos p = {chunkX,chunkY-1};
            loadedChunks.push_back(p);
            if(c.exists(p.x,p.y))
                world.push_back(c.load(p.x,p.y));
            else
                world.push_back(new Chunk((chunkX)*32,(chunkY-1)*32));
        }
        if(temp[6] == 1)
        {
            Pos p = {chunkX-1,chunkY+1};
            loadedChunks.push_back(p);
            if(c.exists(p.x,p.y))
                world.push_back(c.load(p.x,p.y));
            else
                world.push_back(new Chunk((chunkX-1)*32,(chunkY+1)*32));
        }
        if(temp[7] == 1)
        {
            Pos p = {chunkX-1,chunkY};
            loadedChunks.push_back(p);
            if(c.exists(p.x,p.y))
                world.push_back(c.load(p.x,p.y));
            else
                world.push_back(new Chunk((chunkX-1)*32,(chunkY)*32));
        }
        if(temp[8] == 1)
        {
            Pos p = {chunkX-1,chunkY-1};
            loadedChunks.push_back(p);
            if(c.exists(p.x,p.y))
                world.push_back(c.load(p.x,p.y));
            else
                world.push_back(new Chunk((chunkX-1)*32,(chunkY-1)*32));
        }
    */
    unloadChunks(chunkX, chunkY);

    for(int i = 0; i < loadedChunks.size(); i++) {
        bool found = false;
        for(int j = 0; j < allChunks.size(); j++) {
            if(loadedChunks[i].x == allChunks[j].x && loadedChunks[i].y == allChunks[j].y) {
                found = true;
                break;
            }
        }

        if(!found)
            allChunks.push_back(loadedChunks[i]);
    }
}

void World::unloadChunks(int chunkX, int chunkY)
{
    std::vector<Pos> tempChunks = chunkCoordinates(chunkX, chunkY);
    /*
        tempChunks.push_back(Pos {chunkX+1,chunkY+1});
        tempChunks.push_back(Pos {chunkX+1,chunkY});
        tempChunks.push_back(Pos {chunkX+1,chunkY-1});

        tempChunks.push_back(Pos {chunkX,chunkY+1});
        tempChunks.push_back(Pos {chunkX,chunkY});
        tempChunks.push_back(Pos {chunkX,chunkY-1});

        tempChunks.push_back(Pos {chunkX-1,chunkY+1});
        tempChunks.push_back(Pos {chunkX-1,chunkY});
        tempChunks.push_back(Pos {chunkX-1,chunkY-1});
    */
    for(unsigned int i = 0; i < loadedChunks.size(); i++) {
        bool found = false;
        for(unsigned int j = 0; j < tempChunks.size(); j++) {
            if(loadedChunks[i].x == tempChunks[j].x) {
                if(loadedChunks[i].y == tempChunks[j].y) {
                    found = true;
                    break;
                }
            }
        }

        if(!found) {
            // std::cout<<loadedChunks[i].x<<" "<<loadedChunks[i].y<<std::endl;
            // world[i]->unload(*world[i],loadedChunks[i].x,loadedChunks[i].y);
            world[i]->unload(world[i], loadedChunks[i].x, loadedChunks[i].y);
            // world[i]->deleteVBO();
            // world[i].deleteVBO();
            loadedChunks.erase(loadedChunks.begin() + i);
            world.erase(world.begin() + i);
            // std::cout<<loadedChunks[i].x<<" "<<loadedChunks[i].y<<std::endl;
            i--;
        }
    }
}

void World::loadConfigs()
{
    ifstream file("configs.cfg");

    if(file.good()) {
        string parameter;
        file >> parameter;

        cout << parameter << endl;

        if(parameter == "radius:") {
            int r = 0;
            string temp;
            file >> temp;
            cout << temp << endl;
            for(unsigned int i = 0; i < temp.length(); i++) {
                char c = temp[i];

                if(c == '-') {
                    r = -1;
                    break;
                } else if(c == '0' || c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' ||
                          c == '7' || c == '8' || c == '9') {
                    r = r * 10 + (int)c - 48;
                } else if(c == '+') {
                    r = r;
                } else {
                    r = -1;
                    break;
                }
            }

            if(r % 2 == 0) {
                r++;
            }

            if(r <= 0) {
                this->chunkRadius = 3;

                file.close();
                ofstream file2("configs.cfg");

                file2 << "radius: 3";
                file2.close();
            }

            this->chunkRadius = r;
        }
    } else {
        this->chunkRadius = 3;

        file.close();
        ofstream file2("configs.cfg");

        file2 << "radius: 3";
        file2.close();
    }

    file.close();

    cout << chunkRadius << endl;
}

void World::deleteFiles()
{
    for(int i = 0; i < allChunks.size(); i++) {
        string xT;
        string yT;
        ostringstream convert;
        convert << allChunks[i].x;
        xT = convert.str();
        convert << allChunks[i].y;
        yT = convert.str();
        std::string s = "Chunks_stored_" + xT + "_" + yT + ".vx";
        const char* filename = s.c_str();
        /*
                Chunk c;
                if(c.exists(allChunks[i].x, allChunks[i].y))
                    remove(filename);*/
    }
}
