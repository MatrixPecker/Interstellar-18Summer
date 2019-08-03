//
// Created by William Wu on 2019/8/2.
//

#include "Canvas.h"

Canvas::Canvas() {
/* Set Static Coordinates */
    c = new Cdata;
    c->slotnum = 23;
    for(int i=0;i<23;i++) c->is_occupied[i] = false;
    for(int i=0;i<23;i++) c->backwardslng[i] = 0.06;
    c->CENTER = {0,0};
    c->CENTRAL_LOWER_Y = -0.1;
    c->CENTRAL_UPPER_Y = 0.1; //
    c->CENTRAL_LEFT_X  = -0.92;
    c->CENTRAL_RIGHT_X = 0.75; //
    c->INITCENTER = {c->CENTRAL_LEFT_X,-0.7}; // -0.7 for debug, smaller later

    c->LNG_IN_0  = {c->CENTRAL_LEFT_X,-0.5};
    c->LNG_IN_1  = {c->CENTRAL_LEFT_X,-0.16};
    c->LNG_IN_A1 = {-0.86,(c->CENTRAL_LOWER_Y-0.06)};
    c->LNG_IN_2  = {0.0,c->CENTRAL_LOWER_Y};
    c->LNG_IN_3  = {c->CENTRAL_RIGHT_X-0.08,c->CENTRAL_LOWER_Y};
    c->LNG_IN_A3 = {c->CENTRAL_RIGHT_X-0.08,c->CENTRAL_LOWER_Y+0.08};
//    c->LNG_IN_4;
//    c->LNG_IN_A4;
//    c->LNG_IN_5;
//    c->LNG_IN_6;
//    c->LNG_IN_A6;
//    c->LNG_IN_7;
//    double tmp = c->CENTRAL_LOWER_Y+0.22;
    Point p1[]={{-0.68,-0.1},{-0.56,-0.1},{-0.44,-0.1},{-0.32,-0.1},{-0.20,-0.1}}; // assigned here
    for(int i=0;i<5;i++) c->SLNG_SEC2[i]=p1[i].x-c->LNG_IN_A1.x;
    Point pa1[]={{-0.68,-0.22},{-0.56,-0.22},{-0.44,-0.22},{-0.32,-0.22},{-0.20,-0.22}}; // assigned here
    for(int i=0;i<5;i++) c->SLNG_SEC2A[i]=pa1[i];

/* Set Vehicles */
    vnum = 2;
    v[0] = new Car(c->INITCENTER,1.0,1.3,0.175,0.1);
    v[1] = new UFO(c->INITCENTER,1.0,0.5,0.5);
    v[0]->setpos(c->INITCENTER); v[0]->rescale(0.07);
    v[1]->setpos(c->INITCENTER); v[1]->rescale(0.08);
    v[0]->setintime(10); v[1]->setintime(260);
    v[0]->setouttime(1610); v[1]->setouttime(2000);
    v[0]->setassignedslot(3); v[1]->setassignedslot(4);
    for(int i=0;i<vnum;i++) v[i]->setstatus(LOT_WAITING);

    for(int i=0;i<vnum;i++) v[i]->reset();
/* Set Speed */
    linearstep = 0.01;
    angularstep = 2;
/* Set Time */
    double tmp1[] = {(c->LNG_IN_0.y-c->INITCENTER.y)/linearstep, (c->LNG_IN_1.y-c->LNG_IN_0.y)/linearstep,
                     (90.0)/angularstep, -1,
                     (90.0)/angularstep,c->backwardslng[0]/linearstep}; // pick backwardslng[0] here.
    for(int i=0;i<6;i++) c->D_IN_SEC2[i]=(int)tmp1[i];
}
Canvas::~Canvas() {
    for(int i=0;i<vnum;i++) delete v[i];
    delete c;
}
void Canvas::draw() {
    park.parkdraw();//v[0]->rescale(0.07);v[1]->rescale(0.1);
    for(int i=0;i<vnum;i++) v[i]->draw();
}
void Canvas::change(){
    if(timenow <= 25) ((UFO*)v[1])->debugg();
    for(int i=0;i<vnum;i++){
        if(timenow >= v[i]->getintime() && timenow < v[i]->getouttime()){
            parkIN(i);
        }
        if(timenow >= v[i]->getouttime()){ // the gap interval should be set strictly! additional calculation needed.
            parkOUT(i);
        }
    }
}
void Canvas::parkIN(int k) {
    const int SECTOR[] = {2,2,2,2,2,3,3,3,3,3,4,4,4,5,5,5,5,5,6,6,6,6,6};
    const int SLOT[] = {1,2,3,4,5,1,2,3,4,5,1,2,3,1,2,3,4,5,1,2,3,4,5};
    int sector = SECTOR[v[k]->getassignedslot()-1];
    int t = timenow-v[k]->getintime(); // relative time
    int s = SLOT[v[k]->getassignedslot()-1]; // relative slot

    if(sector==2){
        /* Renew coordinate map */
        c->D_IN_SEC2[3] = (int)(c->SLNG_SEC2[s]/linearstep);
        int T[6]; T[0]=c->D_IN_SEC2[0]; for(int i=1;i<6;i++) T[i]=T[i-1]+c->D_IN_SEC2[i];
        if(t<=T[0]) {v[k]->supermove(0,linearstep);}
        else if(t>T[0]&&t<=T[1]) {v[k]->supermove(0,linearstep);}
        else if(t>T[1]&&t<=T[2]) {v[k]->rotate(c->LNG_IN_A1,-1.0*angularstep);}
        else if(t>T[2]&&t<=T[3]) {v[k]->supermove(linearstep,0);}
        else if(t>T[3]&&t<=T[4]) {v[k]->rotate(c->SLNG_SEC2A[s],angularstep);}
        else if(t>T[4]&&t<=T[5]) {v[k]->supermove(0,-1.0*linearstep);}
        else if(t>T[5]) {v[k]->setstatus(LOT_INWAITING);return;}
    }
    else if(sector==3){

    }
    else if(sector==4){

    }
    else if(sector==5){

    }
    else if(sector==6){

    }
}
void Canvas::parkOUT(int k){

}
void Canvas::gettime(int t){
    timenow = t;
}
