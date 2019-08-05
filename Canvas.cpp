//
// Created by William Wu on 2019/8/2.
//

#include "Canvas.h"
void Canvas::settmptype(int *temtype,int num) {
    srand(time(NULL));
    int ran = 0;
    temtype[0]=TYPE_TELEPORTED;temtype[1]=TYPE_TELEPORTED;
    temtype[2]=TYPE_SPACECRAFT;temtype[3]=TYPE_SPACECRAFT;
    for (int i = 4; i < num; i++) {
        ran = rand() % 4;
        switch (ran) {
            case 0:
                temtype[i] = TYPE_CAR; break;
            case 1:
                temtype[i] = TYPE_SPACECRAFT; break;
            case 2:
                temtype[i] = TYPE_UFO; break;
            case 3:
                temtype[i] = TYPE_TELEPORTED; break;
        }
    }
}
void Canvas::settmptime(int *tmpin, int *tmpout, int num) {
    int ran=0;
    srand(time(NULL));
    tmpin[0]=0;tmpin[1]=0;tmpin[2]=0;tmpin[3]=0;tmpin[4]=125;tmpin[5]=325;
    tmpout[0]=9000;tmpout[1]=9000;tmpout[2]=9000;tmpout[3]=9000;tmpout[4]=9000;tmpout[5]=9000;
    for (int i=6;i<num;i++){
        ran=rand()%200+(i-3)*200;
        tmpin[i]=ran;
        do {
            ran=rand()%(vnum*2000);
            tmpout[i]=ran;
        }while ((tmpout[i]-tmpin[i])<300);
    }
}
void Canvas::settmplot(int *tmplot, int num) {
    int ran=0;
    bool judge=true;
    srand(time(NULL));
    tmplot[0]=rand()%23+1;
    for (int i=1;i<num;i++){
        do{
        ran=rand()%23+1;
        for (int j=0;j<i;j++) {
            if (tmplot[j] == ran) {
                judge = false;
                break;
            }
            else judge=true;
        }
        }while (judge==false);
        tmplot[i]=ran;
    }
}
Canvas::Canvas() {
/* Set Static Coordinates */
    c = new Cdata;
    c->slotnum = 23;
    for(int i=0;i<23;i++) c->is_occupied[i] = false;
    for(int i=0;i<23;i++) c->backwardslng[i] = 0.06;
    c->CENTER = {0,0};
    c->CENTRAL_LOWER_Y = -0.1;
    c->CENTRAL_UPPER_Y = 0.1;
    c->CENTRAL_LEFT_X  = -0.92;
    c->CENTRAL_RIGHT_X = 0.75;
    c->INITCENTER = {c->CENTRAL_LEFT_X,-1.3}; // IN

    double tmplotcntx[] = {-0.8,-0.68,-0.56,-0.44,-0.32,0.14,0.26,0.38,0.5,0.62,0.9,0.9,0.9,
                           0.62,0.5,0.38,0.26,0.14,-0.32,-0.44,-0.56,-0.68,-0.8};
    double tmplotcnty[] = {-0.3,-0.3,-0.3,-0.3,-0.3,-0.3,-0.3,-0.3,-0.3,-0.3,-0.12,0,0.12,
                           0.3,0.3,0.3,0.3,0.3,0.3,0.3,0.3,0.3,0.3};
    for(int i=0;i<23;i++) c->LOTCENTER[i] = {tmplotcntx[i],tmplotcnty[i]};

    c->LNG_IN_0  = {c->CENTRAL_LEFT_X,-0.5}; // BAR
    c->LNG_IN_1  = {c->CENTRAL_LEFT_X,-0.16};
    c->LNG_IN_A1 = {-0.86,(c->CENTRAL_LOWER_Y-0.06)};
    c->LNG_IN_2  = {0.0,c->CENTRAL_LOWER_Y};
    c->LNG_IN_3  = {c->CENTRAL_RIGHT_X-0.08,c->CENTRAL_LOWER_Y};
    c->LNG_IN_A3 = {c->CENTRAL_RIGHT_X-0.08,c->CENTRAL_LOWER_Y+0.08};
    c->LNG_IN_4  = {c->CENTRAL_RIGHT_X,c->CENTRAL_UPPER_Y-0.08};
    c->LNG_IN_A4 = {c->CENTRAL_RIGHT_X-0.08,c->CENTRAL_UPPER_Y-0.08};
    c->LNG_IN_5  = {0.0,c->CENTRAL_UPPER_Y};
    c->LNG_IN_6  = {-0.86,c->CENTRAL_UPPER_Y};
    c->LNG_IN_A6 = {-0.86,c->CENTRAL_UPPER_Y+0.06};
    c->LNG_IN_7  = {c->CENTRAL_LEFT_X,1.5}; // OUT

    Point p1[]={{-0.68,-0.1},{-0.56,-0.1},{-0.44,-0.1},{-0.32,-0.1},{-0.20,-0.1}}; // gap 0.12
    for(int i=0;i<5;i++) c->SLNG_SEC2[i]=p1[i].x-c->LNG_IN_A1.x;
    Point pa1[]={{-0.68,-0.22},{-0.56,-0.22},{-0.44,-0.22},{-0.32,-0.22},{-0.20,-0.22}}; // assigned here
    for(int i=0;i<5;i++) c->SLNG_SEC2A[i]=pa1[i];

    Point p2[]={{0.24,-0.1},{0.36,-0.1},{0.48,-0.1},{0.6,-0.1},{0.72,-0.1}};
    for(int i=0;i<5;i++) c->SLNG_SEC3[i]=p2[i].x-c->LNG_IN_2.x;
    Point pa2[]={{0.26,-0.22},{0.38,-0.22},{0.5,-0.22},{0.62,-0.22},{0.74,-0.22}};
    for(int i=0;i<5;i++) c->SLNG_SEC3A[i]=pa2[i];

    Point p3[]={{0.75,-0.04},{0.75,0.08},{0.75,0.2}};
    for(int i=0;i<3;i++) c->SLNG_SEC4[i]=p3[i].y-c->LNG_IN_A3.y; // the first value is negative
    Point pa3[]={{0.82,-0.04},{0.82,0.08},{0.82,0.2}};
    for(int i=0;i<3;i++) c->SLNG_SEC4A[i]=pa3[i];

    Point p4[]={{0.5,0.1},{0.38,0.1},{0.26,0.1},{0.14,0.1},{0.02,0.1}};
    for(int i=0;i<5;i++) c->SLNG_SEC5[i]=p4[i].x-c->LNG_IN_A4.x;
    Point pa4[]={{0.5,0.22},{0.38,0.22},{0.26,0.22},{0.14,0.22},{0.02,0.22}};
    for(int i=0;i<5;i++) c->SLNG_SEC5A[i]=pa4[i];

    Point p5[]={{-0.44,0.1},{-0.56,0.1},{-0.68,0.1},{-0.8,0.1},{-0.92,0.1}};
    for(int i=0;i<5;i++) c->SLNG_SEC6[i]=p5[i].x-c->LNG_IN_5.x;
    Point pa5[]={{-0.44,0.22},{-0.56,0.22},{-0.68,0.22},{-0.8,0.22},{-0.92,0.22}};
    for(int i=0;i<5;i++) c->SLNG_SEC6A[i]=pa5[i];

/* Set Vehicles */
    vnum = 18;
    int *tmptype=new int[vnum];
    settmptype(tmptype,vnum);
    for(int i=0;i<vnum;i++) {
        switch (tmptype[i]) {
            case TYPE_CAR:
                v[i] = new Car;
                v[i]->settype(TYPE_CAR);
                break;
            case TYPE_UFO:
                v[i] = new UFO;
                v[i]->settype(TYPE_UFO);
                break;
            case TYPE_SPACECRAFT:
                v[i] = new Spacecraft;
                v[i]->settype(TYPE_SPACECRAFT);
                break;
            case TYPE_TELEPORTED:
                v[i] = new Teleported;
                v[i]->settype(TYPE_TELEPORTED);
                break;
                // Teleported Init.: special judge needed
        }
    }
    for(int i=0;i<vnum;i++) v[i]->setpos(c->INITCENTER);
    /*for(int i=0;i<vnum;i++) switch(v[i]->gettype()){
            case TYPE_CAR: v[i]->rescale(0.07); break;
            case TYPE_UFO: v[i]->rescale(0.08); break;
            case TYPE_SPACECRAFT: v[i]->rescale(0.13);break;
            case TYPE_TELEPORTED: v[i]->rescale(0.1);break;
        }*/
    int *tmpin=new int [vnum];
    int *tmpout=new int[vnum];
    settmptime(tmpin,tmpout,vnum);
    for(int i=0;i<vnum;i++) v[i]->setouttime(tmpout[i]);
    for(int i=0;i<vnum;i++) v[i]->setintime(tmpin[i]);
    for(int i=0;i<vnum;i++) v[i]->setstatus(LOT_WAITING);
    int *tmplot=new int [vnum];
    settmplot(tmplot,vnum);
    for(int i=0;i<vnum;i++){
        v[i]->setassignedslot(tmplot[i]);
        if(v[i]->gettype() == TYPE_TELEPORTED){
            v[i]->setpos(c->LOTCENTER[v[i]->getassignedslot()-1]); // assign initcenter here! (teleported)
            v[i]->setstatus(LOT_INWAITING);

        }
    }
    for(int i=0;i<vnum;i++) v[i]->reset(); // corresponding with rescale
    for(int i=0;i<vnum;i++)
        if((v[i]->getassignedslot()<=10 || v[i]->getassignedslot()>=14) && v[i]->gettype() == TYPE_TELEPORTED) v[i]->Crotate(90);
    delete [] tmpin; delete [] tmplot; delete [] tmpout; delete [] tmptype;


/* Set Speed */
    linearstep = 0.01;
    angularstep = 2;

/* Set Time */
    c->barwaiting = 50;
    double tmp1[] = {(c->LNG_IN_0.y-c->INITCENTER.y)/linearstep, c->barwaiting, (c->LNG_IN_1.y-c->LNG_IN_0.y)/linearstep,
                     (90.0)/angularstep, -1,
                     (90.0)/angularstep,c->backwardslng[0]/linearstep}; // pick backwardslng[0] here.
    for(int i=0;i<7;i++) c->D_IN_SEC2[i]=(int)tmp1[i];

    double tmp2[] = {(c->LNG_IN_0.y-c->INITCENTER.y)/linearstep, c->barwaiting, (c->LNG_IN_1.y-c->LNG_IN_0.y)/linearstep,
                     (90.0)/angularstep, (c->LNG_IN_2.x-c->LNG_IN_A1.x)/linearstep, -1,
                     (90.0)/angularstep,c->backwardslng[0]/linearstep};
    for(int i=0;i<8;i++) c->D_IN_SEC3[i]=(int)tmp2[i];

    double tmp3[] = {(c->LNG_IN_0.y-c->INITCENTER.y)/linearstep, c->barwaiting, (c->LNG_IN_1.y-c->LNG_IN_0.y)/linearstep,
                     (90.0)/angularstep, (c->LNG_IN_2.x-c->LNG_IN_A1.x)/linearstep,
                     (c->LNG_IN_3.x-c->LNG_IN_2.x)/linearstep, (90.0)/angularstep, -1,
                     (90.0)/angularstep, c->backwardslng[0]/linearstep};
    for(int i=0;i<10;i++) c->D_IN_SEC4[i]=(int)tmp3[i];

    double tmp4[] = {(c->LNG_IN_0.y-c->INITCENTER.y)/linearstep, c->barwaiting, (c->LNG_IN_1.y-c->LNG_IN_0.y)/linearstep,
                     (90.0)/angularstep, (c->LNG_IN_2.x-c->LNG_IN_A1.x)/linearstep,
                     (c->LNG_IN_3.x-c->LNG_IN_2.x)/linearstep, (90.0)/angularstep,
                     (c->LNG_IN_4.y-c->LNG_IN_A3.y)/linearstep, (90.0)/angularstep,
                     -1, (90.0)/angularstep, c->backwardslng[0]/linearstep};
    for(int i=0;i<12;i++) c->D_IN_SEC5[i]=(int)tmp4[i];

    double tmp5[] = {(c->LNG_IN_0.y-c->INITCENTER.y)/linearstep, c->barwaiting, (c->LNG_IN_1.y-c->LNG_IN_0.y)/linearstep,
                     (90.0)/angularstep, (c->LNG_IN_2.x-c->LNG_IN_A1.x)/linearstep,
                     (c->LNG_IN_3.x-c->LNG_IN_2.x)/linearstep, (90.0)/angularstep,
                     (c->LNG_IN_4.y-c->LNG_IN_A3.y)/linearstep, (90.0)/angularstep,
                     (c->LNG_IN_A4.x-c->LNG_IN_5.x)/linearstep, -1, (90.0)/angularstep, c->backwardslng[0]/linearstep};
    for(int i=0;i<13;i++) c->D_IN_SEC6[i]=(int)tmp5[i];
}
Canvas::~Canvas() {
    for(int i=0;i<vnum;i++) delete v[i]; // delete[] v; // for(int i=0;i<vnum;i++) delete v[i];
    delete c;
}
void Canvas::draw() {
    park.parkdraw();
    for(int i=0;i<vnum;i++) v[i]->draw();
}
void Canvas::change(){
//    if(timenow <= 25) ((UFO*)v[1])->debugg();
    for(int i=0;i<vnum;i++){
        if(timenow >= v[i]->getintime() && timenow < v[i]->getouttime() && v[i]->getstatus()<LOT_INWAITING){
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
    int s = SLOT[v[k]->getassignedslot()-1]-1; // relative slot

    if(sector==2){
        /* Renew coordinate map */
        c->D_IN_SEC2[4] = (int)(c->SLNG_SEC2[s]/linearstep);
        int T[7]; T[0]=c->D_IN_SEC2[0]; for(int i=1;i<7;i++) T[i]=T[i-1]+c->D_IN_SEC2[i];
        if(t<=T[0]) {v[k]->supermove(0,linearstep);}
        else if(t>T[0]&&t<=T[1]) {/* Right here waiting. */}
        else if(t>T[1]&&t<=T[2]) {v[k]->supermove(0,linearstep);}
        else if(t>T[2]&&t<=T[3]) {v[k]->rotate(c->LNG_IN_A1,-1.0*angularstep);}
        else if(t>T[3]&&t<=T[4]) {v[k]->supermove(linearstep,0);}
        else if(t>T[4]&&t<=T[5]) {v[k]->rotate(c->SLNG_SEC2A[s],angularstep);}
        else if(t>T[5]&&t<=T[6]) {v[k]->supermove(0,-1.0*linearstep);}
        else if(t>T[6]) {v[k]->setstatus(LOT_INWAITING);return;}
    }
    else if(sector==3){
        c->D_IN_SEC3[5] = (int)(c->SLNG_SEC3[s]/linearstep);
        int T[8]; T[0]=c->D_IN_SEC3[0]; for(int i=1;i<8;i++) T[i]=T[i-1]+c->D_IN_SEC3[i];
        if(t<=T[0]) {v[k]->supermove(0,linearstep);}
        else if(t>T[0]&&t<=T[1]) {/* Right here waiting. */}
        else if(t>T[1]&&t<=T[2]) {v[k]->supermove(0,linearstep);}
        else if(t>T[2]&&t<=T[3]) {v[k]->rotate(c->LNG_IN_A1,-1.0*angularstep);}
        else if(t>T[3]&&t<=T[4]) {v[k]->supermove(linearstep,0);}
        else if(t>T[4]&&t<=T[5]) {v[k]->supermove(linearstep,0);}
        else if(t>T[5]&&t<=T[6]) {v[k]->rotate(c->SLNG_SEC3A[s],angularstep);}
        else if(t>T[6]&&t<=T[7]) {v[k]->supermove(0,-1.0*linearstep);}
        else if(t>T[7]) {v[k]->setstatus(LOT_INWAITING);return;}
    }
    else if(sector==4){
        c->D_IN_SEC4[7] = (int)(abs(c->SLNG_SEC4[s]/linearstep));
        int T[10]; T[0]=c->D_IN_SEC4[0]; for(int i=1;i<10;i++) T[i]=T[i-1]+c->D_IN_SEC4[i];
        if(t<=T[0]) {v[k]->supermove(0,linearstep);}
        else if(t>T[0]&&t<=T[1]) {/* Right here waiting. */}
        else if(t>T[1]&&t<=T[2]) {v[k]->supermove(0,linearstep);}
        else if(t>T[2]&&t<=T[3]) {v[k]->rotate(c->LNG_IN_A1,-1.0*angularstep);}
        else if(t>T[3]&&t<=T[4]) {v[k]->supermove(linearstep,0);}
        else if(t>T[4]&&t<=T[5]) {v[k]->supermove(linearstep,0);}
        else if(t>T[5]&&t<=T[6]) {v[k]->rotate(c->LNG_IN_A3,angularstep);}
        else if(t>T[6]&&t<=T[7]) {v[k]->supermove(0,linearstep);}
        else if(t>T[7]&&t<=T[8]) {v[k]->rotate(c->SLNG_SEC4A[s],angularstep);}
        else if(t>T[8]&&t<=T[9]) {v[k]->supermove(linearstep,0);}
        else if(t>T[9]) {v[k]->setstatus(LOT_INWAITING);return;}
    }
    else if(sector==5){
        c->D_IN_SEC5[9] = (int)(abs(c->SLNG_SEC5[s]/linearstep));
        int T[12]; T[0]=c->D_IN_SEC5[0]; for(int i=1;i<12;i++) T[i]=T[i-1]+c->D_IN_SEC5[i];
        if(t<=T[0]) {v[k]->supermove(0,linearstep);}
        else if(t>T[0]&&t<=T[1]) {/* Right here waiting. */}
        else if(t>T[1]&&t<=T[2]) {v[k]->supermove(0,linearstep);}
        else if(t>T[2]&&t<=T[3]) {v[k]->rotate(c->LNG_IN_A1,-1.0*angularstep);}
        else if(t>T[3]&&t<=T[4]) {v[k]->supermove(linearstep,0);}
        else if(t>T[4]&&t<=T[5]) {v[k]->supermove(linearstep,0);}
        else if(t>T[5]&&t<=T[6]) {v[k]->rotate(c->LNG_IN_A3,angularstep);}
        else if(t>T[6]&&t<=T[7]) {v[k]->supermove(0,linearstep);}
        else if(t>T[7]&&t<=T[8]) {v[k]->rotate(c->LNG_IN_A4,angularstep);}
        else if(t>T[8]&&t<=T[9]) {v[k]->supermove(-1.0*linearstep,0);}
        else if(t>T[9]&&t<=T[10]) {v[k]->rotate(c->SLNG_SEC5A[s],angularstep);}
        else if(t>T[10]&&t<=T[11]) {v[k]->supermove(0,linearstep);}
        else if(t>T[11]) {v[k]->setstatus(LOT_INWAITING);return;}
    }
    else if(sector==6){
        c->D_IN_SEC6[10] = (int)(abs(c->SLNG_SEC6[s]/linearstep));
        int T[13]; T[0]=c->D_IN_SEC6[0]; for(int i=1;i<13;i++) T[i]=T[i-1]+c->D_IN_SEC6[i];
        if(t<=T[0]) {v[k]->supermove(0,linearstep);}
        else if(t>T[0]&&t<=T[1]) {/* Right here waiting. */}
        else if(t>T[1]&&t<=T[2]) {v[k]->supermove(0,linearstep);}
        else if(t>T[2]&&t<=T[3]) {v[k]->rotate(c->LNG_IN_A1,-1.0*angularstep);}
        else if(t>T[3]&&t<=T[4]) {v[k]->supermove(linearstep,0);}
        else if(t>T[4]&&t<=T[5]) {v[k]->supermove(linearstep,0);}
        else if(t>T[5]&&t<=T[6]) {v[k]->rotate(c->LNG_IN_A3,angularstep);}
        else if(t>T[6]&&t<=T[7]) {v[k]->supermove(0,linearstep);}
        else if(t>T[7]&&t<=T[8]) {v[k]->rotate(c->LNG_IN_A4,angularstep);}
        else if(t>T[8]&&t<=T[9]) {v[k]->supermove(-1.0*linearstep,0);}
        else if(t>T[9]&&t<=T[10]) {v[k]->supermove(-1.0*linearstep,0);}
        else if(t>T[10]&&t<=T[11]) {v[k]->rotate(c->SLNG_SEC6A[s],angularstep);}
        else if(t>T[11]&&t<=T[12]) {v[k]->supermove(0,linearstep);}
        else if(t>T[12]) {v[k]->setstatus(LOT_INWAITING);return;}
    }
}
void Canvas::parkOUT(int k){

}
void Canvas::gettime(int t){
    timenow = t;
}
