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

class Vehicle{
public:
    virtual void draw()=0;
    virtual void rotate(Point center, double degree)=0;
    void setpos(Point pos);
    void moveln(double *dx,double *dy,double lnx,double lny);
    void moveup(double *dx,double *dy);
    void movedown(double *dx,double *dy);
    void moveleft(double *dx,double *dy);
    void moveright(double *dx,double *dy);
    void zoom(double *width,double *height,double *owidth,double *Radii);
    void rescale(double coefficient);

    virtual void reset()=0;
    virtual void printin(Point position,int time)=0;
    virtual void printout(int time)=0;
    int getintime(int time);
    int getouttime(int time);
    virtual ~Vehicle();
protected:
    Point p; // center position
    double w,h,o,R; // Geometric feature
    double inrot; // rotational status
    int intime,outtime;
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
    void printin(Point position,int time);
    void printout(int time);
    void rotate(Point center, double degree);
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
    void rotate(Point center, double degree);
    void printin(Point position,int time);
    void printout(int time);
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
    void rotate(Point center, double degree);
    void printin(Point position,int time);
    void printout(int time);
private:
    Shape *sh[8];
    int intime,outtime,price;
};
#endif //HWX_FIGURE_H
