#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#include "../include/player.h"
Supemon *getSupemonByID(int id);

#define NAME_MAX_LENGTH 50
#define MAX_NAME_LENGTH 12

void ask_name(Player *ptrPlayer) {
    char buffer[NAME_MAX_LENGTH];
    char name[MAX_NAME_LENGTH + 1];

    int isValid = 0;
    size_t nameLength;

    do {
        write(1, "What's your name? ", 18);
        fgets(buffer, sizeof(buffer), stdin);
        buffer[strcspn(buffer, "\n")] = '\0';
        strncpy(name, buffer, sizeof(name));

        nameLength = strlen(name);

        for (size_t i = 0; i < nameLength; ++i) {
            if (!isalpha(name[i]) || nameLength > MAX_NAME_LENGTH) {
                isValid = 0;
                break;
            }
            isValid = 1;
        }

        if (nameLength == 0 || !isValid) {
            write(1, "Please enter a valid name (letters only, max 12 characters) : ", 63);
        }

    } while (nameLength == 0 || !isValid);

    ptrPlayer->name = (char *)malloc(nameLength + 1);
    strcpy(ptrPlayer->name, buffer);

    write(1, "Welcome in Supemon World! ", 27);
    write(1, ptrPlayer->name, strlen(ptrPlayer->name));
    write(1, "\n", 1);
}

