//
// Created by lykku on 2019/7/29.
//

#ifndef HWX_PARKINGAREA_H
#define HWX_PARKINGAREA_H

#include <string>
using namespace std;
typedef struct _Point { double x,y; int floor;} Point;
class Parkingarea{
public:
    Point offerlot(string type);
    void moveout(Point p1);
    Parkingarea(int n);
    ~Parkingarea();
private:
    int slots=100;
    Point *lot=new Point[slots];
    bool *lott=new bool[slots];
    string *lottt=new string[slots];
};
#endif //HWX_PARKINGAREA_H
