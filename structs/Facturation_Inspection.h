//
// Created by zairi on 10/9/2024.
//

#ifndef FACTURATION_INSPECTION_H
#define FACTURATION_INSPECTION_H
#include "Inspection.h"
#include "date.h"

enum statutFacturation {
    PAYE,
    NON_PAYE
};
enum modePaiement {
    ESPECE,
    CHEQUE,
    CARTE_BANCAIRE,
    VIREMENT
};

struct Facturation_Inspection {
    INSPECTION *inspection;
    float montant;
    Date date;
    enum modePaiement mode;
    enum statutFacturation statut;
};

typedef struct Facturation_Inspection FACTURATION_INSPECTION;
#endif //FACTURATION_INSPECTION_H
