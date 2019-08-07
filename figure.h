//
// Created by lykku on 2019/7/22.
//

#ifndef HWX_FIGURE_H
#define HWX_FIGURE_H

#ifdef __APPLE__
#include <GLUT/glut.h>
#elif _WIN32
#include <windows.h>
#include <GL/freeglut.h>
#else
#include <GL/freeglut.h>
#endif

#include "Vec.h"
#include "shape.h"
#define LOT_WAITING -1
#define LOT_IN 0
#define LOT_INWAITING 1
#define LOT_OUT 2
#define TYPE_CAR 10
#define TYPE_UFO 11
#define TYPE_SPACECRAFT 12
#define TYPE_TELEPORTED 13

class Vehicle{
public:
/* Dynamic way of controlling figures (static figures) */
    virtual void draw()=0;
    virtual void supermove(double dx, double dy)=0;
    virtual void rotate(Point center, double degree)=0;
    virtual void Crotate(double degree)=0;
    void rescale(double coefficient);
/* Traditional way of controlling figures (set x/y/rot, reset, draw) */
    virtual void reset()=0;
    void setpos(Point pos);

/*Posotion control*/
    int getintime();
    int getouttime();
    void setintime(int time);
    void setouttime(int time);
    int getassignedslot();
    void setassignedslot(int slot);
    int getstatus();
    void setstatus(int s);
    void settype(int t);
    int gettype();
/*Others*/
    Vehicle();
    virtual ~Vehicle();
protected:
    Point p; // center position
    double w,h,o,R; // Geometric feature
    double inrot; // rotational status
    int intime,outtime;
    int assignedslot;
    int status;
    int vtype;
    void paint(float *r, float *g, float *b);
};

class Car:public Vehicle{
public:
    Car(Point pt1={0,0}, double width=0.15,
        double height=0.11, double owidth=0.02,double Radii=0.02);
    ~Car();
    void reset();
    void draw();
    void magicflag();
    void supermove(double dx, double dy);
    void rotate(Point center, double degree);
    void Crotate(double degree); // rotate around the center of this vehicle.
private:
    Shape *sh[6];
    int intime,outtime,price; // repeated definition here. fix that later.
    double flaglng;
    Point tc;  // trace position
    double acx,acy;
    int tcflag;
    int anflag;
};
class Teleported:public Vehicle{
public:
    Teleported(Point pt1={0,0},double width=0.15,double height=0.11);
    ~Teleported();
    void reset();
    void draw();
    void supermove(double dx, double dy);
    void rotate(Point center, double degree);
    void Crotate(double degree);
    void magic();
private:
    Shape *sh;
    int magictime;
    int intime,outtime,price;
};
class UFO:public Vehicle{
public:
    UFO(Point pt1={0,0},double width=0.12,double height=0.09,double owidth=0.015);
    ~UFO();
    void reset();
    void draw();
    void supermove(double dx, double dy);
    void rotate(Point center, double degree);
    void Crotate(double degree);
    void debugg(); // only for debug
private:
    Shape *sh[5];
    int intime,outtime,price;
};

class Spacecraft:public Vehicle{
public:
    Spacecraft(Point pt1={0,0},double width=0.15,double height=0.11,double owidth=0.02);
    ~Spacecraft();
    void reset();
    void autorescale();
    void draw();
    void supermove(double dx, double dy);
    void rotate(Point center, double degree);
    void Crotate(double degree);
private:
    Shape *sh[8];
    int intime,outtime,price;
};
class Occupy{
private:
    Point p;
    Shape *oc[2];
public:
    Occupy(Point pt);
    ~Occupy();
    void draw();
};
#endif //HWX_FIGURE_H
