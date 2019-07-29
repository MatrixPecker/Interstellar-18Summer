//
// Created by lykku on 2019/7/29.
//

#include "normalvehicle.h"
using namespace std;

#include <iostream>
void Normalvehicle::requirelot(int time,Parkingarea park) {
    intime=time;
    Point p=park.offerlot(type);
    position=p;
    printin();
}
void Normalvehicle::leave(int time,Parkingarea park) {
    outtime=time;
    park.moveout(position);
    printout();
}
void Normalvehicle::printin() {
    cout<<intime<<endl<<position.x<<' '<<position.y<<' '<<position.floor<<endl;
}
void Normalvehicle::printout() {
    cout<<(outtime-intime)*money<<endl;
}
Car::Car() {
    type="Car";
    money=3;
}
Van::Van() {
    type="Van";money=4;
}
Bicycle::Bicycle() {
    type="Bicycle";money=1;
}
Motorbike::Motorbike() {
    type="Motorbike";money=2;
}
