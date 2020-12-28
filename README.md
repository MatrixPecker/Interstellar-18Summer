# Interstellar - Group 0E0W
Interstellar Parking Lot for Intro. to Computer & Programming, 18 Summer

**Contributors:**

Gu Xihe <br>
Lou Yukun <br> 
Wang Ziyi <br>
Wu Qinhang <br>

**Version: Final Submission (Aug. 7)**

## File Structure
|--main.cpp

|--Vec.h

|--Vec.cpp

|--shape.h

|--shape.cpp

|--figure.h

|--figure.cpp

|--parkinglot.cpp

|--parkinglot.h

|--Canvas.cpp

|--Canvas.h

|--README.md

|--Changelog.txt

|--CMakeLists.txt

|--IR.jpg

|--p3_part1.cpp

|--parkingarea.h

|--parkingarea.cpp

|--normalvehicle.h

|--normalvehicle.cpp


## To-do List
### General
- ~~Color Table    [GXH]~~
- ~~Engine: Vec, Rotate    [WQH]~~
- ~~First Part of the Parkinglot (the design of a generic parking lot)    [GXH/LYK]~~
- ~~Figure: Parkinglot    [LYK]~~
  - ~~Layer design & fix    [LYK]~~
- ~~Size & Scale fix    [LYK]~~
- ~~Shape: barrier blocking    [GXH]~~
- ~~Shape: bicycle, motorbike, car    [?]~~
- README maintenance    [GXH]
- ~~Rotation engine    [WQH]~~
  - ~~Map for different slots    [WQH]~~
- ~~Route programming    [WQH]~~
### Milestone 1
- ~~Ticket    [WZY]~~
- ~~Price Calculation    [LYK/WZY]~~
- ~~Find an empty slot    [LYK/WZY]~~
### Milestone 2
- ~~Basic shapes    [LYK]~~
- ~~Figure: vehicles    [LYK]~~
- ~~Normal parking lot  [LYK]~~
- ~~Rule of normal parking lot  [GXH]~~
- ~~Placeholder  [WZY]~~
### Final submission
- ~~fix main.c and Canvas    [WQH]~~
- ~~Interface: specify slots and enter command    [WQH]~~
  - ~~"Not available" symbol on the slot    [WZY]~~
### Bonus
- ~~Trajectory recording: simulate the dust tracks    [WQH] [pending]~~
- ~~Motion: moving flag    [WQH]~~
- ~~fix inheritance relationship~~
- ~~clean the code~~
- ~~Motion: teleported (polygon teleporter)    [LYKKK]~~
- ~~Multiple cars entering different slot with corresponding smooth trajectory    [WQH]~~
## General Setup
- Inheritance Relationship

  **(for the image, see IR.jpg in this file holder)**

  All the vehicles inherit from a fundamental class and two kinds of carports inherit from a general carport class.
  The motivation is that all the vehicles have some common functions such as move and print tickets, and so do the carports. Thus, it is more efficient to use inheritance relationship.

- Our interstellar parking lot is designed to be 2 floors, 23 slots in total. All the carports are identical. We consider it to be the size big enough to make full use of all functions and cute enough for the whole process to be clear and concise.
- There are four kinds of vehicles, car, teleported, UFO and spacecraft, each with its standard functions.


## Highlights
- In the interstellar parking lot, the cars have yellow tails behind them when they proceed, which act as the dust.
## Rules of Normal Parking Lot
User has three options, which are Enter 1 to begin the autoshow, Enter 2 to play the game and Enter other numbers to break. Before the game begins, user can choose how many slots he/she wants(the number should between 5 and 100), how many rounds he/she wants(the number should between 1 and 20).  
When the first round begin, the user can let cars come in and choose which round the car will leave. More than one car or no car can come at one round. One round ends when user enters 0. After the car coming in, an arrival ticket will be provided like   
             **Arrival ticket**

* Arrival time: 1
* Type of vehicle: Motorbike
* Empty slot (x,y,floor) : 4,1,1

which includes the arrival time, type of the car and the empty slot the car can stop.
After that, if the user wants the car to leave at the fifth round, an departure ticket will be provided when the fifth round begins, which is shown as   
           **Departure ticket**

* Time spent: 4
* Type of vehicle: Motorbike
* Price: 8

*which includes how long this kind of car was parked and how much it cost.

## Rules of Interstellar Parking Lot
At the beginning, users are allowed to set the slots in the parking lot. It should be an integer larger than or equal to 10 and smaller than or equal to 23. Then, the allowed number of slots will be available and the others will have a cross on them.  
We randomly generate cars, spacecrafts, UFOs and teleported at different time.  
Teleported are put on the slots at the beginning. Others come into the slots one by one. The UFOs are rotating and the spacecrafts are zooming. The cars have flags floating up and down on them.   
After all slots are occupied, the game ends.

## Bonus
- All types of vehicles can enter the parking lot.
- The cars have moving flags on them.
- The teleported have different shapes.
- Every slot can have a vehicle (with corresponding smooth trajectory).
- Car will leave a temporary trace (acting as dust).
