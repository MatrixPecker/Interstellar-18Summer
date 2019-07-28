//
// Created by William Wu on 2019/7/27.
//

#ifndef P3_G8_VEC_H
#define P3_G8_VEC_H

#include <iostream>
#include <cmath>
#define PI_V  3.14159265358979
typedef struct _Point { double x,y; } Point;

double d2r(double a); // degree to rad
double r2d(double a); // rad  to degree
void printVec(Point p); // only for debug
void moveVec(Point *p, Point dir);
void rotateVec(Point *p, Point center, double degree);
void zoomVec(Point *p, double rate);

#endif //P3_G8_VEC_H
