#ifndef shape
#define shape
#include <iostream>
 using namespace std;

typedef struct S2d {double x=0.; double y=0.;}base ;
class segment{
    private:
    base point;
    float angle;
    float longueur;
    public:
    segment(float poix,float poiy,float ang,float lon)
    :angle(ang),longueur(lon),point(poix,poiy){};
    float getangle(){return angle;}
    float getlongueur(){return longueur;}
    void affiche(){
    }
    float extr_x(){
        return point.x+longueur*cos(angle);
    };
    float extr_y(){
        return point.y+longueur*sin(angle);
    };
};


#endif 
