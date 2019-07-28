//
// Created by William Wu on 2019/7/27.
//

#include "Vec.h"
double d2r(double a){
    return a * PI_V / 180.0;
}
double r2d(double a){
    return a * 180.0 / PI_V;
}
void printVec(Point p){ // only for debug
    std::cout<<"<"<<p.x<<", "<<p.y<<">"<<std::endl;
}
void moveVec(Point *p, Point dir){
    p->x += dir.x;
    p->y += dir.y;
}
void rotateVec(Point *p, Point center, double degree){
    /*p rotates around Center for d degrees */
    double tmpx1=p->x-center.x,tmpy1=p->y-center.y;
    double tmpx2=tmpx1, tmpy2=tmpy1;
    tmpx2 = tmpx1*cos(d2r(degree)) - tmpy1*sin(d2r(degree));
    tmpy2 = tmpx1*sin(d2r(degree)) + tmpy1*cos(d2r(degree));
    p->x=tmpx2+center.x; p->y=tmpy2+center.y;
}
void zoomVec(Point *p, double rate){
    p->x *= rate;
    p->y *= rate;
}