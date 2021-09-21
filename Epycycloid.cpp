#include <iostream>
#include <stdio.h>
#include <cmath>

#include "Epycycloid.h"

namespace Lab2{

    //constructors
    Epycycloid::Epycycloid(){
        double radBig = 2.0;
        double radSmall = 1.0;
        double distance = 1.0;
    }
    //write messeges
    Epycycloid::Epycycloid(double rBig, double rSmall, double dist) :p() {
        if (rBig <= 0)
            throw std::exception();
        if (rSmall <= 0)
            throw std::exception();
        if (rBig <= rSmall)
            throw std::exception();
        if (dist <= 0)
            throw std::exception();
        double radBig = rBig;
        double radSmall = rSmall;
        double distance = dist;
    }

    //setters
    Epycycloid& Epycycloid::setRBig(double r) {
        if (r<0 )
            throw std::exception();
        double radBig = r;
        return *this;

    }
    Epycycloid& Epycycloid::setRSmall(double r) {
        if (r<0)
            throw std::exception();
        double radSmall = r;
        return *this;
    }
    Epycycloid& Epycycloid::setDist(double dist) {
        if (dist<0)
            throw std::exception();
        double distance = dist;
        return *this;
    }
    //getters

    //other methods
    Point Epycycloid::pointOfAngle(double angle) const {
        Point *point = new Point;

        double rbig = getRBig();
        double rsmall = getRSmall();
        double k = rbig/rsmall;

        point->x = rsmall*(k+1)*(cos(angle) - ((cos((k+1)*angle))/(k+1)));
        point->y = rsmall*(k+1)*(sin(angle) - ((sin((k+1)*angle))/(k+1)));
        return *point;
    }
    //формула радиуса кривизны
    double Epycycloid::curvRadiusOfAngle(double angle) const  {
        double x1, x2, y1, y2, r;
        double rbig = getRBig();
        double rsmall = getRSmall();
        double k = rbig/rsmall;

        x1 = rsmall*(k+1)*(-sin(angle) + sin(angle*(k+1)));
        x2 = rsmall*(k+1)*(-cos(angle) + (1+k)*cos(angle*(k+1)));

        y1 = rsmall*(k+1)*(cos(angle) + ((k-1)/(k+1))*cos(angle*(k-1)));
        y2 = rsmall*(k+1)*(-sin(angle) - ((k-1)*(k-1)/(k+1))*sin(angle*(k-1)));

        r = (sqrt(pow((x1*x1 + x2*x2), 3)))/(abs(x1*y2 - y1*x2));
        return r;
    }
    //формула секториальной площади кривизны
    double Epycycloid::sectorArea(double angle) const {
        double x1, y1,  s;
        double rbig = getRBig();
        double rsmall = getRSmall();
        double k = rbig/rsmall;

        x1 = rsmall*(k+1)*(-sin(angle) + sin(angle*(k+1)));

        y1 = rsmall*(k+1)*(cos(angle) + ((k-1)/(k+1))*cos(angle*(k-1)));

        s = rsmall*(k+1)*(angle + 2*((k-1)/(k+1))*((sin(angle*(k+2)))/(2*k+4) + sin(k*angle)/2*k) - sin(k*angle)/2 + (sin((2*k+2)*angle))/(2*(k+2)) + angle/2 - (sin((2*k+2)*angle))/(4*(k+1)) + pow(((k-1)/(k+1)), 2)*(((sin((2*k+2)*angle)) + (2*k+2)*angle)/(4*k+4)));

        return s;

    }
    
}
