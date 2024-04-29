#ifndef lifeform
#define lifeform
#include <vector>
#include "../rendu1.cc"
using namespace std;

class corail{
    private:
    vector<segment> segment;
    int age;
    static int unique;
    enum Status_cor status;
    enum Dir_rot_cor dr_rotation;
    enum Status_dev status_dev;
    int nbr_seg=0;
    float effecteur=0;
    public:
    corail(){
        segment.pop_back();
        status=ALIVE;
        status_dev=REPRO;
        effecteur=getlongeur();
        age=1;
    }
    float getlongeur(){

        for (int i=1;i<=nbr_seg;i++){
              effecteur+=segment[i].getlongueur();
        }
        return effecteur;
    }
};
int corail::unique=0;

#endif 
