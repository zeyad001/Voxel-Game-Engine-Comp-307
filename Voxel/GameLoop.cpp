
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <cmath>

#include "GameLoop.h"
#include <GL/freeglut.h>

Time* t = nullptr;

int* elapsed;

GameLoop::GameLoop()
{
    run = true;
    t = new Time(2);
}

GameLoop::~GameLoop()
{
}

void display()
{

    // std::cout << "Display" << std::endl;
    // GL_DEPTH_BUFFER_BIT - resets the depth test values for hidden surface removal
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Reset transformations
    glMatrixMode(GL_MODELVIEW);

    glLoadIdentity();
    glColor3f(0.9f, 0.9f, 0.9f);

    elapsed = new int(glutGet(GLUT_ELAPSED_TIME));


    t->update(*elapsed);
    
    
    setCamera();

    w->setPlayerPostion(camera[0][0],camera[0][1],camera[0][2]);
    w->render();
    
   
}
void initGL()
{
    glClearColor(1, 1, 1, 1); // White and opaque

    glEnable(GL_DEPTH_TEST); // turns on hidden surface removal so that objects behind other objects do not get displayed
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    turn_inc = 2.0; // in degrees

    z_dist_at = 68.0;

    resetCamera();
}
void reshape(int w, int h)
{

    // Prevent a divide by zero, when window is too short
    // (you cant make a window of zero width).
    if(h == 0)
	h = 1;

    GLfloat ratio = 1.0f * (GLfloat)w / (GLfloat)h;

    // Set the viewport to be the entire window
    glViewport(0, 0, w, h);

    glLoadIdentity();
    // Reset the coordinate system before modifying
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    // Set the clipping volume
    gluPerspective(60, ratio, 0.1, 100);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void GameLoop::init(int argc, char** argv)
{
    glutInit(&argc, argv); // Initialize GLUT
    // glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(width, height);      // Set the window's initial width & height - non-square
    glutInitWindowPosition(50, 50);         // Position the window's initial top-left corner
    glutCreateWindow("This is not a Game"); // Create window with the given title

    glutReshapeFunc(reshape);
    glutDisplayFunc(display);

    glutSetCursor(GLUT_CURSOR_NONE);
    glutWarpPointer(glutGet(GLUT_WINDOW_WIDTH) / 2, glutGet(GLUT_WINDOW_WIDTH) / 2);

  w->loadChunks();
       GLenum err = glewInit();
    if (GLEW_OK != err)
    {
        std::cout<<glewGetErrorString(err);
        /* Problem: glewInit failed, something is seriously wrong. */
        fprintf(stderr, "Error: %s\n", glewGetErrorString(err));
    }
  

    // glEnable(GL_DEPTH_TEST);

    initGL(); // Our own OpenGL initialization

    
}
void setCamera()
{

    gluLookAt(camera[0][2],
              camera[0][0],
              camera[0][1],
              camera[1][2],
              camera[1][0],
              camera[1][1],
              camera[2][0],
              camera[2][2],
              camera[2][1]);
}
/*

void processNormalKeys(unsigned char key, int xx, int yy)
{

        eventSystem.createEvent(1,key);

}

void releaseKey(unsigned char key, int x, int y)
{

  eventSystem.createEvent(2,key);


}
*/
void GameLoop::pause()
{
    run = false;
}
void GameLoop::resume()
{
    run = true;
}
bool GameLoop::isPaused()
{
    return !run;
}
void GameLoop::input()
{

    // glutIgnoreKeyRepeat(1);
    //  glutKeyboardFunc(processNormalKeys);
    // glutKeyboardUpFunc(releaseKey);

}
void GameLoop::render()
{
    // Register callback handler for window re-paint event
    // display();
    glutPostRedisplay();
    glutMainLoopEvent();
    glutSwapBuffers(); // ******** DO NOT FORGET THIS **********
}
void GameLoop::update()
{

   
}

