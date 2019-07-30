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
    cout << "*************Arrival ticket*************" << endl;
    cout << "* Arrival time: " << intime << endl;
    cout << "* Type of vehicle: " << type << endl;
    cout << "* Empty slot (x,y,floor) : " << position.x << ',' << position.y << ',' << position.floor << endl;
    cout << "****************************************" << endl;
}
void Normalvehicle::printout() {
    cout << "*************Departure ticket*************" << endl;
    cout << "* Time spent: " << outtime-intime << endl;
    cout << "* Type of vehicle: " <<type<< endl;
    cout << "* Price: "<<(outtime-intime)*money<<endl;
    cout << "******************************************" << endl;
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
