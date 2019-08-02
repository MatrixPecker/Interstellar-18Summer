//
// Created by William Wu on 2019/8/2.
//

#include "Canvas.h"

Canvas::Canvas() {
    /* Coordinates */
    coor.slotnum = 23;
    for(int i=0;i<23;i++) coor.is_occupied[i] = false;
    coor.CENTER = {0,0};
    coor.CENTRAL_LOWER_Y = -0.2;
//    coor.CENTRAL_UPPER_Y =
    coor.CENTRAL_LEFT_X = -0.95;
//    coor.CENTRAL_RIGHT_X =
    coor.INITCENTER = {-0.8,coor.CENTRAL_LEFT_X};

    coor.LNG_IN_1 = coor.CENTRAL_LOWER_Y - coor.INITCENTER.y;
    coor.LNG_IN_A1 = {-0.7,-0.3};
    coor.LNG_IN_2 = 1.1;

    /* Vehicles */
    vnum = 2;
    v[0] = new Car(coor.INITCENTER,1.0,1.3,0.175,0.1);
    v[1] = new UFO(coor.INITCENTER,1.0,0.5,0.5);
    // If I don't write like this, sometimes Segmentation Fault will occur randomly.
    // I think the initial value of some certain variable is not set up correctly. - wqh
    v[0]->setpos(coor.INITCENTER); v[0]->rescale(0.07);
    v[1]->setpos(coor.INITCENTER); v[1]->rescale(0.1);
}
Canvas::~Canvas() {
    for(int i=0;i<vnum;i++) delete v[i];
}
void Canvas::draw() {
    std::cout << "ok\n";
    park.parkdraw();
    for(int i=0;i<vnum;i++) v[i]->reset();
    for(int i=0;i<vnum;i++) v[i]->draw();
}
void Canvas::change(int timenow){
    // change on the parkinglot
    static Point Csh = {-0.4,-0.4};
    v[0]->moveright(&Csh.x,&Csh.y);
    std::cout << "success\n";
}