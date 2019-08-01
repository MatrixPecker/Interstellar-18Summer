//
// Created by lykku on 2019/7/29。
// Edited by GXH on 2019/8/1.
//

#include <iomanip>
#include <iostream>
#include <time.h>
#include "parkingarea.h"
#include "normalvehicle.h"
using namespace std;
void autoshow(){
    int in=0,out=0;
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

inline void anothercartype(int* cartype){
    cout << "The number is not qualified." << endl;
    cout << "Vehicle entering: " << endl << "(1 for van, 2 for car, 3 for motorbike, 4 for bicycle): " << endl;
    cin >> *cartype;
}

inline void anotherleavetime(int* leavetime){
    cout << "The number is smaller or equal to the current one." << endl;
    cout << "Enter the round number you want the vehicle to leave. " << endl <<
         "(Please make sure that the number is larger than the current round.)" << endl;
    cin >> *leavetime;
}

typedef struct _normalvehicle {
    Normalvehicle vehicle;
    int leavetime = -1;
}normalvehicle;

void interact(){
    int in=0;
    normalvehicle * Vehicle = new ( normalvehicle  [100] );
    Parkingarea park(20);
    int cartype=-1;
    int leavetime=-1;
    cout << endl << "******Welcome to our parking lot!******"<<endl;
    cout << endl << "Our parking lot has 20 slots in total." << endl;
    cout << "There are 10 rounds, and you can decide the vehicles entering at each round." << endl;
    cout << endl << "Press Enter to start the game!" << endl;
    cin.get();
    for (int i=1 ; i<=10 ; i++){
        cout << endl << "******Round " << i << "******" << endl;
        //cars leaving
        for (int j=0 ; j<100 ; j++) {
            if (Vehicle[j].leavetime == i)
                Vehicle[j].vehicle.leave(i, park);
        }
        //cars entering
        cout << "Enter one car each time, you have more than one time each round." << endl;
        cout << "Enter 0 to stop." << endl;
        while (cartype!=0){
            cout << "Vehicle entering: " << endl << "(1 for van, 2 for car, 3 for motorbike, 4 for bicycle): " << endl;
            cin >> cartype;
            while (cartype > 4 || cartype < 0 ) anothercartype(&cartype);
            if (cartype!=0) { //If there is a new vehicle entering
                cout << "Enter the round number you want the vehicle to leave. " << endl <<
                    "(Please make sure the number is larger than the current one.)" << endl;
                cin >> leavetime;
                while (leavetime <= i) anotherleavetime(&leavetime);
                if (cartype==1) {
                    Van car;
                    Vehicle[in].vehicle = car;
                    Vehicle[in].leavetime = leavetime;
                    (Vehicle[in].vehicle).requirelot(i, park);
                    in++;
                } else if (cartype==2) {
                    Car car;
                    Vehicle[in].vehicle = car;
                    Vehicle[in].leavetime = leavetime;
                    (Vehicle[in].vehicle).requirelot(i, park);
                    in++;
                } else if (cartype==3) {
                    Motorbike car;
                    Vehicle[in].vehicle = car;
                    Vehicle[in].leavetime = leavetime;
                    (Vehicle[in].vehicle).requirelot(i, park);
                    in++;
                } else if (cartype==4){
                    Bicycle car;
                    Vehicle[in].vehicle = car;
                    Vehicle[in].leavetime = leavetime;
                    (Vehicle[in].vehicle).requirelot(i, park);
                    in++;
                }
            }
        }
        cartype = -1;
    }
    cout << endl <<"***Good job! Hope you enjoyed it!***" << endl;
    cout << endl << "**********End of the game**********" << endl;
    park.deleteParkingarea();
    delete [] Vehicle;
}

int main(){
    int i;
    cout << endl << "Enter 1 to begin the autoshow." << endl
        << "Enter 2 to play the game." << endl
        << "Enter other numbers to break." << endl;

    cin >> i;
    cin.get();
    switch (i){
        case 1:
            autoshow(); break;
        case 2:
            interact(); break;
    }
    return 0;
}
