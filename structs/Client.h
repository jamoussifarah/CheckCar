#ifndef CLIENT_H
#define CLIENT_H

#define MAX_CIN_LENGTH 9
#define MAX_DESCRIPTION_LENGTH 256
#define MAX_STRING_LENGTH 60
#define MAX_EMAIL_LENGTH 50
#define MAX_TELEPHONE_LENGTH 9

struct Client {
    char nom[MAX_STRING_LENGTH];
    char prenom[MAX_STRING_LENGTH];
    char adresse[MAX_STRING_LENGTH];
    char ville[MAX_STRING_LENGTH];
    char CIN[MAX_CIN_LENGTH];
    char telephone[MAX_TELEPHONE_LENGTH];
    char email[MAX_EMAIL_LENGTH];
};
typedef struct Client CLIENT;

#define MAX_CLIENTS 100
extern CLIENT *clients;

// Function declarations
void remplirClient(CLIENT *client, char nom[], char prenom[], char adresse[], char ville[], char CIN[], char telephone[], char email[]);
void initialize_clients();
void add_client_to_table(CLIENT client, int *client_count);

#endif // CLIENT_H