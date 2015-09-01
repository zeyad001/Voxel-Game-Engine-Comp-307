// Copyright (c) 2015
// Muhammad Shoaib Ikram
// Mohamed Zeyad Ballim

// Implement dynamic chunk loading radius
// Storing chunk objs instead of pointers

// Mesh creation, load faces next to air blocks
// modify terraingen

#define GLEW_STATIC
//#include <windows.h> // for MS Windows
#include <GL/glew.h>
#include <GL/freeglut.h> // GLUT, include glu.h and gl.h
#include <iostream>
#include <math.h>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include "FlatArray.h"
#include "World.h"
#ifdef _WIN32
#include <Windows.h>
float M_PI = 22.0f / 7.0f;
#else
#include <unistd.h>
#endif

using namespace std;

const int FPS = 200;
// float M_PI = 22.0f/7.0f;
// int time = 0;
float x_rotation = 0;
float y_rotation = 0;
// int time = 0;
float turn_inc;
float x_dist_at;
float camera[3][3] = { { x_dist_at, 0, 0 }, { 0, 0, 0 }, { 0, 0, 1.0f } };
float lx, ly, lz;
float angle;

World* w = new World();

void resetCamera()
{
    angle = 0;
    ly = 0;
    lx = 0;
    camera[0][0] = x_dist_at;
}

void sleep(int time)
{

#ifdef _WIN32
    Sleep(time);
#else
    usleep(time * 1000);
#endif
}

/* Initialize OpenGL Graphics */
void initGL()
{
    // Set "clearing" or background color
    glClearColor(0, 0, 0, 1); // White and opaque

    glEnable(GL_DEPTH_TEST); // turns on hidden surface removal so that objects behind other objects do not get
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    turn_inc = 2.0; // in degrees

    x_dist_at = 1.0;

    resetCamera();

    GLenum err = glewInit();
    if(GLEW_OK != err) {
        std::cout << glewGetErrorString(err);
        /* Problem: glewInit failed, something is seriously wrong. */
        fprintf(stderr, "Error: %s\n", glewGetErrorString(err));
    }
}

void setCamera()
{

    gluLookAt(camera[0][0],
              camera[0][1],
              camera[0][2],
              camera[1][0],
              camera[1][1],
              camera[1][2],
              camera[2][0],
              camera[2][1],
              camera[2][2]);
}

void render()
{

    // GL_DEPTH_BUFFER_BIT - resets the depth test values for hidden surface removal

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Reset transformations
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    setCamera();

    glColor3f(1, 0, 0);
    w->render();

    glutMainLoopEvent();
    glutSwapBuffers(); // ******** DO NOT FORGET THIS **********
}

void update()
{

    // w->setPlayerPostion(camera[0][0],camera[0][1],camera[0][2]);
}

void input()
{
}
void init()
{
    w->loadChunks();
}

void gameLoop()
{

    init();
    while(true) {

        input();
        update();
        render();
        sleep(1000 / FPS);
    }
}

/* Handler for window-repaint event. Call back when the window first appears and
   whenever the window needs to be re-painted. */
void display()
{

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Reset transformations
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    setCamera();

    // render();
}

/* Handler for window re-size event. Called back when the window first appears and
   whenever the window is re-sized with its new width and height */

void reshape(int w, int h)
{

    // Prevent a divide by zero, when window is too short
    // (you cant make a window of zero width).
    if(h == 0)
        h = 1;

    GLfloat ratio = 1.0f * (GLfloat)w / (GLfloat)h;

    // Set the viewport to be the entire window
    glViewport(0, 0, w, h);

    // Reset the coordinate system before modifying
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    // Set the clipping volume
    gluPerspective(45, ratio, 0.1, 1000);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void processNormalKeys(unsigned char key, int x, int y)
{

    switch(key) {
    // case 'l' : lookAround(); break;
    case 27:
        w->deleteFiles();
        exit(0);
        break;
    case 'q':
        camera[0][2] = camera[0][2] - 0.2f;
        // camera[1][2] = camera[1][2] - 1.0f;
        break;
    case 'a':
        camera[0][2] = camera[0][2] + 0.2f;
        // camera[1][2] = camera[1][2] + 1.0f;
        break;
    }

    cout << camera[0][2] << endl;
    // glutPostRedisplay();
}

void inputKey(int key, int ix, int iy)
{
    float a, y, x;
    switch(key) {
    case GLUT_KEY_LEFT:
        angle += turn_inc;
        a = M_PI * angle / 180.0;
        ly = x_dist_at * sin(a);
        lx = x_dist_at * cos(a);
        camera[1][1] = camera[0][1] - ly;
        camera[1][0] = camera[0][0] - lx;
        break;

    case GLUT_KEY_RIGHT:
        angle -= turn_inc;
        a = M_PI * angle / 180.0;
        ly = x_dist_at * sin(a);
        lx = x_dist_at * cos(a);
        camera[1][1] = camera[0][1] - ly;
        camera[1][0] = camera[0][0] - lx;
        break;

    case GLUT_KEY_UP:
        a = M_PI * angle / 180.0;
        y = sin(a);
        x = cos(a);
        camera[0][1] -= y; // move x by
        camera[0][0] -= x;
        camera[1][1] -= y; // move x by
        camera[1][0] -= x;
        break;
    case GLUT_KEY_DOWN:
        a = M_PI * angle / 180.0;
        y = sin(a);
        x = cos(a);
        camera[0][1] += y; // move x by
        camera[0][0] += x;
        camera[1][1] += y; // move x by
        camera[1][0] += x;
        break;
    }

    //  glutPostRedisplay();
}

void idle()
{
    // render();
    glutPostRedisplay(); // called when there is now other event
}

/* Main function: GLUT runs as a console application starting at main() */
int main(int argc, char** argv)
{
    glutInit(&argc, argv); // Initialize GLUT
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(640, 480);              // Set the window's initial width & height - non-square
    glutInitWindowPosition(50, 50);            // Position the window's initial top-left corner
    glutCreateWindow("Beware of the Voxel's"); // Create window with the given title

    initGL();                 // Our own OpenGL initialization
                              //  init();
    glutDisplayFunc(render);  // Register callback handler for window re-paint event
    glutReshapeFunc(reshape); // Register callback handler for window re-size event

    glutKeyboardFunc(processNormalKeys);
    glutSpecialFunc(inputKey);

    //  glutIdleFunc(idle);

    gameLoop();

    // glutMainLoop();
    return 0;
}
