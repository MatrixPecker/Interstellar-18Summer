# Interstellar - Group 0E0W
Interstellar Parking Lot for Vg101, 18 Summer

**Contributors:**

Gu Xihe    518370910093
  
Lou Yukun  518021910263
  
Wang Ziyi  518370910073
  
Wu Qinhang 518370910041

**Version: Final Submission (Aug. 6)**

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

|--p3_part1.cpp

|--parkingarea.h

|--parkingarea.cpp

|--normalvehicle.h

|--normalvehicle.cpp


## To-do List
### General
- ~~Color Table    [GXH]~~
- ~~Engine: Vec, Rotate    [WQH]~~
- First Part of the Parkinglot (the design of a generic parking lot)    [GXH/LYK]
- ~~Figure: Parkinglot    [LYK]~~
  - ~~Layer design & fix    [LYK]~~
- ~~Size & Scale fix    [?]~~
- ~~Shape: barrier blocking    [?]~~
- ~~Shape: bicycle, motorbike, car    [?]~~
- README maintenance    [GXH]
- ~~Rotation engine    [WQH]~~
  - ~~Map for different slots    [WQH]~~
- ~~Route programming    [LYK/WQH]~~
### Milestone 1
- ~~Ticket    [WZY]~~
- ~~Price Calculation    [WZY]~~
- Find an empty slot    [?]
### Milestone 2
- ~~Basic shapes    [LYK]~~
- ~~Figure: vehicles    [LYK]~~
- ~~Normal parking lot  [LYK]~~
- ~~Rule of normal parking lot  [GXH]~~
- Placeholder  [WZY]
### Final submission
- fix main.c and Canvas    [WQH]
- Interface: specify slots and enter command    [?]
  - "Not available" symbol on the slot    [?]
### Bonus
- Trajectory recording    [WQH] [pending]
  - simulate the dust tracks; implemented with queue
- ~~Motion: moving flag    [WQH]~~
- fix inheritance relationship
- clean the code
- ~~Motion: teleported (polygon teleporter)    [LYKKK]~~
- Advanced user interface
  
### Final Checklist
- Make Vec class immutable
- Draw the class inheritance relationship
- correspond new with delete; check memory leak (Linux)
- refine README

## General setup
- Inheritance Relationship
![Inheritance Relationship:](https://github.com/MatrixPecker/Interstellar-18Summer/blob/master/IR.jpg)
All the vehicles inherit from a fundamental class and two kinds of carports inherit from a general carport class.
The motivation is that all the vehicles have some common functions such as move and print tickets, and so do the carports. Thus, it is more efficient to use inheritance relationship.
- Our interstellar parking lot is designed to be 2 floors, 20 slots in total. All the carports are identical. We consider it to be the size big enough to make full use of all functions and cute enough for the whole process to be clear and concise.
- There are four kinds of vehicles, car, teleported, UFO and spacecraft, each with its standard functions.


## Highlights
- Color matching for every car

## Rule of normal parking lot
User has three options, which are Enter 1 to begin the autoshow, Enter 2 to play the game and Enter other numbers to break.
Before the game begining, user can choose how many slots he/she wants(the number should between 5 and 100), how many rounds he/she wants(the number should between 1 and 20).
When the first round begin, the user can let cars come in and choose which round the car will leave. More than one car or no car can come at one round. One round ends when user enters 0. After the car coming in, an arrival ticket will be provided like 
             **Arrival ticket**
* Arrival time: 1
* Type of vehicle: Motorbike
* Empty slot (x,y,floor) : 4,1,1

which includs the arrival time, type of the car and the empty slot the car can stop.
After that, if the user wants the car to leave at the fifth round, an departure ticket will be provided when the fifth round begins, which is shown as
           **Departure ticket**
* Time spent: 4
* Type of vehicle: Motorbike
* Price: 8

*which includes how long this kind of car was parked and how much it cost.
