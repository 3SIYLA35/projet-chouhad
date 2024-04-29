#include <iostream>
#include <cmath>
#include "constantes.h"
using namespace std;

typedef struct S2d {double x=0.; double y=0.;}base ;
class segment{
    private:
    base point;
    float angle;
    float longueur;
    public:
    segment(){
        point.x=round() % (int)(dmax -2);
        point.y=round() % (int)(dmax -2);
        longueur=sqrt();
        
    };
    float getangle(){return angle;}
    float getlongueur(){return longueur;}
    double getX(){return point.x;}
    double getY(){return point.y;}
    void affiche(){
    }
    base extr(){
        double x=point.x+longueur*cos(angle);
        double y=point.y+longueur*sin(angle);
        return {x,y};
    };
    base get_base(){return point;}
}; 