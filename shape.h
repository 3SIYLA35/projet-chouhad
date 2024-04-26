#ifndef shape
#define shape
#include <iostream>
#include <cmath>
#include "PI.H"
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
    base extr(){
        double x=point.x+longueur*cos(angle);
        double y=point.y+longueur*sin(angle);
        return {x,y};
    };
    float get_angle(){return angle;}
    base get_base(){return point;}
};
float ecart_angulaire( segment & A,segment& B){
        float diff=A.get_angle()-B.get_angle();
        if(diff>Pi)
            diff=2*Pi-diff;
        else
            diff=2*Pi+diff;
        return diff;
    }
bool intersection(segment& A,segment& B){
        float prod_vectoriel1 = (B.extr().x-A.get_base().x)*(A.get_base().y-B.get_base().y)-
                                (A.get_base().x-B.get_base().x)*(B.extr().y-A.get_base().y);
        float prod_vectoriel2 = (A.extr().x-A.get_base().x)*(A.get_base().y-B.get_base().y)-
                                (A.get_base().x-B.get_base().x)*(A.extr().y-A.get_base().y);
                                
    }


#endif 







