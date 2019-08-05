//
// Created by lykku on 2019/7/20.
//
#ifdef __APPLE__
#include <GLUT/glut.h>
#elif _WIN32
#include <windows.h>
#include <GL/freeglut.h>
#else
#include <GL/freeglut.h>
#endif
#include <iostream>
#include <ctime>
#include "Vec.h"
#include "shape.h"
#include "parkinglot.h"
#include "figure.h"
#include "Canvas.h"
using namespace std;

void timeStep(int step){
    glutTimerFunc(step, timeStep, step);
    glutPostRedisplay();
}

//void TestDraw1(){ // [demonstration of the rotation of single figures]
//    static double r = 0; r += 10;
//
//    Spacecraft sh1({-0.4,0.4},0.3,0.2,0.2/3.0);
//    Car sh3({-0.4,-0.4},1.0/3,1.3/3,0.175/3,0.1/3);
//    Teleported sh4({0.4,0.4},1.0/3,0.5/3);
//    UFO sh5({0.4,-0.4},1.0/3,0.5/3,0.5/3);
//    sh1.rotate({-0.4,0.4},r);sh3.rotate({-0.4,-0.4},r);sh4.rotate({0.4,0.4},r);sh5.rotate({0.4,-0.4},r);
//
//    sh1.draw();sh3.draw();sh4.draw();sh5.draw();
//}
void glDraw(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    static int timenow = 0; timenow++;

    static auto *cvs = new Canvas; cvs->gettime(timenow);
    cvs->change();
    cvs->draw();

    glutSwapBuffers(); glFlush();
}

void mouse(int button, int state, int x, int y) // [only for debug]
{
    GLint viewport[4];
    GLdouble mvmatrix[16], projmatrix[16];
    GLint realy;  /*  OpenGL y coordinate position  */
    GLdouble wx, wy, wz;  /*  returned world x, y, z coords  */
    switch (button) {
        case GLUT_LEFT_BUTTON:
            if (state == GLUT_DOWN) {
                glGetIntegerv (GL_VIEWPORT, viewport);
                glGetDoublev (GL_MODELVIEW_MATRIX, mvmatrix);
                glGetDoublev (GL_PROJECTION_MATRIX, projmatrix);
/*  note viewport[3] is height of window in pixels  */
                realy = viewport[3] - (GLint) y - 1;
                printf ("Coordinates at cursor are (%4d, %4d)\n", x, realy);
                gluUnProject ((GLdouble) x, (GLdouble) realy, 0.0,
                              mvmatrix, projmatrix, viewport, &wx, &wy, &wz);
                printf ("World coords at z=0.0 are (%f, %f, %f)\n",
                        wx, wy, wz);
                gluUnProject ((GLdouble) x, (GLdouble) realy, 1.0,
                              mvmatrix, projmatrix, viewport, &wx, &wy, &wz);
                printf ("World coords at z=1.0 are (%f, %f, %f)\n",
                        wx, wy, wz);
            }
            break;
        case GLUT_RIGHT_BUTTON:
            if (state == GLUT_DOWN)
                exit(0);
            break;
        default:
            break;
    }
}
void keyboard(unsigned char key, int x, int y) // [only for debug]
{
    switch (key) {
        case 27:
            exit(0);
            break;
    }
}

int main(int argc, char** argv){
    srand(time(0));

    glutInit(&argc, argv);
    glutInitWindowSize(900, 900);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutCreateWindow("P3_Aug-3");

    glClearColor(1.0, 1.0, 1.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);

    glutDisplayFunc(glDraw);
    glutKeyboardFunc(keyboard); // [only for debug]
    glutMouseFunc(mouse); // [only for debug]
    glutTimerFunc(25, timeStep, 25);
    glutMainLoop();

    return 0;
}
