//
// Created by lykku on 2019/7/22.
//

#include "figure.h"
#include <math.h>
#include "shape.h"

#include <ctime>
#include <cstdlib>
using namespace std;
void Vehicle::zoom(double *width, double *height, double *owidth,double *Radii){
    int static i=0;
    if(h>=0.1 && i==0) zoomout(width, height, owidth,Radii);
    else if (h<=2) { i=1; zoomin(width, height, owidth,Radii); }
    else i=0;
}
void Vehicle::zoomout(double *width, double *height, double *owidth,double *Radii){
    h/=1.01; *height=h; w/=1.01; *width=w; o/=1.01; *owidth=o;R/=1.01;*Radii=R;
}
void Vehicle::zoomin(double *width, double *height, double *owidth,double *Radii){
    h*=1.01; *height=h; w*=1.01; *width=w; o*=1.01; *owidth=o;R*=1.01;*Radii=R;
}
void Vehicle::paint(float *r, float *g, float *b) {
    *r=(float)rand()/RAND_MAX; *g=(float)rand()/RAND_MAX;
    *b=(float)rand()/RAND_MAX;
}
void Vehicle::moveup(double *dx, double *dy) {
    p.x+=0;*dx=p.x;p.y+=0.01;*dy=p.y;
}
void Vehicle::movedown(double *dx, double *dy) {
    p.x+=0;*dx=p.x;p.y-=0.01;*dy=p.y;
}
void Vehicle::moveleft(double *dx, double *dy) {
    p.x-=0.01;*dx=p.x;p.y+=0;*dy=p.y;
}
void Vehicle::moveright(double *dx, double *dy) {
    p.x+=0.01;*dx=p.x;p.y+=0;*dy=p.y;
}

int Vehicle::getintime(int time) {
    intime=time;
    return intime;
}

int Vehicle::getouttime(int time){
    outtime=time;
    return time;
}
  
Home::Home(Point pt1, double width, double height, double owidth,double Radii){
    float r, g, b; Point p1, p2, p3;
    p=pt1; w=width; h=height; o=owidth; R=Radii;srand(time(0));
    p1={p.x - w/2,p.y-w/2}; p2={p.x+w/2,p.y+w/2};
    paint(&r,&g,&b); sh[0]=new class Rectangle(p1,p2,r,g,b);
    p1={p.x-o,p.y-w/2}; p2={p.x+o,p.y};
    paint(&r,&g,&b); sh[1]=new class Rectangle(p1,p2,r,g,b);
    p1={p.x-2*o,p.y+o}; p2={p.x-o,p.y+2*o};
    paint(&r,&g,&b); sh[2]=new class Rectangle(p1,p2,r,g,b);
    p1={p.x+w/2-2*o,p.y+o}; p2={p.x+w/2-o,p.y+2*o};
    paint(&r,&g,&b); sh[3]=new class Rectangle(p1,p2,r,g,b);
    p1={p.x,p.y+h-w/2}; p2={p.x-w/2,p.y+w/2}; p3={p.x+w/2,p.y+w/2};
    paint(&r,&g,&b); sh[4]=new class Triangle(p1,p2,p3,r,g,b);
    p1={p.x,p.y};
    paint(&r,&g,&b);sh[5]=new class Circle(p1,Radii,r,g,b);
}
Home::~Home(){ for(int i=0;i<6;i++) delete sh[i]; }

void Home::draw() {for(int i=0;i<6;i++) sh[i]->draw();}

Car::Car(Point pt1, double width,
         double height, double owidth,double Radii) {
    float r, g, b; Point p1, p2, p3,p4;
    p=pt1; w=width; h=height; o=owidth; R=Radii;srand(time(0));
    p1={p.x - w/2,p.y-h/2}; p2={p.x+w/2,p.y+h/2};
    paint(&r,&g,&b);
    float static r1=r,g1=g,b1=b;
    sh[0]=new class Rectangle(p1,p2,r1,g1,b1);
    p1={p.x-w/2+2*o,p.y+h/2+o}; p2={p.x+w/2-2*o,p.y+h/2+o};p3={p.x+w/2-2*o,p.y+h/2};p4={p.x-w/2,p.y+h/2};
    paint(&r,&g,&b);
    float static r2=r,g2=g,b2=b;
    sh[1]=new class Trapezium(p1,p2,p3,p4,r2,g2,b2);
    p1={p.x-1.5*o,p.y-h/2};
    paint(&r,&g,&b);
    float static r3=r,g3=g,b3=b;
    sh[2]=new class Circle(p1,Radii,r3,g3,b3);
    p1={p.x+1.5*o,p.y-h/2};
    sh[3]=new class Circle(p1,Radii,r3,g3,b3);

}
Car::~Car() {for(int i=0;i<4;i++) delete sh[i];}
void Car::draw() {for(int i=0;i<4;i++) sh[i]->draw();}

void Car::printin(Point position,int time){
    Car::intime=time;
    cout<<"*************Arrival ticket*************"<<endl;
    cout<<"* Arrival time: "<<getintime(time)<<endl;
    cout<<"* Type of vehicle: Car "<<endl;
    cout<<"* Empty slot: "<<position.x<<","<<position.y<<endl;
    cout<<"****************************************"<<endl;
}

void Car::printout(int time) {
    Car::outtime = time;
    int totaltime = Car::outtime - Car::intime;
    double price = totaltime * Car::price;             //different car should have different price standards.
    cout << "*************Departure ticket*************" << endl;
    cout << "* Time spent: " << totaltime << endl;
    cout << "* Price: " << price << endl;
    cout << "* Type of vehicle: Car" << endl;
    cout << "******************************************" << endl;
}

Teleported::Teleported(Point pt1,double width,double height) {
    float r,g,b;Point p1,p2;
    p=pt1;w=width;h=height;
    srand(time(NULL));
    p1={p.x - w/2,p.y-h/2}; p2={p.x+w/2,p.y+h/2};
    paint(&r,&g,&b);
    sh=new class Rectangle(p1,p2,r,g,b);
}
Teleported::~Teleported() {delete sh;}
void Teleported::draw() {sh->draw();}
    
void Teleported::printin(Point position,int time){
    Teleported::intime=time;
    cout<<"*************Arrival ticket*************"<<endl;
    cout<<"* Arrival time: "<<getintime(time)<<endl;
    cout<<"* Type of vehicle: Teleported "<<endl;
    cout<<"* Empty slot: "<<position.x<<","<<position.y<<endl;
    cout<<"****************************************"<<endl;
}    
    
void Teleported::printout(int time) {
    Teleported::outtime = time;
    int totaltime = Teleported::outtime - Teleported::intime;
    double price = totaltime * Teleported::price;             //different car should have different price standards.
    cout << "*************Departure ticket*************" << endl;
    cout << "* Time spent: " << totaltime << endl;
    cout << "* Price: " << price << endl;
    cout << "* Type of vehicle: Teleported" << endl;
    cout << "******************************************" << endl;
}
    
UFO::UFO(Point pt1, double width, double height, double owidth) {

    float r, g, b; Point p1, p2, p3,p4;
    p=pt1; w=width; h=height; o=owidth;
    p1={p.x,p.y-h/2};
    paint(&r,&g,&b);float static r1=r,g1=g,b1=b;
    sh[0]=new class Semicircle(p1,w/2,r1,g1,b1);
    p1={p.x-w/2+2*o/3,p.y-h/2};p2={p.x-2*o/3,p.y-h/2};p3={p.x-o/3,p.y-h/2-o/2};p4={p.x-w/2+o/3,p.y-h/2-o/2};
    paint(&r,&g,&b);float static r2=r,g2=g,b2=b;
    sh[1]=new class Trapezium(p1,p2,p3,p4,r2,g2,b2);
    p1={p.x+w/2-o*2/3,p.y-h/2};p2={p.x+o*2/3,p.y-h/2};p3={p.x+o/3,p.y-h/2-o/2};p4={p.x+w/2-o/3,p.y-h/2-o/2};
    sh[2]=new class Trapezium(p1,p2,p3,p4,r2,g2,b2);
    p1={p.x-w/4,p.y-h/2+w/2-o/4};p2={p.x-w/2,p.y-h/2+w/2+o/2};
    paint(&r,&g,&b);float static r3=r,g3=g,b3=b;
    sh[3]=new class Line(p1,p2,r3,g3,b3);
    p1={p.x+w/4,p.y-h/2+w/2-o/4};p2={p.x+w/2,p.y-h/2+w/2+o/2};
    sh[4]=new class Line(p1,p2,r3,g3,b3);
}
UFO::~UFO() {for(int i=0;i<=4;i++) delete sh[i];}
void UFO::draw() {for (int i=0;i<=4;i++) sh[i]->draw();}
  
void UFO::printin(Point position,int time){
    UFO::intime=time;
    cout<<"*************Arrival ticket*************"<<endl;
    cout<<"* Arrival time: "<<getintime(time)<<endl;
    cout<<"* Type of vehicle: UFO "<<endl;
    cout<<"* Empty slot: "<<position.x<<","<<position.y<<endl;
    cout<<"****************************************"<<endl;
}    
    
void UFO::printout(int time) {
    UFO::outtime = time;
    int totaltime = UFO::outtime - UFO::intime;
    double price = totaltime * UFO::price;             //different car should have different price standards.
    cout << "*************Departure ticket*************" << endl;
    cout << "* Time spent: " << totaltime << endl;
    cout << "* Price: " << price << endl;
    cout << "* Type of vehicle: UFO" << endl;
    cout << "******************************************" << endl;
}
    
Spacecraft::Spacecraft(Point pt1, double width, double height, double owidth) {
    float r,g,b;Point p1,p2,p3,p4;
    p=pt1;w=width;h=height;o=owidth;
    p1={p.x-w/2+o,p.y-h/4};p2={p.x+w/2-o,p.y+h/4};
    paint(&r,&g,&b);float static r1=r,g1=g,b1=b;
    sh[0]=new class Rectangle(p1,p2,r1,g1,b1);
    p1={p.x+w/2-o,p.y+h/4};p2={p.x+w/2-o,p.y-h/4};p3={p.x+w/2,p.y};
    paint(&r,&g,&b);float static r2=r,g2=g,b2=b;
    sh[1]=new class Triangle(p1,p2,p3,r2,g2,b2);
    p1={p.x,p.y-h/10};p2={p.x+w/8,p.y+h/10};
    paint(&r,&g,&b);float static r3=r,g3=g,b3=b;
    sh[2]=new class Rectangle(p1,p2,r3,g3,b3);
    p1={p.x+w/6,p.y+h/8};p2={p.x+w/5,p.y+h/6};
    paint(&r,&g,&b);float static r4=r,g4=g,b4=b;
    sh[3]=new class Rectangle(p1,p2,r4,g4,b4);
    p1={p.x+w/6,p.y-h/8};p2={p.x+w/5,p.y-h/6};
    sh[4]=new class Rectangle(p1,p2,r4,g4,b4);
    p1={p.x,p.y+h/4};p2={p.x-w/2+o,p.y+h/4};p3={p.x-w/2+o,p.y+h/2};
    paint(&r,&g,&b);float static r5=r,g5=g,b5=b;
    sh[5]=new class Triangle(p1,p2,p3,r5,g5,b5);
    p1={p.x,p.y-h/4};p2={p.x-w/2+o,p.y-h/4};p3={p.x-w/2+o,p.y-h/2};
    sh[6]=new class Triangle(p1,p2,p3,r5,g5,b5);
    p1={p.x-w/2+o,p.y+h/5};p2={p.x-w/2+o,p.y-h/5};p3={p.x-w/2+o/2,p.y-h/4};p4={p.x-w/2+o/2,p.y+h/4};
    paint(&r,&g,&b);float static r6=r,g6=g,b6=b;
    sh[7]=new class Trapezium(p1,p2,p3,p4,r6,g6,b6);

}
Spacecraft::~Spacecraft() {for(int i=0;i<=7;i++) delete sh[i];}
void Spacecraft::draw() {for(int i=0;i<=7;i++) sh[i]->draw();}
  
void Spacecraft::printin(Point position,int time){
    Spacecraft::intime=time;
    cout<<"*************Arrival ticket*************"<<endl;
    cout<<"* Arrival time: "<<getintime(time)<<endl;
    cout<<"* Type of vehicle: Spacecraft "<<endl;
    cout<<"* Empty slot: "<<position.x<<","<<position.y<<endl;
    cout<<"****************************************"<<endl;
}    
    
void Spacecraft::printout(int time) {
    Spacecraft::outtime = time;
    int totaltime = Spacecraft::outtime - Spacecraft::intime;
    double price = totaltime * Spacecraft::price;             //different car should have different price standards.
    cout << "*************Departure ticket*************" << endl;
    cout << "* Time spent: " << totaltime << endl;
    cout << "* Price: " << price << endl;
    cout << "* Type of vehicle: Spacecraft" << endl;
    cout << "******************************************" << endl;
}
