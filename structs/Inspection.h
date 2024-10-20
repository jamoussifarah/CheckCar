//
// Created by zairi on 10/9/2024.
//

#ifndef INSPECTION_H
#define INSPECTION_H
#include "Critere.h"
#include "Technicien.h"
#include "Vehicule.h"
#include  "date.h"

enum statutInspection {
    EN_COURS,
    TERMINÉ,
    ANNULE
};
struct Inspection {
    VEHICULE *vehicule;
    TECHNICIEN *technicien;
    CRITERE *criteres;
    int nombreCriteres;
    Date date;
    char remarques[MAX_DESCRIPTION_LENGTH];
    enum statutInspection statut;
};

typedef struct Inspection INSPECTION;

#endif //INSPECTION_H
