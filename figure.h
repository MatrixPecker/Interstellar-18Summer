//
// Created by lykku on 2019/7/22.
//

#ifndef HWX_FIGURE_H
#define HWX_FIGURE_H
#include <windows.h>
#include <GL/freeglut.h>
#include "Vec.h"
#include "shape.h"

class Vehicle{
public:
    virtual void draw()=0;
    virtual void rotate(Point center, double degree)=0;
    void moveup(double *dx,double *dy);
    void movedown(double *dx,double *dy);
    void moveleft(double *dx,double *dy);
    void moveright(double *dx,double *dy);
    void moveln(double *dx,double *dy,double lnx,double lny);
    void zoom(double *width,double *height,double *owidth,double *Radii);
protected:
    Point p;
    double w,h,o,R;
    void zoomout(double *width,double *height,double *owidth,double *Radii);
    void zoomin(double *width,double *height,double *owidth,double *Radii);
    void paint(float *r, float *g, float *b);
};
class Home: public Vehicle {
public:
    Home(Point pt1={0,-.25}, double width=1,
         double height=1.3, double owidth=.175,double Radii=0.4);
    ~Home();
    void draw();
    void rotate(Point center, double degree);
private:
    Shape *sh[6];
};

class Car:public Vehicle{
public:
    Car(Point pt1={0,-.25}, double width=1,
         double height=1.3, double owidth=.175,double Radii=0.1);
    ~Car();
    void draw();
    void rotate(Point center, double degree);
    void Crotate(double degree); // rotate around the center of this vehicle.
private:
    Shape *sh[4];
};
class Teleported:public Vehicle{
public:
    Teleported(Point pt1={0,0},double width=1,double height=0.5);
    ~Teleported();
    void draw();
    void rotate(Point center, double degree);
private:
    Shape *sh;
};
class UFO:public Vehicle{
public:
    UFO(Point pt1={0,0},double width=1,double height=0.5,double owidth=0.5);
    ~UFO();
    void draw();
    void rotate(Point center, double degree);
private:
    Shape *sh[5];
};

class Spacecraft:public Vehicle{
public:
    Spacecraft(Point pt1={0,0},double width=1,double height=0.5,double owidth=0.5);
    ~Spacecraft();
    void draw();
    void rotate(Point center, double degree);
private:
    Shape *sh[8];
};
#endif //HWX_FIGURE_H
