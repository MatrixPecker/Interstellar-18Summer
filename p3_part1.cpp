//
// Created by lykku on 2019/7/29.
//

#include <iomanip>
#include <iostream>
#include "parkingarea.h"
#include "normalvehicle.h"
using namespace std;
int main(){
    Parkingarea park(50);
    Van car1;
    car1.requirelot(1,park);
    if (car1.position!={0,0,0}) car1.leave(8,park);
    Car car2,car3;
    car2.requirelot(8,park);
    car3.requirelot(8,park);
    if (c2.positon!={0,0,0}) car2.leave(10,park);
    if (c3.positon!={0,0,0}) car3.leave(10,park);
    return 0;
}
