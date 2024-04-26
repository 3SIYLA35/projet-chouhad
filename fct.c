#ifndef fct

#include <iostream>





double ecart_angulair( segment& segment1, segment& segment2) {
    base end1 = segment1.extr();
    base end2 = segment2.extr();
    double angle1=atan2(end1.y-segment1.getY(), end1.x-segment1.getX());
    double angle2=atan2(end2.y-segment2.getY(),end2.x-segment2.getX());
     double angularGap = angle2 - angle1;
    while(angularGap>PI){angularGap -= 2 * PI};
    while (angularGap<= -PI) {angularGap += 2*PI};
    return angularGap;
}

#endif 