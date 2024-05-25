#include <iostream>
#include <stdlib.h>
#include <vcruntime.h>
#include "lifeform.h"
#include "../message.h"
#include "../shape.h"


void lifeforme::check_age(){
    if(age<0){
        cout << message::lifeform_age(age);
        exit(EXIT_FAILURE);
    } 
};

int corail::unique = 0;

void lifeforme::check_lenght(){
    if(effecteur>=l_seg_interne && effecteur<=l_repro){
        cout << message::segment_length_outside(id,effecteur);
        exit(EXIT_FAILURE);
    }
}
void corail::check_angle(int id, double a){
    if (seg[i].angle < -M_PI || seg[i].angle > M_PI){
        cout << message::segment_angle_outside(id, a);
    }
}

void corail::check_id(){
    for(auto i  : tab_id){
        if(id==i)
        {cout<<"id duplicated";
        exit(-1);}
    }
    cout << message::lifeform_duplicated_id(id);
}

void corail::check_lenght(){
    if (segments[i]. < l_repro - l_seg_interne || seg[i].longueur >= l_repro){
        cout << message::segment_length_outside(id, )
        exit(EXIT_FAILURE);
    }
}

void scavanger::check_raduis(){
    if (rayon < r_sca || rayon >= r_sca_repro){
        cout << message::scavanger_radius_outside(rayon);
        exit(EXIT_FAILURE);
    }
}