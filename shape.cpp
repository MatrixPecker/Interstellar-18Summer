//
// Created by lykku on 2019/7/24.
//

#include "shape.h"

//double static PI=3.1415926535;
int static n=360;
Shape::~Shape(){}
Circle::Circle(Point pt1, double Radii,float red, float green, float blue) {
    p1=pt1;r=red;g=green;b=blue;R=Radii;
}
void Circle::reset(Point pt1, double Radii){
    p1=pt1;R=Radii;
}
void Circle::rotate(Point center, double degree){
    rotateVec(&p1, center, degree);
}
void Circle::draw() {
    glColor3f(r,g,b);glBegin(GL_POLYGON);
    for(int i=0;i<n;i++)
    {
//        glVertex2f(p1.x+R*cos(2*PI*i/n),p1.y+R*sin(2*PI*i/n));
        glVertex2f(p1.x+R*cos(d2r(i)),p1.y+R*sin(d2r(i)));
    }
    glEnd();
}
Semicircle::Semicircle(Point pt1, double Radii,float red, float green, float blue) {
    p1=pt1;r=red;g=green;b=blue;R=Radii;cir=0;
}
void Semicircle::reset(Point pt1, double Radii) {
    p1=pt1;R=Radii;cir=0;
}
void Semicircle::rotate(Point center, double degree){
    rotateVec(&p1, center, degree);
    cir=degree;
    // new feature needed: add property "DEGREE" in Semicircle
}
void Semicircle::draw() {
    glColor3f(r,g,b);glBegin(GL_POLYGON);
    for(int i=0;i<n;i++)
    {
//        glVertex2f(p1.x+R*cos(PI*i/n),p1.y+R*sin(PI*i/n));
        glVertex2f(p1.x+R*cos(0.5*d2r(i+2*cir)),p1.y+R*sin(0.5*d2r(i+2*cir)));
    }
    glEnd();
}
Line::Line(Point pt1, Point pt2, float red, float green, float blue) {
    p1=pt1;p2=pt2;r=red;g=green; b = blue;
}
void Line::reset(Point pt1, Point pt2){
    p1=pt1;p2=pt2;
}
void Line::rotate(Point center, double degree){
    rotateVec(&p1, center, degree);
    rotateVec(&p2, center, degree);
}
void Line::draw() {
    glColor3f(r,g,b);glBegin(GL_LINE_LOOP);
    glVertex2f(p1.x,p1.y);glVertex2f(p2.x,p2.y);glEnd();
}
Rectangle::Rectangle(Point pt1, Point pt2,float red, float green, float blue) {
    p1=pt1; p3=pt2; r=red; g=green; b=blue; p2={p3.x,p1.y}; p4={p1.x,p3.y};
}
void Rectangle::reset(Point pt1, Point pt2){
    p1=pt1; p3=pt2; p2={p3.x,p1.y}; p4={p1.x,p3.y};
}
void Rectangle::rotate(Point center, double degree){
    rotateVec(&p1, center, degree);
    rotateVec(&p2, center, degree);
    rotateVec(&p3, center, degree);
    rotateVec(&p4, center, degree);
}
void Rectangle::draw() {
    glColor3f(r, g, b); glBegin(GL_QUADS);
    glVertex2f(p1.x, p1.y); glVertex2f(p2.x, p2.y);
    glVertex2f(p3.x, p3.y); glVertex2f(p4.x, p4.y); glEnd();
}
Triangle::Triangle(Point pt1, Point pt2, Point pt3,float red, float green, float blue) {
    p1=pt1; p2=pt2; p3=pt3; r=red; g=green; b=blue;
}
void Triangle::reset(Point pt1, Point pt2, Point pt3){
    p1=pt1; p2=pt2; p3=pt3;
}
void Triangle::rotate(Point center, double degree){
    rotateVec(&p1, center, degree);
    rotateVec(&p2, center, degree);
    rotateVec(&p3, center, degree);
}
void Triangle::draw() {
    glColor3f(r, g, b); glBegin(GL_TRIANGLE_STRIP);
    glVertex2f(p1.x, p1.y); glVertex2f(p2.x, p2.y); glVertex2f(p3.x, p3.y);
    glEnd();
}
Parallelogram::Parallelogram(Point pt1, Point pt2, Point pt3, Point pt4, float red, float green, float blue) {
    p1=pt1;p1=pt2;p3=pt3;p4=pt4;r=red;g=green;b=blue;
}
void Parallelogram::reset(Point pt1, Point pt2, Point pt3, Point pt4) {
    p1=pt1;p1=pt2;p3=pt3;p4=pt4;
}
void Parallelogram::rotate(Point center, double degree){
    rotateVec(&p1, center, degree);
    rotateVec(&p2, center, degree);
    rotateVec(&p3, center, degree);
    rotateVec(&p4, center, degree);
}
void Parallelogram::draw() {
    glColor3f(r, g, b); glBegin(GL_QUADS);
    glVertex2f(p1.x, p1.y); glVertex2f(p2.x, p2.y); glVertex2f(p3.x, p3.y);glVertex2f(p4.x,p4.y);
    glEnd();
}
Trapezium::Trapezium(Point pt1, Point pt2, Point pt3, Point pt4, float red, float green, float blue) {
    p1=pt1;p2=pt2;p3=pt3;p4=pt4;r=red;g=green;b=blue;
}
void Trapezium::reset(Point pt1, Point pt2, Point pt3, Point pt4){
    p1=pt1;p2=pt2;p3=pt3;p4=pt4;
}
void Trapezium::rotate(Point center, double degree){
    rotateVec(&p1, center, degree);
    rotateVec(&p2, center, degree);
    rotateVec(&p3, center, degree);
    rotateVec(&p4, center, degree);
}
void Trapezium::draw() {
    glColor3f(r, g, b); glBegin(GL_QUADS);
    glVertex2f(p1.x, p1.y); glVertex2f(p2.x, p2.y); glVertex2f(p3.x, p3.y);glVertex2f(p4.x,p4.y);
    glEnd();
}