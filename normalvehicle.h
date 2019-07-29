//
// Created by lykku on 2019/7/29.
//

#ifndef HWX_NORMALVEHICLE_H
#define HWX_NORMALVEHICLE_H
#include "parkingarea.h"
#include <string>
using namespace std;
class Normalvehicle{
public:
    void requirelot(int time,Parkingarea park);
    //~Normalvehicle();
    void leave(int time,Parkingarea park);

protected:
    void printin();
    void printout();
    string type;
    int intime,outtime;
    int money;
    Point position;
};
class Car:public Normalvehicle{
public:
    Car();
    //~Car();

};
class Van:public Normalvehicle{
public:
    Van();
    //~Van();

};
class Bicycle:public Normalvehicle{
public:
    Bicycle();
    //~Bicycle();

};
class Motorbike:public Normalvehicle{
public:
    Motorbike();
    //~Motorbike();

};
#endif //HWX_NORMALVEHICLE_H
