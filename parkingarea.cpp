//
// Created by lykku on 2019/7/29.
//

#include <cstring>
#include "parkingarea.h"

Parkingarea::Parkingarea(int n) {
    slots=n;
    for (int i=0;i<=slots-1;i++){
        lott[i]=true;
        if (i % 4==0) lottt[i]="Car";
        else if (i%4==1) lottt[i]="Van";
        else if (i%4==2) lottt[i]="Bicycle";
        else if (i%4==3) lottt[i]="Motorbike";
        if (i<=(slots/2)) {
            lot[i].floor=1;
            if (i<=(slots/4)) lot[i].y=1;
            else lot[i].y=2;
        }
        else {
            lot[i].floor=2;
            if (i<=(3*slots/4)) lot[i].y=1;
            else lot[i].y=2;
        }
        lot[i].x=(i%(slots/4))+1;
    }
}
Point Parkingarea::offerlot(string type) {
    for (int i=0;i<=slots;i++){
        if (lott[i]==true && lottt[i]==type){
            lott[i]=false;
            return lot[i];
        }
    }
    return {0,0,0};
}
void Parkingarea::moveout(Point p1) {
    for (int i=0;i<=slots;i++){
        if (lot[i].x==p1.x && lot[i].y==p1.y && lot[i].floor==p1.floor){
            lott[i]=true;
            break;
        }
    }
}

void Parkingarea::deleteParkingarea() {
    delete []lot;
    delete []lott;
    delete []lottt;
}
