//
// Created by lykku on 2019/7/29.
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

inline void anotherparknum(int* parknum){
    cout << "Please enter a number qualified." << endl;
    cout << "For the game, how many slots do you want the parking lot to have?" << endl;
    cout << "(Enter an integer between 5 to 100.)" << endl;
    cin >> *parknum;
}

inline void anotherroundnum(int* roundnum){
    cout << "Please enter a number qualified." << endl;
    cout << "How many rounds do you want to have?" << endl;
    cout << "(Enter an integer between 1 and 20.)" << endl;
    cin >> *roundnum;
}

typedef struct _normalvehicle {
    Normalvehicle vehicle;
    int leavetime = -1;
}normalvehicle;

void interact(){
    int in=0;
    int cartype=-1;
    int leavetime=-1;
    cout << endl << "******Welcome to our parking lot!******"<<endl;

    //Set the slots number
    int parknum=0;
    cout << endl << "For the game, how many slots do you want the parking lot to have?" << endl;
    cout << "(Enter an integer between 5 to 100.)" << endl;
    cin >> parknum;
    while ( parknum<5 || parknum>100 ) anotherparknum(&parknum);
    Parkingarea park(parknum);

    //Set the round number
    int roundnum=0;
    cout << "How many rounds do you want to have?" << endl;
    cout << "(Enter an integer between 1 and 20.)" << endl;
    cin >> roundnum;
    while ( roundnum<1 || roundnum>20 ) anotherroundnum(&roundnum);
    cin.get();
    normalvehicle * Vehicle = new ( normalvehicle  [200] );

    //Starts the game
    cout << endl <<"For each round, you may decide the vehicles entering and when they leave." << endl;
    cout << "Press Enter to start the game!" << endl;
    cin.get();
    for (int i=1 ; i<=roundnum ; i++){
        cout << endl << "******Round " << i << "/" << roundnum << "******" << endl;
        //cars leaving
        for (int j=0 ; j<200 ; j++) {
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
                }else if (cartype==4){
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
    switch (i){
        case 1:
            autoshow(); break;
        case 2:
            interact(); break;
    }
    return 0;
}
