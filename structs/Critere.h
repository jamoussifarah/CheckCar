//
// Created by zairi on 10/9/2024.
//

#ifndef CRITERE_H
#define CRITERE_H
#include <stdbool.h>

#include "Client.h"

enum CritereType {
    MECANIQUE,
    ELECTRIQUE,
    CARROSSERIE,
    PEINTURE,
    PNEUMATIQUE,
    ECLAIRAGE,
    VISIBILITE,
    FREINAGE,
    EMISSION,
    SECURITE,
    CONFORT,
    AUTRE
};
enum statut {
    REUSSI,
    ECHEC
};
struct Critere {
    char nom[MAX_STRING_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    int coefficient;
    enum CritereType type;
    enum statut statut;
};


typedef struct Critere CRITERE;

#endif //CRITERE_H
