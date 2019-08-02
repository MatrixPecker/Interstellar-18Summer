//
// Created by William Wu on 2019/8/2.
//

#ifndef P3_G8_CANVAS_H
#define P3_G8_CANVAS_H

#include "parkinglot.h"
#include "figure.h"
#include "Vec.h"

typedef struct _Data{
    int slotnum; // 23
    bool is_occupied[40];
    Point CENTER;
    Point INITCENTER;
    double CENTRAL_LOWER_Y;
    double CENTRAL_UPPER_Y;
    double CENTRAL_LEFT_X;
    double CENTRAL_RIGHT_X;

    double LNG_IN_1;
    Point LNG_IN_A1;
    double LNG_IN_2;
    double LNG_IN_3;
    Point LNG_IN_A3;
    double LNG_IN_4;
    Point LNG_IN_A4;
    double LNG_IN_5;
    double LNG_IN_6;
    Point LNG_IN_A6;
    double LNG_IN_7;

//    double SLNG_SEC2[5]={0.3,0.5,0.7,0.9,1.1};
//    Point SLNG_SEC2A[5]={{-0.7,-0.1},{-0.7,0.1},{-0.7,0.3},{-0.7,0.5},{-0.7,0.7}};
    double SLNG_SEC3[5];
    Point SLNG_SEC3A[5];
    double SLNG_SEC4[3];
    Point SLNG_SEC4A[3];
    double SLNG_SEC5[5];
    Point SLNG_SEC5A[5];
    double SLNG_SEC6[5];
    Point SLNG_SEC6A[5];

}Data;

class Canvas {
private:
    Parkinglot park;
    Vehicle *v[50];
    int vnum;
    Data coor;
public:
    Canvas();
    void draw();
    void change(int timenow);
    ~Canvas();
};


#endif //P3_G8_CANVAS_H
