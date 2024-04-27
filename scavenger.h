#ifndef scavenger 
#define scavenger
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

// Définition des constantes
const double delta_l = 0.1;     // Distance maximale par mise à jour
const double r_sca_repro = 0.5; // Rayon pour la reproduction
const double delta_r_sca = 0.1; // Augmentation du rayon par mise à jour
const double r_sca = 0.2;       // Rayon du scavenger
const int sca_life_max = 100;   // Âge maximum du scavenger

// Structure pour représenter les coraux
struct Coral
{
    double x;    // Position x
    double y;    // Position y
    bool isDead; // Statut du corail
};

// Classe pour représenter les scavengers
class Scavenger
{
private:
    double x;      // Position x
    double y;      // Position y
    double radius; // Rayon
    int age;       // Âge
    Coral *target; // Cible
    bool isEating; // Statut d'alimentation

public:
    Scavenger(double x, double y, double radius) : x(x), y(y), radius(radius), age(0), target(nullptr), isEating(false) {}

    // Méthode pour déplacer le scavenger vers sa cible
    void moveTowardsTarget()
    {
        if (target != nullptr)
        {
            double distToTarget = distance(x, y, target->x, target->y);
            if (distToTarget > delta_l)
            {
                double dx = (target->x - x) * delta_l / distToTarget;
                double dy = (target->y - y) * delta_l / distToTarget;
                x += dx;
                y += dy;
            }
            else
            {
                x = target->x;
                y = target->y;
            }
        }
    }

    // Autres méthodes nécessaires pour gérer l'état et le comportement du scavenger
    // ...
};

// Fonction pour calculer la distance entre deux points
double distance(double x1, double y1, double x2, double y2)
{
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

// Fonction pour trouver le corail mort le plus proche
Coral *findNearestDeadCoral(Scavenger scavenger, vector<Coral> &corals)
{
    Coral *nearest = nullptr;
    double minDist = numeric_limits<double>::max();
    for (auto &coral : corals)
    {
        if (coral.isDead)
        {
            double dist = distance(scavenger.x, scavenger.y, coral.x, coral.y);
            if (dist < minDist)
            {
                minDist = dist;
                nearest = &coral;
            }
        }
    }
    return nearest;
}

// Fonction pour simuler le comportement des scavengers
// void simulate(vector<Coral>& corals, vector);




#endif 