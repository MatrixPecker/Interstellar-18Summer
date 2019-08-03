//
// Created by lykku on 2019/7/26.
//

#include "parkinglot.h"
#include "shape.h"

Parkinglot::Parkinglot() {
    float r=0,g=0,b=0;
    sh[0]=new class Rectangle({-0.08f,-0.02f},{0.08f,0.02f},r,g,b);
    sh[1]=new class Rectangle({-0.86f,-0.02f},{-0.26f,0.02f},r,g,b);
    sh[2]=new class Rectangle({0.26f,-0.02f},{0.65f,0.02f},r,g,b);
    sh[3]=new class Line({-0.98f,-0.4f},{-0.98f,0.38f},r,g,b);
    sh[4]=new class Line({0.98f,-0.38f},{0.98f,0.38f},r,g,b);
    sh[5]=new class Line({-0.96f,-0.4f},{-0.86f,-0.4f},0.9,g,b);
    sh[6]=new class Line({-0.86f,-0.38f},{-0.08f,-0.38f},r,g,b);
    sh[7]=new class Line({-0.08f,-0.02f},{0.08f,-0.02f},r,g,b);
    sh[8]=new class Line({0.98f,-0.38f},{0.08f,-0.38f},r,g,b);
    sh[9]=new class Line({0.98f,-0.38f},{0.98f,0.38f},r,g,b);
    sh[10]=new class Line({0.98f,0.38f},{0.08f,0.38f},r,g,b);
    sh[11]=new class Line({-0.86f,0.38f},{-0.08f,0.38f},r,g,b);
    sh[12]=new class Line({-0.08f,0.02f},{0.08f,0.02f},r,g,b);
    sh[13]=new class Line({-0.86f,-0.4f},{-0.86f,-0.22f},r,g,b);
    sh[14]=new class Line({-0.74f,-0.38f},{-0.74f,-0.22f},r,g,b);
    sh[15]=new class Line({-0.62f,-0.38f},{-0.62f,-0.22f},r,g,b);
    sh[16]=new class Line({-0.5f,-0.38f},{-0.5f,-0.22f},r,g,b);
    sh[17]=new class Line({-0.38f,-0.38f},{-0.38f,-0.22f},r,g,b);
    sh[18]=new class Line({-0.26f,-0.38f},{-0.26f,-0.22f},r,g,b);
    sh[19]=new class Line({-0.08f,-0.38f},{-0.08f,-0.18f},r,g,b);
    sh[20]=new class Line({0.08f,-0.38f},{0.08f,-0.18f},r,g,b);
    sh[21]=new class Line({0.2f,-0.38f},{0.2f,-0.22f},r,g,b);
    sh[22]=new class Line({0.32f,-0.38f},{0.32f,-0.22f},r,g,b);
    sh[23]=new class Line({0.44f,-0.38f},{0.44f,-0.22f},r,g,b);
    sh[24]=new class Line({0.56f,-0.38f},{0.56f,-0.22f},r,g,b);
    sh[25]=new class Line({0.68f,-0.38f},{0.68f,-0.22f},r,g,b);
    sh[26]=new class Line({0.82f,-0.18f},{0.98f,-0.18f},r,g,b);
    sh[27]=new class Line({-0.08f,-0.18f},{0.08f,-0.18f},r,g,b);
    sh[28]=new class Line({-0.86f,0.4f},{-0.86f,0.22f},r,g,b);
    sh[29]=new class Line({-0.74f,0.38f},{-0.74f,0.22f},r,g,b);
    sh[30]=new class Line({-0.62f,0.38f},{-0.62f,0.22f},r,g,b);
    sh[31]=new class Line({-0.5f,0.38f},{-0.5f,0.22f},r,g,b);
    sh[32]=new class Line({-0.38f,0.38f},{-0.38f,0.22f},r,g,b);
    sh[33]=new class Line({-0.26f,0.38f},{-0.26f,0.22f},r,g,b);
    sh[34]=new class Line({-0.08f,0.38f},{-0.08f,0.18f},r,g,b);
    sh[35]=new class Line({0.08f,0.38f},{0.08f,0.18f},r,g,b);
    sh[36]=new class Line({0.2f,0.38f},{0.2f,0.22f},r,g,b);
    sh[37]=new class Line({0.32f,0.38f},{0.32f,0.22f},r,g,b);
    sh[38]=new class Line({0.44f,0.38f},{0.44f,0.22f},r,g,b);
    sh[39]=new class Line({0.56f,0.38f},{0.56f,0.22f},r,g,b);
    sh[40]=new class Line({0.68f,0.38f},{0.68f,0.22f},r,g,b);
    sh[41]=new class Line({0.82f,0.18f},{0.98f,0.18f},r,g,b);
    sh[42]=new class Line({-0.08f,0.18f},{0.08f,0.18f},r,g,b);
    sh[43]=new class Line({-0.06f,-0.18f},{-0.06f,-0.02f},r,g,b);
    sh[44]=new class Line({-0.08f,-0.18f},{-0.08f,-0.02f},r,g,b);
    sh[45]=new class Line({-0.04f,-0.18f},{-0.04f,-0.02f},r,g,b);
    sh[46]=new class Line({-0.02f,-0.18f},{-0.02f,-0.02f},r,g,b);
    sh[47]=new class Line({0,-0.18f},{0,-0.02f},r,g,b);
    sh[48]=new class Line({0.02f,-0.18f},{0.02f,-0.02f},r,g,b);
    sh[49]=new class Line({0.04f,-0.18f},{0.04f,-0.02f},r,g,b);
    sh[50]=new class Line({0.06f,-0.18f},{0.06f,-0.02f},r,g,b);
    sh[51]=new class Line({0.08f,-0.18f},{0.08f,-0.02f},r,g,b);
    sh[52]=new class Line({-0.06f,0.18f},{-0.06f,0.02f},r,g,b);
    sh[53]=new class Line({-0.08f,0.18f},{-0.08f,0.02f},r,g,b);
    sh[54]=new class Line({-0.04f,0.18f},{-0.04f,0.02f},r,g,b);
    sh[55]=new class Line({-0.02f,0.18f},{-0.02f,0.02f},r,g,b);
    sh[56]=new class Line({0,0.18f},{0,0.02f},r,g,b);
    sh[57]=new class Line({0.02f,0.18f},{0.02f,0.02f},r,g,b);
    sh[58]=new class Line({0.04f,0.18f},{0.04f,0.02f},r,g,b);
    sh[59]=new class Line({0.06f,0.18f},{0.06f,0.02f},r,g,b);
    sh[60]=new class Line({0.08f,0.18f},{0.08f,0.02f},r,g,b);
    sh[61]=new class Line({-0.1f,0.18f},{-0.1f,0.02f},r,g,b);
    sh[62]=new class Line({0.1f,0.18f},{0.1f,0.02f},r,g,b);
    sh[63]=new class Line({-0.1f,-0.18f},{-0.1f,-0.02f},r,g,b);
    sh[64]=new class Line({0.1f,-0.18f},{0.1f,-0.02f},r,g,b);
    sh[65]=new class Line({-0.96f,0.4f},{-0.86f,0.4f},1,0,0);
    sh[66]=new class Line({0.82f,0.06f},{0.98f,0.06f},r,g,b);
    sh[67]=new class Line({0.82f,-0.06f},{0.98f,-0.06f},r,g,b);
    for (int i=0;i<=19;i++) plate[i]=true;
    location[0]={-0.8,-0.3};location[1]={-0.68,-0.3};location[2]={-0.56,-0.3};location[3]={-0.44,-0.3};location[4]={-0.32,-0.3};
    location[9]={0.8,-0.3};location[8]={0.68,-0.3};location[7]={0.56,-0.3};location[6]={0.44,-0.3};location[5]={0.32,-0.3};
    location[10]={0.8,0.3};location[11]={0.68,0.3};location[12]={0.56,0.3};location[13]={0.44,0.3};location[14]={0.32,0.3};
    location[19]={-0.8,0.3};location[18]={-0.68,0.3};location[17]={-0.56,0.3};location[16]={-0.44,0.3};location[15]={-0.32,0.3};
}
Parkinglot::~Parkinglot() {
    for(int i=0;i<68;i++) delete sh[i];
}
void Parkinglot::parkdraw() {for(int i=0;i<=67;i++) sh[i]->draw();}
Point Parkinglot::locate() {
    for (int i=0;i<=19;i++)
        if (plate[i]) {
            plate[i]=false;
            return location[i];
    }
    return {0,0};
}
void Parkinglot::leave(Point vehicle) {
    for (int i=0;i<20;i++){
        if (vehicle.x==location[i].x && vehicle.y==location->y){
            plate[i]=true;
            break;
        }
    }
}