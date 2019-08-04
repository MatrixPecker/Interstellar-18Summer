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
    double getinrot(); // get the inner rotational angle
    void setinrot(double a); // set the inner rotational angle
    void changeinrot(double a); // change the inner rotational angle
    void moveln(double *dx,double *dy,double lnx,double lny);
    void moveup(double *dx,double *dy);
    void movedown(double *dx,double *dy);
    void moveleft(double *dx,double *dy);
    void moveright(double *dx,double *dy);
    void zoom(double *width,double *height,double *owidth,double *Radii);
/*Posotion control*/
    virtual void printin(Point position,int time)=0;
    virtual void printout(int time)=0;
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
/*Debug*/
    Point getcenter();
protected:
    Point p; // center position
    double w,h,o,R; // Geometric feature
    double inrot; // rotational status
    int intime,outtime;
    int assignedslot;
    int status;
    int vtype;
    void zoomout(double *width,double *height,double *owidth,double *Radii);
    void zoomin(double *width,double *height,double *owidth,double *Radii);
    void paint(float *r, float *g, float *b);
};

class Car:public Vehicle{
public:
    Car(Point pt1={0,-.25}, double width=1,
         double height=1.3, double owidth=.175,double Radii=0.1);
    ~Car();
    void reset();
    void draw();
    void supermove(double dx, double dy);
    void rotate(Point center, double degree);
    void Crotate(double degree); // rotate around the center of this vehicle.
    void printin(Point position,int time);
    void printout(int time);
private:
    Shape *sh[4];
    int intime,outtime,price; // repeated definition here. fix that later.
};
class Teleported:public Vehicle{
public:
    Teleported(Point pt1={0,0},double width=1,double height=0.5);
    ~Teleported();
    void reset();
    void draw();
    void supermove(double dx, double dy);
    void printin(Point position,int time);
    void printout(int time);
    void rotate(Point center, double degree);
    void Crotate(double degree);
private:
    Shape *sh;
    int intime,outtime,price;
};
class UFO:public Vehicle{
public:
    UFO(Point pt1={0,0},double width=1,double height=0.5,double owidth=0.5);
    ~UFO();
    void reset();
    void draw();
    void supermove(double dx, double dy);
    void rotate(Point center, double degree);
    void Crotate(double degree);
    void printin(Point position,int time);
    void printout(int time);
    void debugg();
private:
    Shape *sh[5];
    int intime,outtime,price;
};

class Spacecraft:public Vehicle{
public:
    Spacecraft(Point pt1={0,0},double width=1,double height=0.5,double owidth=0.5);
    ~Spacecraft();
    void reset();
    void draw();
    void supermove(double dx, double dy);
    void rotate(Point center, double degree);
    void Crotate(double degree);
    void printin(Point position,int time);
    void printout(int time);
private:
    Shape *sh[8];
    int intime,outtime,price;
};
#endif //HWX_FIGURE_H
