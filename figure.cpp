//
// Created by lykku on 2019/7/22.
//

#include <cmath>
#include <ctime>
#include <cstdlib>
#include "figure.h"
#include "shape.h"
#include "Vec.h"
using namespace std;

void Vehicle::paint(float *r, float *g, float *b) {
    *r=(float)rand()/RAND_MAX; *g=(float)rand()/RAND_MAX;
    *b=(float)rand()/RAND_MAX;
}
/* Dynamic way of controlling figures (static figures) */
void Vehicle::rescale(double coefficient) {
    w *= coefficient;
    h *= coefficient;
    o *= coefficient;
    R *= coefficient;
}
void Vehicle::setpos(Point pos){
    p.x=pos.x; p.y=pos.y;
}

/* Other figure-related functions */
void Vehicle::setintime(int time){
    intime = time;
}
void Vehicle::setouttime(int time){
    outtime = time;
}
int Vehicle::getintime() {
    return intime;
}
int Vehicle::getouttime(){
    return outtime;
}
int Vehicle::getassignedslot() {return assignedslot;}
void Vehicle::setassignedslot(int slot) {assignedslot=slot;}
int Vehicle::getstatus() {return status;}
void Vehicle::setstatus(int s) {status=s;}
void Vehicle::settype(int t){vtype=t;}
int Vehicle::gettype(){return vtype;}

Vehicle::Vehicle(){
    status = LOT_WAITING;
}
Vehicle::~Vehicle(){}

Car::Car(Point pt1, double width,
         double height, double owidth,double Radii) {
//    srand(time(nullptr));
    float r, g, b; Point p1, p2, p3,p4;
    p=pt1; w=width; h=height; o=owidth; R=Radii;
    p1={p.x-w/2,p.y-h/3}; p2={p.x+w/2,p.y+h/3};
    paint(&r,&g,&b);
    float r1=r,g1=g,b1=b; // ORI: float static r1=r,g1=g,b1=b;
    sh[0]=new class Rectangle(p1,p2,r1,g1,b1);
    p1={p.x+w/2-2*o,p.y+h/3+o}; p2={p.x-w/2+2*o,p.y+h/3+o};p3={p.x-w/2+2*o,p.y+h/3};p4={p.x+w/2,p.y+h/3};
    paint(&r,&g,&b);
    float r2=r,g2=g,b2=b;
    sh[1]=new class Trapezium(p1,p2,p3,p4,r2,g2,b2);
    p1={p.x-2*o,p.y-h/3};
    paint(&r,&g,&b);
    float r3=r,g3=g,b3=b;
    sh[2]=new class Circle(p1,Radii,r3,g3,b3);
    p1={p.x+2*o,p.y-h/3};
    sh[3]=new class Circle(p1,Radii,r3,g3,b3);
    sh[4]=new class Line({p.x-1*w/3,p.y-h/3+flaglng+o},{p.x-1*w/3,p.y-h/3+o+flaglng+o},0,0,0);
    sh[5]=new class Triangle({p.x-1*w/3,p.y-h/3+o+flaglng+o},{p.x-1*w/3,p.y-h/3+2*o+flaglng+o},{p.x-1*w/3+o,p.y-h/3+1.5*o+flaglng+o},1,0,0);
    inrot = 90;// counter-clockwise 90 degrees
    flaglng = 0;
}
Car::~Car() {for(int i=0;i<6;i++) delete sh[i];}
void Car::reset(){
    Point p1,p2,p3,p4;
    p1={p.x - w/2,p.y-h/3}; p2={p.x+w/2,p.y+h/3};
    ((class Rectangle*)sh[0])->reset(p1,p2);
    p1={p.x+w/2-2*o,p.y+h/3+o}; p2={p.x-w/2+2*o,p.y+h/3+o};p3={p.x-w/2+2*o,p.y+h/3};p4={p.x+w/2,p.y+h/3};
    ((Trapezium*)sh[1])->reset(p1,p2,p3,p4);
    p1={p.x-2*o,p.y-h/3};
    ((Circle*)sh[2])->reset(p1,R);
    p1={p.x+2*o,p.y-h/3};
    ((Circle*)sh[3])->reset(p1,R);
    ((Line*)sh[4])->reset({p.x-1*w/3,p.y-h/3+flaglng+o},{p.x-1*w/3,p.y-h/3+o+flaglng+o});
    ((Triangle*)sh[5])->reset({p.x-1*w/3,p.y-h/3+o+flaglng+o},{p.x-1*w/3,p.y-h/3+2*o+flaglng+o},{p.x-1*w/3+o,p.y-h/3+1.5*o+flaglng+o});
    Crotate(inrot);inrot/=2;
}
void Car::magicflag(){
    static int rescalestatus = 0;
    if(rescalestatus%400 < 200) flaglng+=0.0007;
    else flaglng-=0.0007;
    rescalestatus++;rescalestatus=rescalestatus%400;
}
void Car::supermove(double dx, double dy){
    p.x+=dx; p.y+=dy;
    for(int i=0;i<6;i++) sh[i]->supermove(dx,dy);
}
void Car::rotate(Point center, double degree){
    /*move*/
    rotateVec(&p,center,degree);
    for(int i=0;i<6;i++) sh[i]->rotate(center,degree);
    inrot+=degree;

}
void Car::Crotate(double degree){for(int i=0;i<6;i++) sh[i]->rotate(p,degree);inrot+=degree;}
void Car::draw() {magicflag(); reset(); for(int i=0;i<6;i++) sh[i]->draw();}


Teleported::Teleported(Point pt1,double width,double height) {
    float r,g,b;Point p1,p2;
    p=pt1;w=width;h=height;o=-1;R=-1;
//    srand(time(NULL));
    p1={p.x - w/2,p.y-h/2}; p2={p.x+w/2,p.y+h/2};
    paint(&r,&g,&b);
    sh=new class Rectangle(p1,p2,r,g,b);
    inrot = 0; // counter-clockwise 0 degree
}
Teleported::~Teleported() {delete sh;}
void Teleported::reset() {
    Point p1,p2;
    p1={p.x - w/2,p.y-h/2}; p2={p.x+w/2,p.y+h/2};
    ((class Rectangle*)sh)->reset(p1,p2);
}
void Teleported::supermove(double dx, double dy){
    p.x+=dx; p.y+=dy;
    sh->supermove(dx,dy);
}
void Teleported::draw() {
    magictime++;if (magictime%20==0) magic();
    Crotate(inrot);sh->draw();}
void Teleported::rotate(Point center, double degree){sh->rotate(center,degree);rotateVec(&p,center,degree);}
void Teleported::Crotate(double degree){sh->rotate(p,degree);}

void Teleported::magic() {
    int ran=rand()%3;
    delete sh;
    float r,g,b;paint(&r,&g,&b);
    switch (ran){
        case 0:Point p1,p2,p3;
            p1={p.x,p.y+h/2};p2={p.x-h/2,p.y-h/2};p3={p.x+h/2,p.y-h/2};
            sh=new class Triangle(p1,p2,p3,r,g,b);
            break;
        case 1:
            Point p4,p5;
            p4={p.x-h/2,p.y-h/2};p5={p.x+h/2,p.y+h/2};
            sh=new class Rectangle(p4,p5,r,g,b);break;
        case 2:
            Point p6,p7,p8,p9,p10;
            p6={p.x-h/4,p.y+h/2};p7={p.x+h/4,p.y+h/2};p8={p.x+h/2,p.y};p9={p.x,p.y-h/2};p10={p.x-h/2,p.y};
            sh=new class Pentagon(p6,p7,p8,p9,p10,r,g,b);break;
    }
}

UFO::UFO(Point pt1, double width, double height, double owidth) {
    float r, g, b; Point p1, p2, p3,p4;
    p=pt1; w=width; h=height; o=owidth; R=-1;
    p1={p.x,p.y-h/2};
    paint(&r,&g,&b);float r1=r,g1=g,b1=b;
    sh[0]=new class Semicircle(p1,w/2,r1,g1,b1);
    p1={p.x-w/2+2*o/3,p.y-h/2};p2={p.x-2*o/3,p.y-h/2};p3={p.x-o/3,p.y-h/2-o/2};p4={p.x-w/2+o/3,p.y-h/2-o/2};
    paint(&r,&g,&b);float r2=r,g2=g,b2=b;
    sh[1]=new class Trapezium(p1,p2,p3,p4,r2,g2,b2);
    p1={p.x+w/2-o*2/3,p.y-h/2};p2={p.x+o*2/3,p.y-h/2};p3={p.x+o/3,p.y-h/2-o/2};p4={p.x+w/2-o/3,p.y-h/2-o/2};
    sh[2]=new class Trapezium(p1,p2,p3,p4,r2,g2,b2);
    p1={p.x-w/4,p.y-h/2+w/2-o/4};p2={p.x-w/2,p.y-h/2+w/2+o/2};
    paint(&r,&g,&b);float r3=r,g3=g,b3=b;
    sh[3]=new class Line(p1,p2,r3,g3,b3);
    p1={p.x+w/4,p.y-h/2+w/2-o/4};p2={p.x+w/2,p.y-h/2+w/2+o/2};
    sh[4]=new class Line(p1,p2,r3,g3,b3);
    inrot = 3; // counter-clockwise 0 degree
}
UFO::~UFO() {for(int i=0;i<=4;i++) delete sh[i];}
void UFO::debugg(){
    cout<<p.x<<"/"<<p.y<<"/"<<w<<"/"<<h<<"/"<<o<<"/"<<R<<"/"<<inrot<<"/\n";
}
void UFO::reset() {
    Point p1,p2,p3,p4;
    p1={p.x,p.y-h/2+h/2};
    ((class Semicircle*)sh[0])->reset(p1,w/2);
    p1={p.x-w/2+2*o/3,p.y-h/2+h/2};p2={p.x-2*o/3,p.y-h/2+h/2};p3={p.x-o/3,p.y-h/2-o/2+h/2};p4={p.x-w/2+o/3,p.y-h/2-o/2+h/2};
    ((class Trapezium*)sh[1])->reset(p1,p2,p3,p4);
    p1={p.x+w/2-o*2/3,p.y-h/2+h/2};p2={p.x+o*2/3,p.y-h/2+h/2};p3={p.x+o/3,p.y-h/2-o/2+h/2};p4={p.x+w/2-o/3,p.y-h/2-o/2+h/2};
    ((class Trapezium*)sh[2])->reset(p1,p2,p3,p4);
    p1={p.x-w/4,p.y-h/2+w/2-o/8+h/2};p2={p.x-w/2,p.y-h/2+w/2+o/4+h/2};
    ((class Line*)sh[3])->reset(p1,p2);
    p1={p.x+w/4,p.y-h/2+w/2-o/8+h/2};p2={p.x+w/2,p.y-h/2+w/2+o/4+h/2};
    ((class Line*)sh[4])->reset(p1,p2); // Rectangle
    inrot = 3;
}
void UFO::supermove(double dx, double dy){
    p.x+=dx; p.y+=dy;
    for(int i=0;i<5;i++) sh[i]->supermove(dx,dy);
}
void UFO::rotate(Point center, double degree){for(int i=0;i<5;i++) sh[i]->rotate(center,degree);rotateVec(&p,center,degree);}
void UFO::Crotate(double degree){for(int i=0;i<5;i++) sh[i]->rotate({p.x,p.y},degree);}
void UFO::draw() {
    inrot += 3; if(inrot>365)inrot-=360; // self-spinning
    Crotate(3);
    for (int i=0;i<=4;i++) sh[i]->draw();
}

Spacecraft::Spacecraft(Point pt1, double width, double height, double owidth) {
    float r,g,b;Point p1,p2,p3,p4;
    p=pt1;w=width;h=height;o=owidth;R=-1;
    p1={p.x-w/2+o,p.y-h/4};p2={p.x+w/2-o,p.y+h/4};
    paint(&r,&g,&b);float r1=r,g1=g,b1=b;
    sh[0]=new class Rectangle(p1,p2,r1,g1,b1);
    p1={p.x+w/2-o,p.y+h/4};p2={p.x+w/2-o,p.y-h/4};p3={p.x+w/2,p.y};
    paint(&r,&g,&b);float r2=r,g2=g,b2=b;
    sh[1]=new class Triangle(p1,p2,p3,r2,g2,b2);
    p1={p.x,p.y-h/10};p2={p.x+w/8,p.y+h/10};
    paint(&r,&g,&b);float r3=r,g3=g,b3=b;
    sh[2]=new class Rectangle(p1,p2,r3,g3,b3);
    p1={p.x+w/6,p.y+h/8};p2={p.x+w/5,p.y+h/6};
    paint(&r,&g,&b);float r4=r,g4=g,b4=b;
    sh[3]=new class Rectangle(p1,p2,r4,g4,b4);
    p1={p.x+w/6,p.y-h/8};p2={p.x+w/5,p.y-h/6};
    sh[4]=new class Rectangle(p1,p2,r4,g4,b4);
    p1={p.x,p.y+h/4};p2={p.x-w/2+o,p.y+h/4};p3={p.x-w/2+o,p.y+h/2};
    paint(&r,&g,&b);float r5=r,g5=g,b5=b;
    sh[5]=new class Triangle(p1,p2,p3,r5,g5,b5);
    p1={p.x,p.y-h/4};p2={p.x-w/2+o,p.y-h/4};p3={p.x-w/2+o,p.y-h/2};
    sh[6]=new class Triangle(p1,p2,p3,r5,g5,b5);
    p1={p.x-w/2+o,p.y+h/5};p2={p.x-w/2+o,p.y-h/5};p3={p.x-w/2+o/2,p.y-h/4};p4={p.x-w/2+o/2,p.y+h/4};
    paint(&r,&g,&b);float r6=r,g6=g,b6=b;
    sh[7]=new class Trapezium(p1,p2,p3,p4,r6,g6,b6);
    inrot = 90; // counter-clockwise 0 degree
}
Spacecraft::~Spacecraft() {for(int i=0;i<=7;i++) delete sh[i];}
void Spacecraft::reset() {
    Point p1,p2,p3,p4;
    p1={p.x-w/2+o,p.y-h/4};p2={p.x+w/2-o,p.y+h/4};
    ((class Rectangle*)sh[0])->reset(p1,p2);
    p1={p.x+w/2-o,p.y+h/4};p2={p.x+w/2-o,p.y-h/4};p3={p.x+w/2,p.y};
    ((class Triangle*)sh[1])->reset(p1,p2,p3);
    p1={p.x,p.y-h/10};p2={p.x+w/8,p.y+h/10};
    ((class Rectangle*)sh[2])->reset(p1,p2);
    p1={p.x+w/6,p.y+h/8};p2={p.x+w/5,p.y+h/6};
    ((class Rectangle*)sh[3])->reset(p1,p2);
    p1={p.x+w/6,p.y-h/8};p2={p.x+w/5,p.y-h/6};
    ((class Rectangle*)sh[4])->reset(p1,p2);
    p1={p.x,p.y+h/4};p2={p.x-w/2+o,p.y+h/4};p3={p.x-w/2+o,p.y+h/2};
    ((class Triangle*)sh[5])->reset(p1,p2,p3);
    p1={p.x,p.y-h/4};p2={p.x-w/2+o,p.y-h/4};p3={p.x-w/2+o,p.y-h/2};
    ((class Triangle*)sh[6])->reset(p1,p2,p3);
    p1={p.x-w/2+o,p.y+h/5};p2={p.x-w/2+o,p.y-h/5};p3={p.x-w/2+o/2,p.y-h/4};p4={p.x-w/2+o/2,p.y+h/4};
    ((class Trapezium*)sh[7])->reset(p1,p2,p3,p4);
    Crotate(inrot);inrot/=2;
}
void Spacecraft::supermove(double dx, double dy){
    p.x+=dx; p.y+=dy;
    for(int i=0;i<8;i++) sh[i]->supermove(dx,dy);
}
void Spacecraft::rotate(Point center, double degree){for(int i=0;i<8;i++) sh[i]->rotate(center,degree);rotateVec(&p,center,degree);inrot+=degree;}
void Spacecraft::Crotate(double degree){for(int i=0;i<8;i++) sh[i]->rotate(p,degree);inrot+=degree;}
void Spacecraft::draw() {autorescale(); reset(); for(int i=0;i<8;i++) sh[i]->draw();}
void Spacecraft::autorescale() {
    static int rescalestatus = 0;
    if(rescalestatus%200 < 100) rescale(0.97);
    else rescale (1.030928); // parameter assigned
    rescalestatus++;rescalestatus=rescalestatus%200;
}
Occupy::Occupy(Point pt){
    p = pt;
    oc[0]=new class Line({p.x-.05,p.y-.05},{p.x+.05,p.y+.05},1,0,0);
    oc[1]=new class Line({p.x-.05,p.y+.05},{p.x+.05,p.y-.05},1,0,0);
}
Occupy::~Occupy(){for(int i=0;i<2;i++) delete oc[i];}
void Occupy::draw() {for(int i=0;i<2;i++) oc[i]->draw();}