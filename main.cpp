//
// Created by lykku on 2019/7/20.
// Edited by Group 8
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

void glDraw(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    static int timenow = 0; timenow++;

    static auto *cvs = new Canvas; cvs->gettime(timenow);
    cvs->change();
    cvs->draw();

    glutSwapBuffers(); glFlush();
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
//    glutKeyboardFunc(keyboard); // [only for debug]
//    glutMouseFunc(mouse); // [only for debug]
    glutTimerFunc(25, timeStep, 25);
    glutMainLoop();

    return 0;
}
