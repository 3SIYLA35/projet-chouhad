#ifndef lifeform
#define lifeform
#include <cmath>
#include <vector>
#include "../rendu1.cc"
#include <iostream>
using namespace std;

class lifeforme {
protected:
    base position;
    int age;

 public:
    lifeforme():age(1){
        position.x=rand() % (int)(dmax-1)+1;
        position.y=rand() % (int)(dmax-1)+1;;
    }
    ~lifeforme(){}

    base getPosition(){return position;}
    int getAge(){return age;}
};




class alg:public lifeforme{
   public:
   alg():lifeforme(){}
   bool algue_dead(){return age>=alg_birth_rate;}
  };

class corail:public lifeforme{
    private:
    vector<segment> segments;
    static int unique;
    static vector<int> tab_id;
    int id;
    enum Status_cor status;
    enum Dir_rot_cor dr_rotation;
    enum Status_dev status_dev;
    int nbr_seg=0;
    float effecteur=0;
    public:
    corail():lifeforme(){
        position.x=rand()% (int)(dmax -2);
        position.y=rand()%(int)(dmax-2);
        unique++;
        id=unique;
        tab_id.push_back(id);
        segments.push_back(t);
        nbr_seg++;
        status=ALIVE;
        status_dev=REPRO;
        effecteur=getlongeur();
        age=1; 
    }
    float getlongeur(){

        for (int i=1;i<=nbr_seg;i++){
              effecteur+=segments[i].getlongueur();
        }
        return effecteur;
    }
    base getpos(){return position;};
    vector<segment> getsegment(){return segments;} 
    int getage(){return age;}
    int getid(){return id;}
    int get_nbrseg(){return nbr_seg;}
    float getefecteur(){return effecteur;}
    string segment_consecutive(segment &, segment &);
    string check_age();
    string check_lenght();
    string check_angle();//---------------
    string check_id();
};
int corail::unique=0;


class scavanger:public lifeforme{
    int rayon;
    public:
    scavanger():lifeforme(){
    
    }
    string check_raduis();

}

#endif 
