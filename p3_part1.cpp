//
// Created by lykku on 2019/7/29.
//

#include <iomanip>
#include <iostream>
#include <time.h>
#include "parkingarea.h"
#include "normalvehicle.h"
using namespace std;
void autoshow(){
    int in=0,out=0;
    Car car1;
    Normalvehicle *vehicle=new Normalvehicle[100];
    Parkingarea park(20);
    int cartype;
    int ran=0;
    srand(time(NULL));
    for (int i=0;i<=100;i++){
        //cout<<"Time:"<<i<<endl;
        ran=rand()%3;
        //cout<<ran<<endl;
        switch (ran) {
            case 0:
                cout<<"No car in or out"<<endl;
                break;
            case 1:
                cartype = rand() % 4;
                //cout<<"cartype"<<cartype<<endl;
                if (cartype == 0) {
                    Van car;
                    vehicle[in] = car;
                    vehicle[in].requirelot(i, park);
                } else if (cartype == 1) {
                    Car car;
                    vehicle[in] = car;
                    vehicle[in].requirelot(i, park);
                } else if (cartype == 2) {
                    Motorbike car;
                    vehicle[in] = car;
                    vehicle[in].requirelot(i, park);
                } else if (cartype == 3) {
                    Bicycle car;
                    vehicle[in] = car;
                    vehicle[in].requirelot(i, park);
                }
                in++;
                break;
            case 2:
                if (in == 0) cout<<"No car"<<endl;
                else {
                    out = rand() % in;
                    //cout<<out<<endl;
                    vehicle[out].leave(i, park);
                    if (in>=2){
                        for (int j = out; j <= in - 2; j++) {
                            vehicle[j] = vehicle[j + 1];
                        }
                    }
                    in--;
                }
                break;
        }
    }
    park.deleteParkingarea();
    delete [] vehicle;
}
int main(){
    autoshow();
    return 0;
}
