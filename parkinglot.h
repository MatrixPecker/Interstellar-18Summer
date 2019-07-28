//
// Created by lykku on 2019/7/26.
//

#ifndef HWX_PARKINGLOT_H
#define HWX_PARKINGLOT_H

#include "shape.h"
class Parkinglot{
public:
    void parkdraw();
    Parkinglot();
    Point locate();
    void leave(Point vehicle);
private:
    Shape *sh[70];
    bool plate[20];
    Point location[20];
};
#endif //HWX_PARKINGLOT_H
