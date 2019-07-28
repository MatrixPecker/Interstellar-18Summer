//
// Created by lykku on 2019/7/24.
//

#include "shape.h"

#include <math.h>
double static PI=3.1415926535;
int static n=360;
Shape::~Shape(){}
Circle::Circle(Point pt1, double Radii,float red, float green, float blue) {
    p1=pt1;r=red;g=green;b=blue;R=Radii;
}
void Circle::draw() {
    glColor3f(r,g,b);glBegin(GL_POLYGON);
    for(int i=0;i<n;i++)
    {
        glVertex2f(p1.x+R*cos(2*PI*i/n),p1.y+R*sin(2*PI*i/n));   //定义顶点
    }
    glEnd();
}
Semicircle::Semicircle(Point pt1, double Radii,float red, float green, float blue) {
    p1=pt1;r=red;g=green;b=blue;R=Radii;
}
void Semicircle::draw() {
    glColor3f(r,g,b);glBegin(GL_POLYGON);
    for(int i=0;i<n;i++)
    {
        glVertex2f(p1.x+R*cos(PI*i/n),p1.y+R*sin(PI*i/n));   //定义顶点
    }
    glEnd();
}
Line::Line(Point pt1, Point pt2, float red, float green, float blue) {
    p1=pt1;p2=pt2;r=red;g=green; b = blue;
}
void Line::draw() {
    glColor3f(r,g,b);glBegin(GL_LINE_LOOP);
    glVertex2f(p1.x,p1.y);glVertex2f(p2.x,p2.y);glEnd();
}
Rectangle::Rectangle(Point pt1, Point pt2,float red, float green, float blue) {
    p1=pt1; p2=pt2; r=red; g=green; b=blue;
}
void Rectangle::draw() {
    glColor3f(r, g, b); glBegin(GL_QUADS);
    glVertex2f(p1.x, p1.y); glVertex2f(p2.x, p1.y);
    glVertex2f(p2.x, p2.y); glVertex2f(p1.x, p2.y); glEnd();
}
Triangle::Triangle(Point pt1, Point pt2, Point pt3,float red, float green, float blue) {
    p1=pt1; p2=pt2; p3=pt3; r=red; g=green; b=blue;
}
void Triangle::draw() {
    glColor3f(r, g, b); glBegin(GL_TRIANGLE_STRIP);
    glVertex2f(p1.x, p1.y); glVertex2f(p2.x, p2.y); glVertex2f(p3.x, p3.y);
    glEnd();
}
Parallelogram::Parallelogram(Point pt1, Point pt2, Point pt3, Point pt4, float red, float green, float blue) {
    p1=pt1;p1=pt2;p3=pt3;p4=pt4;r=red;g=green;b=blue;
}
void Parallelogram::draw() {
    glColor3f(r, g, b); glBegin(GL_QUADS);
    glVertex2f(p1.x, p1.y); glVertex2f(p2.x, p2.y); glVertex2f(p3.x, p3.y);glVertex2f(p4.x,p4.y);
    glEnd();
}
Trapezium::Trapezium(Point pt1, Point pt2, Point pt3, Point pt4, float red, float green, float blue) {
    p1=pt1;p2=pt2;p3=pt3;p4=pt4;r=red;g=green;b=blue;
}
void Trapezium::draw() {
    glColor3f(r, g, b); glBegin(GL_QUADS);
    glVertex2f(p1.x, p1.y); glVertex2f(p2.x, p2.y); glVertex2f(p3.x, p3.y);glVertex2f(p4.x,p4.y);
    glEnd();
}