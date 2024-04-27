#ifndef simulation
#define simulation
#include <iostream>
#include <vector>
#include "rendu1.cpp"
using namespace std;
class Corail{
    int id;
    base position;
    string status;
    string direction_retation;
    string status_devlop;
    int nbr_segment;
    float effecteur;
    vector<segment> segment;
    int age;
};



#endif
