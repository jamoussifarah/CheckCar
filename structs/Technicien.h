//
// Created by zairi on 10/9/2024.
//



#ifndef TECHNICIEN_H
#define TECHNICIEN_H
#include "Client.h"
struct Technicien {
    char nom[MAX_STRING_LENGTH];
    char prenom[MAX_STRING_LENGTH];
    char adresse[MAX_STRING_LENGTH];
    char ville[MAX_STRING_LENGTH];
    char CIN[MAX_CIN_LENGTH];
    char telephone[MAX_TELEPHONE_LENGTH];
    char email[MAX_EMAIL_LENGTH];
};

typedef struct Technicien TECHNICIEN;
#endif //TECHNICIEN_H
