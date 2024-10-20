//
// Created by zairi on 10/9/2024.
//

#ifndef GARAGE_H
#define GARAGE_H
#include "Inspection.h"

struct Garage {
    char nom[MAX_STRING_LENGTH];
    char adresse[MAX_STRING_LENGTH];
    char ville[MAX_STRING_LENGTH];
    char telephone[MAX_TELEPHONE_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    INSPECTION *inspections;
    int nombreInspections;
};

typedef struct Garage GARAGE;
#endif //GARAGE_H
