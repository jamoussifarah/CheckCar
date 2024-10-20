#ifndef VEHICULE_H
#define VEHICULE_H
#include "Client.h"
struct Vehicule {
    char marque[MAX_STRING_LENGTH];
    char modele[MAX_STRING_LENGTH];
    char immatriculation[MAX_STRING_LENGTH];
    int annee;
    int kilometrage;
    CLIENT *proprietaire;
};

typedef struct Vehicule VEHICULE;

#endif
