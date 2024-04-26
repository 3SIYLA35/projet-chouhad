#ifndef shape
#define shape
#include <iostream>
#include "rendu1.cpp"
#include <cmath>
#include "PI.H"
#define EPSILON 1e-9
 using namespace std;


double ecart_angulair( segment& segment1, segment& segment2) {
    base end1 = segment1.extr();
    base end2 = segment2.extr();
    double angle1=atan2(end1.y-segment1.getY(), end1.x-segment1.getX());
    double angle2=atan2(end2.y-segment2.getY(),end2.x-segment2.getX());
     double angular = angle2 - angle1;
    while(angular>Pi){angular-=2*Pi;}
    while (angular<=-Pi){angular+=2*Pi;};
    return angular;
};
bool super_pos( segment& segment1,  segment& segment2) {
    double angularGap = ecart_angulair(segment1, segment2);
    return fabs(angularGap) < EPSILON;
}
int orientation(base p,base q,base r) 
{
    int val=(q.y-p.y)*(r.x-q.x)-(q.x-p.x)*(r.y-q.y); 
    if (val==0) return 0;
  
    return (val > 0)? 1: 2; 
}
bool intersection(segment& A,segment& B){
        float prod_vectoriel1 = (B.extr().x-A.get_base().x)*(A.get_base().y-B.get_base().y)-
                                (A.get_base().x-B.get_base().x)*(B.extr().y-A.get_base().y);
        float prod_vectoriel2 = (A.extr().x-A.get_base().x)*(A.get_base().y-B.get_base().y)-
                                (A.get_base().x-B.get_base().x)*(A.extr().y-A.get_base().y);
                                
    }


#endif 
