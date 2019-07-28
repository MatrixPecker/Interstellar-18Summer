#include <iostream>
#include <ctime>
using namespace std;
#include "Vec.h"
#include "shape.h"
#include "figure.h"
#include "Engine.h"

void timeStep(int step){
    glutTimerFunc(step, timeStep, step);
    glutPostRedisplay();
}
void TestDraw1(){
    static double r = 0; r += 10;

    static Point center = {0.2,0.2};//{0.2, 0.4};
    Spacecraft sh1({-0.4,0.4},0.3,0.2,0.2/3.0);
    Home sh2({-0.4,0.0},0.2,0.25,0.012,0.15);
    Car sh3({-0.4,-0.4},1.0/3,1.3/3,0.175/3,0.1/3);
    Teleported sh4({0.4,0.4},1.0/3,0.5/3);
    UFO sh5({0.4,-0.4},1.0/3,0.5/3,0.5/3);
    sh1.rotate({-0.4,0.4},r);sh2.rotate({-0.4,0.0},r);sh3.rotate({-0.4,-0.4},r);sh4.rotate({0.4,0.4},r);sh5.rotate({0.4,-0.4},r);

    sh1.draw();sh2.draw();sh3.draw();sh4.draw();sh5.draw();
}
void TestDraw2(){
    static int tmpTime = 0; tmpTime++;static int flag=0;
    static double r = 0,lng = 0.01;
    static Point Csh = {-0.4,-0.4};
    double movelng[] = {0.3,0.7};
    Car sh(Csh,1.0/10,1.3/10,0.175/10,0.1/10);

    if(tmpTime <= (int)(movelng[0]/lng)) sh.moveup(&Csh.x,&Csh.y);
    else if(tmpTime > (int)(movelng[0]/lng) && tmpTime <= (int)(movelng[0]/lng)+90){
        r -= 1;
        sh.rotate({-0.3,-0.1},r);
        if(tmpTime==(int)(movelng[0]/lng)+90) sh.moveln(&Csh.x,&Csh.y,0.1,0.1);
    }
    else if(tmpTime > (int)(movelng[0]/lng)+90 && tmpTime <= (int)(movelng[0]/lng)+90+(int)(movelng[1]/lng)){
        sh.moveright(&Csh.x,&Csh.y);flag=0;
        sh.Crotate(r);
    }
    else if(tmpTime > (int)(movelng[0]/lng)+90+(int)(movelng[1]/lng) && tmpTime <= (int)(movelng[0]/lng)+90+(int)(movelng[1]/lng)+90){
//        if(tmpTime==(int)(movelng[0]/lng)+90+(int)(movelng[1]/lng)+1) sh.moveln(&Csh.x,&Csh.y,-0.1,-0.1);
        if(flag==0) {sh.moveln(&Csh.x,&Csh.y,-0.1,-0.1);flag=1;}
        r += 1;
        sh.rotate({0.4,-0.1},r);
    }
//    else sh.rotate({0.4,-0.1},r);

    sh.draw();
}
void glDraw(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//    Canvas cvs({0,0},step);
//    cvs.move(&step);
    TestDraw2();
//    cvs.draw();
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
