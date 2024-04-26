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
    double angularGap=ecart_angulair(segment1, segment2);
    return fabs(angularGap)<EPSILON;
}
bool itersection( segment& segment1,segment& segment2) {
    base end1=segment1.extr();
    base end2=segment2.extr();
    return (end1.x>=segment2.getX() && end2.x>=segment1.getX() &&
            end1.y>=segment2.getY() && end2.y>=segment1.getY());
}

int orientation(base p,base q,base r) 
{
    double val=(q.y-p.y)*(r.x-q.x)-(q.x-p.x)*(r.y-q.y);
    double pq_Norm =sqrt((q.x-p.x)*(q.x-p.x)+(q.y-p.y)*(q.y-p.y));
    double distance =val/pq_Norm;
    if (fabs(distance)<EPSILON) {
        return 0; 
    }
    return (val > 0)?1:-1; 
}
double produitvectoriel(const S2d& v1, const S2d& v2) {
    return v1.x * v2.x + v1.y * v2.y;
}
double norm(const S2d& v) {
    return sqrt(v.x*v.x+v.y*v.y);
}
bool onSegment(const S2d& p, const S2d& q, const S2d& r) {
    S2d pr = {r.x-p.x, r.y-p.y};
    S2d pq = {q.x-p.x, q.y-p.y};
    double dot =produitvectoriel(pr, pq);
    double prNorm =norm(pr);
    double projection =dot/prNorm;
    return (projection >=-EPSILON && projection<=prNorm+EPSILON);
}
#endif 







