//
// Created by William Wu on 2019/8/2.
//

#ifndef P3_G8_CANVAS_H
#define P3_G8_CANVAS_H

#include "parkinglot.h"
#include "figure.h"
#include "Vec.h"
#include <cmath>

typedef struct _Cdata{
    int slotnum; // 23
    bool is_occupied[40];
    Point CENTER;
    Point INITCENTER;
    double CENTRAL_LOWER_Y;
    double CENTRAL_UPPER_Y;
    double CENTRAL_LEFT_X;
    double CENTRAL_RIGHT_X;
    double backwardslng[23];

    Point LNG_IN_0; // before the bar
    Point LNG_IN_1;
    Point LNG_IN_A1;
    Point LNG_IN_2;
    Point LNG_IN_3;
    Point LNG_IN_A3;
    Point LNG_IN_4;
    Point LNG_IN_A4;
    Point LNG_IN_5;
    Point LNG_IN_6;
    Point LNG_IN_A6;
    Point LNG_IN_7;

    double SLNG_SEC2[5];//={0.3,0.5,0.7,0.9,1.1};
    Point SLNG_SEC2A[5];//={{-0.7,-0.1},{-0.7,0.1},{-0.7,0.3},{-0.7,0.5},{-0.7,0.7}};
    double SLNG_SEC3[5];
    Point SLNG_SEC3A[5];
    double SLNG_SEC4[3];
    Point SLNG_SEC4A[3];
    double SLNG_SEC5[5];
    Point SLNG_SEC5A[5];
    double SLNG_SEC6[5];
    Point SLNG_SEC6A[5];

    // If time permitted, come back and optimize that.
    int D_IN_SEC2[6];
    int D_IN_SEC3[7];
    int D_IN_SEC4[9];
    int D_IN_SEC5[11];
    int D_IN_SEC6[12];

    int D_OUT_SEC2[11];
    int D_OUT_SEC3[10];
    int D_OUT_SEC4[8];
    int D_OUT_SEC5[6];
    int D_OUT_SEC6[5];

}Cdata;

typedef struct _Vdata{
    // add sth.
}Vdata;
class Canvas {
private:
    Parkinglot park;
    Vehicle *v[50];
    int vnum; // total number of active vehicles
    Cdata *c; // coordinate map
    int timenow;
    double linearstep;
    double angularstep;
    void parkIN(int k);
    void parkOUT(int k);
public:
    Canvas();
    void draw();
    void change();
    void gettime(int t);
    ~Canvas();
};

#endif //P3_G8_CANVAS_H