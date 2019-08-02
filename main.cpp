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
#include "Engine.h"
#include "Canvas.h"
using namespace std;

void timeStep(int step){
    glutTimerFunc(step, timeStep, step);
    glutPostRedisplay();
}
void TestDraw1(){ // only for demonstration of the rotation of single figures
    static double r = 0; r += 10;

    Spacecraft sh1({-0.4,0.4},0.3,0.2,0.2/3.0);
    Car sh3({-0.4,-0.4},1.0/3,1.3/3,0.175/3,0.1/3);
    Teleported sh4({0.4,0.4},1.0/3,0.5/3);
    UFO sh5({0.4,-0.4},1.0/3,0.5/3,0.5/3);
    sh1.rotate({-0.4,0.4},r);sh3.rotate({-0.4,-0.4},r);sh4.rotate({0.4,0.4},r);sh5.rotate({0.4,-0.4},r);

    sh1.draw();sh3.draw();sh4.draw();sh5.draw();
}
void glDraw(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    static int timenow = 0; timenow++;
    static Canvas cvs;
    cvs.change(timenow);
    cvs.draw();

//    TestDraw2();
    glutSwapBuffers(); glFlush();
}

int main(int argc, char** argv){
    srand(time(nullptr));
    // Init window

    // step function
    // GL main loop
    // define corresponding functions in tools.cpp
    glutInit(&argc, argv);
    glutInitWindowSize(900, 900);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutCreateWindow("P3_partial");

    glClearColor(1.0, 1.0, 1.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);


    glutDisplayFunc(glDraw);
    glutTimerFunc(25, timeStep, 25);
    glutMainLoop();

    return 0;
}
