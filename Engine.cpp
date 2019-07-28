//
// Created by William Wu on 2019/7/29.
//

#include "Engine.h"
#include "Vec.h"
#include "figure.h"

void TestDraw2(){
    static int tmpTime = 0; tmpTime++;static int flag=0;
    static double r = 0,lng = 0.01;
    static Point Csh = {-0.4,-0.4};
    double movelng[] = {0.3,0.7};
    Car sh(Csh,1.0/10,1.3/10,0.175/10,0.1/10);

    if(tmpTime <= (int)(movelng[0]/lng)) sh.moveup(&Csh.x,&Csh.y);
    else if(tmpTime > (int)(movelng[0]/lng) && tmpTime <= (int)(movelng[0]/lng)+90){
        r -= 1;
        sh.rotate({-0.3,-0.1},r);
        if(tmpTime==(int)(movelng[0]/lng)+90) sh.moveln(&Csh.x,&Csh.y,0.1,0.1);
    }
    else if(tmpTime > (int)(movelng[0]/lng)+90 && tmpTime <= (int)(movelng[0]/lng)+90+(int)(movelng[1]/lng)){
        sh.moveright(&Csh.x,&Csh.y);flag=0;
        sh.Crotate(r);
    }
    else if(tmpTime > (int)(movelng[0]/lng)+90+(int)(movelng[1]/lng) && tmpTime <= (int)(movelng[0]/lng)+90+(int)(movelng[1]/lng)+90){
//        if(tmpTime==(int)(movelng[0]/lng)+90+(int)(movelng[1]/lng)+1) sh.moveln(&Csh.x,&Csh.y,-0.1,-0.1);
        if(flag==0) {sh.moveln(&Csh.x,&Csh.y,-0.1,-0.1);flag=1;}
        r += 1;
        sh.rotate({0.4,-0.1},r);
    }
//    else sh.rotate({0.4,-0.1},r);

    sh.draw();
}