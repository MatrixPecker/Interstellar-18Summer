//
// Created by lykku on 2019/7/20.
//

#include <iostream>
#include <ctime>
#include <GL/glut.h>
#include "Vec.h"
#include "Shape.h"

using namespace std;

void timeStep(int step){
    glutTimerFunc(step, timeStep, step);
    glutPostRedisplay();
}
void glDraw(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//    Canvas cvs({0,0},step);
//    cvs.move(&step);
    static double r = 0;
    static Point center = {0.2, 0.4};
    Point p1={-0.2,-0.2},p2={-0.4,0.1},p3={0.02,-0.05};
    r += 10;
    rotateVec(&p1,center,r);rotateVec(&p2,center,r);rotateVec(&p3,center,r);
    Triangle sh1(p1,p2,p3,0.956863,0.815686,1.0);
    sh1.draw();
    //Shape *sh1; sh1=new

//    cvs.draw();
    glutSwapBuffers(); glFlush();
//    cout << "Drawing complete. Close the window to exit.\n";
}

int main(int argc, char** argv){
    srand(time(nullptr));

    // Init window

    // step function
    // GL main loop
    // define corresponding functions in tools.cpp
    glutInit(&argc, argv);
    glutInitWindowSize(500, 500);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutCreateWindow("P3_partial");

    glClearColor(1.0, 1.0, 1.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);


    glutDisplayFunc(glDraw);
    glutTimerFunc(25, timeStep, 25);
    glutMainLoop();

    return 0;
}
