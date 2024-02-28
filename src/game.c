#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#include "../include/player.h"
Supemon *getSupemonByID(int id);

#define NAME_MAX_LENGTH 50

void ask_name(Player *ptrPlayer) {
    char name[NAME_MAX_LENGTH];

    do {
        write(1, "What's your name? ", 18);
        fgets(name, sizeof(name), stdin);
        name[strcspn(name, "\n")] = '\0';

        if (strlen(name) == 0) {
            write(1, "Please enter a valid name.\n", 27);
            continue;
        }

        ptrPlayer->name = (char*)malloc(strlen(name) + 1);
        strcpy(ptrPlayer->name, name);
    } while (strlen(name) == 0);
    
    write(1, "Welcome in Supemon World ! ", 28);
    write(1, ptrPlayer->name, strlen(ptrPlayer->name));
    write(1, "\n", 1); 
}