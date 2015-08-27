#ifndef GAMELOOP_H
#define GAMELOOP_H

class GameLoop
{
private:
    float height = 900;
    float width = 1200;

public:
    GameLoop();
    ~GameLoop();
    bool run;
    void pause();
    void resume();
    void render();
    void update();
    void input();
    bool isPaused();
    void init(int, char**);
  

#endif // GAMELOOP_H
