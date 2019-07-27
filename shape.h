//
// Created by lykku on 2019/7/24.
//

#ifndef HWX_SHAPE_H
#define HWX_SHAPE_H
#include <windows.h>
#include <GL/freeglut.h>
#include "Vec.h"
//typedef struct _Point { double x,y; } Point;
// I move this definition to Vec.h
class Shape {
public:
    virtual void draw() = 0;
    virtual ~Shape();
protected:
    float r, g, b;
};
class Circle:public Shape{
public:
    Circle(Point pt1={-0.5,-0.5}, double R=0.5,float r=0, float g=0, float b=0);
    void draw();

private:
    Point p1;
    double R;
};
class Semicircle:public Shape{
public:
    Semicircle(Point pt1={-0.5,-0.5}, double R=0.5,float r=0, float g=0, float b=0);
    void draw();

private:
    Point p1;
    double R;
};
class Line:public Shape{
public:
    Line(Point pt1={-0.5,-0.5},Point pt2={0.5,0.5},float r=0, float g=0, float b=0);
    void draw();

private:
    Point p1,p2;
};
class Rectangle : public Shape {
public:
    Rectangle(Point pt1={-.5,-.5}, Point pt2={.5,.5},
                  float r=0, float g=0, float b=0);
    void draw();
private: Point p1,p2;
};
class Triangle : public Shape {
public:
    Triangle(Point pt1={-.5,-.5}, Point pt2={.5,-.5},
                 Point pt3={0,.5}, float r=0, float g=0, float b=0);
    void draw();
private: Point p1,p2,p3;
};
class Parallelogram:public Shape{
public:
    Parallelogram(Point pt1={-0.5,-0.5},Point pt2={0.5,-0.5},
            Point pt3={1,0.5},Point pt4={0,0.5}, float r=0, float g=0, float b=0);
    void draw();

private:
    Point p1,p2,p3,p4;
};
class Trapezium:public Shape{
public:
    Trapezium(Point pt1={-0.25,0.5},Point pt2={0.25,0.5},
            Point pt3={0.5,-0.5},Point pt4={-0.5,-0.5}, float r=0, float g=0, float b=0);
    void draw();

private:
    Point p1,p2,p3,p4;
};



#endif //HWX_SHAPE_H
