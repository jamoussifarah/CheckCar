//
// Created by zairi on 10/9/2024.
//

#ifndef NOTIFICATION_CLIENT_H
#define NOTIFICATION_CLIENT_H
#include "Client.h"
#include "date.h"
enum typeNotification {
    RAPPEL,
    PROMOTION,
    ALERT,
    INFO,
    AUTRE
};
struct Notification_Client {
    CLIENT *client;
    char message[MAX_DESCRIPTION_LENGTH];
    Date date;
    enum typeNotification type;
};

#endif //NOTIFICATION_CLIENT_H
