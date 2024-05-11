#include <iostream>
#include <cmath>
#include "constantes.h"
#include "shape.h"
using namespace std;

typedef struct S2d {double x=0.; double y=0.;}base ;
class segment{
    private:
    base point;
    float angle;
    float longueur;
    public:
    segment(){
        point.x=rand() % (int)(dmax -2);
        point.y=rand() % (int)(dmax -2);
        angle = (rand())/(RAND_MAX)*2*PI; // Angle entre 0 et 2*PI
        longueur = (rand()%(int)(dmax)); 
        
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