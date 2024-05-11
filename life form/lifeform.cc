#include <iostream>
#include <stdlib.h>
#include <vcruntime.h>
#include "lifeform.h"
#include "../message.h"
#include "../shape.h"

string corail:: segment_consecutive(segment &segment1, segment &segment2){
    if(ecart_angulair(segment1,segment2)==0 && (ecart_angulair(segment1,
    segment2)>(-delta_rot) || ecart_angulair(segment1,segment2)<delta_rot)){
        message::segment_superposition(id,segment1.getlongueur(),segment2.getlongueur());
    }
    else{

    }
}
string corail::check_age(){
    if(age>0){
        return message::lifeform_age(age);
    }
    else{
        cout<<age <<"est negative";
    }
};
string corail::check_lenght(){
    if(effecteur>=l_seg_interne && effecteur<=l_repro){
        return message::segment_length_outside(id,effecteur);
    }
    else{
        cout<<"la longeur est pas compris dans l'interval [l_repro-l_seg_interne, l_repro[";
    }
}
string corail::check_angle(){
    int compteur=0;
    for(int i(0);i<nbr_seg;i++){
         if(segments[i].getangle()>(-PI)&& segments[i].getangle()<PI)
         compteur++;
    }//------------------------------------------------------------------
    if(compteur==nbr_seg){
        return message::segment_angle_outside(id,orientation());
    }
}
string corail::check_id(){
    for(auto i  : tab_id){
        if(id==i)
        {cout<<"id duplicated";
        exit(-1);}
    }
    return message::lifeform_duplicated_id(id);
}
string scavanger::check_raduis(){
    
}