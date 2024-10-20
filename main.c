#include <stdio.h>
#include <stdlib.h>

// Inclusion des fichiers de structure
#include <locale.h>
#include "structs/Technicien.h"
#include "structs/Vehicule.h"
#include "structs/Critere.h"
#include "structs/Inspection.h"

int main() {
    setlocale(LC_ALL, "");
    int n;  // Nombre d'inspections
    printf("Entrez le nombre d'inspections : ");
    scanf("%d", &n);
    getchar();  // Consomme le caractère '\n' restant dans le buffer

    // Allocation dynamique pour un tableau de 'n' inspections
    INSPECTION* inspections = (INSPECTION*)malloc(n * sizeof(INSPECTION));
    if (inspections == NULL) {
        printf("Échec de l'allocation mémoire.\n");
        return 1;
    }

    // Saisie des informations pour chaque inspection
    for (int i = 0; i < n; i++) {
        INSPECTION* currentInspection = &inspections[i];  // Pointeur vers l'inspection actuelle
        printf("\n--- Saisie de l'Inspection %d ---\n", i + 1);

        // Allocation mémoire pour le véhicule
        currentInspection->vehicule = (VEHICULE*)malloc(sizeof(VEHICULE));
        if (currentInspection->vehicule == NULL) {
            printf("Échec de l'allocation mémoire pour le véhicule.\n");
            free(inspections);  // Libération mémoire en cas d'erreur
            return 1;
        }

        // Saisie des informations du véhicule
        printf("Marque du vehicule : ");
        scanf("%s", currentInspection->vehicule->marque);
        printf("Modele du vehicule : ");
        scanf("%s", currentInspection->vehicule->modele);
        printf("Immatriculation : ");
        scanf("%s", currentInspection->vehicule->immatriculation);
        printf("Annee : ");
        scanf("%d", &currentInspection->vehicule->annee);
        printf("Kilometrage : ");
        scanf("%d", &currentInspection->vehicule->kilometrage);

        // Allocation mémoire pour le client
        currentInspection->vehicule->proprietaire = (CLIENT*)malloc(sizeof(CLIENT));
        if (currentInspection->vehicule->proprietaire == NULL) {
            printf("Échec de l'allocation mémoire pour le client.\n");
            free(inspections);  // Libération mémoire en cas d'erreur
            return 1;
        }

        // Saisie des informations du client
        printf("Nom du client : ");
        scanf("%s", currentInspection->vehicule->proprietaire->nom);
        printf("Prenom du client : ");
        scanf("%s", currentInspection->vehicule->proprietaire->prenom);
        printf("Email du client : ");
        scanf("%s", currentInspection->vehicule->proprietaire->email);
        printf("Telephone du client : ");
        scanf("%s", &currentInspection->vehicule->proprietaire->telephone);
        printf("Ville du client : ");
        scanf("%s", &currentInspection->vehicule->proprietaire->ville);

        // Allocation mémoire pour le technicien
        currentInspection->technicien = (TECHNICIEN*)malloc(sizeof(TECHNICIEN));
        if (currentInspection->technicien == NULL) {
            printf("Échec de l'allocation mémoire pour le technicien.\n");
            free(currentInspection->vehicule);  // Libération mémoire pour le véhicule
            free(inspections);  // Libération mémoire en cas d'erreur
            return 1;
        }

        // Saisie des informations du technicien
        printf("Nom du technicien : ");
        scanf("%s", currentInspection->technicien->nom);
        printf("Prenom du technicien:\n");
        scanf("%s", currentInspection->technicien->prenom);

        // Saisie du nombre de critères
        printf("Nombre de criteres : ");
        if (scanf("%d", &currentInspection->nombreCriteres) != 1) {
            printf("Erreur de saisie.\n");
            free(currentInspection->technicien);
            free(currentInspection->vehicule);
            free(inspections);  // Libération mémoire en cas d'erreur
            return 1;
        }
        getchar();  // Consomme le caractère '\n' restant

        // Allocation dynamique pour les critères
        currentInspection->criteres = (CRITERE*)malloc(currentInspection->nombreCriteres * sizeof(CRITERE));
        if (currentInspection->criteres == NULL) {
            printf("Échec de l'allocation mémoire pour les criteres.\n");
            free(currentInspection->technicien);
            free(currentInspection->vehicule);
            free(inspections);  // Libère la mémoire du tableau d'inspections
            return 1;
        }

        // Saisie des critères
        for (int j = 0; j < currentInspection->nombreCriteres; j++) {
            CRITERE* currentCritere = &currentInspection->criteres[j];
            printf("\nCritere %d:\n", j + 1);
            printf("Nom : ");
            scanf("%s", currentCritere->nom);
            printf("Description : ");
            scanf("%s", currentCritere->description);
            printf("Coefficient : ");
            scanf("%d", &currentCritere->coefficient);
        }

        // Saisie du statut de l'inspection
        printf("Statut de l'inspection (0 = EN_COURS, 1 = TERMINE, 2 = ANNULE) : ");
        scanf("%d", (int*)&currentInspection->statut);
    }

    // Affichage de toutes les inspections et leurs critères
    printf("\n=== Affichage de toutes les inspections ===\n");
    for (int i = 0; i < n; i++) {
        INSPECTION* currentInspection = &inspections[i];

        printf("\n--- Inspection %d ---\n", i + 1);
        printf("Vehicule: %s %s, Immatriculation: %s, Annee: %d, Kilometrage: %d km\n",
               currentInspection->vehicule->marque,
               currentInspection->vehicule->modele,
               currentInspection->vehicule->immatriculation,
               currentInspection->vehicule->annee,
               currentInspection->vehicule->kilometrage);
        printf("Client: %s %s, Email: %s, Telephone: %s, Ville: %s km\n",
              currentInspection->vehicule->proprietaire->prenom,
              currentInspection->vehicule->proprietaire->nom,
              currentInspection->vehicule->proprietaire->email,
              currentInspection->vehicule->proprietaire->telephone,
              currentInspection->vehicule->proprietaire->ville);
        printf("Technicien: %s %s\n",
               currentInspection->technicien->nom,
               currentInspection->technicien->prenom);

        printf("Statut de l'inspection: ");
        switch (currentInspection->statut) {
            case EN_COURS: printf("EN_COURS\n"); break;
            case TERMINÉ: printf("TERMINE\n"); break;
            case ANNULE: printf("ANNULE\n"); break;
            default: printf("Inconnu\n"); break;
        }

        printf("Criteres:\n");
        for (int j = 0; j < currentInspection->nombreCriteres; j++) {
            CRITERE* currentCritere = &currentInspection->criteres[j];

            printf("  Critere %d: %s (%s), Coefficient: %d\n",
                   j + 1,
                   currentCritere->nom,
                   currentCritere->description,
                   currentCritere->coefficient);
        }
    }

    // Libération de la mémoire allouée
    for (int i = 0; i < n; i++) {
        free(inspections[i].criteres);  // Libère les critères de chaque inspection
        free(inspections[i].technicien);  // Libère le technicien de chaque inspection
        free(inspections[i].vehicule);  // Libère le véhicule de chaque inspection
    }
    free(inspections);  // Libère le tableau d'inspections

    return 0;
}
