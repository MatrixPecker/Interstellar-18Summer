# Interstellar - Group 0E0W
Interstellar Parking Lot for Vg101, 18 Summer

**Contributors:**

Gu Xihe    518370910093
  
Lou Yukun  518021910263
  
Wang Ziyi  518370910073
  
Wu Qinhang 518370910041

**Version: Milestone 1 (July. 28)**

**DDL(Milestone 2): Aug. 2**

**DDL(Final Submission): Aug. 7**

## File Structure
|--main.cpp

|--Vec.h

|--Vec.cpp

|--Engine.h

|--Engine.cpp

|--shape.h

|--shape.cpp

|--figure.h

|--figure.cpp

|--parkinglot.cpp

|--parkinglot.h

|--README.md

|--Changelog.txt  [Not Implemented]
  
|--CMakeLists.txt


## To-do List
### General
- ~~Color Table    [GXH]~~
- ~~Engine: Vec, Rotate    [WQH]~~
- First Part of the Parkinglot (the design of a generic parking lot)    [GXH/LYK]
- ~~Figure: Parkinglot    [LYK]~~
  - Layer design & fix    [LYK]
- Size & Scale fix    [?]
- Shape: barrier blocking    [?]
- Shape: bicycle, motorbike, car    [?]
- README maintenance    [GXH]
- Rotation engine    [WQH]
  - Map for different slots    [WQH]
- Route programming    [LYK/WQH]
### Milestone 1
- Ticket    [WZY]
- Price Calculation    [WZY]
- Find an empty slot    [?]
### Milestone 2
- ~~Basic shapes    [LYK]~~
- ~~Figure: vehicles    [LYK]~~
### Final submission
- fix main.c and Canvas    [WQH]
- Interface: specify slots and enter command    [?]
  - "Not available" symbol on the slot    [?]
### Bonus
- Trajectory recording    [WQH] [pending]
  - simulate the dust tracks; implemented with queue
- Motion: moving flag
- fix inheritance relationship
- clean the code
- Motion: teleported (polygon teleporter)
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




