#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#include "../include/player.h"
Supemon *getSupemonByID(int id);

void get_input(char *prompt, void *output, char type, const int BUFFER_SIZE);

void ask_name(Player *ptrPlayer) {
    char name[12];

    int isValid = 0;
    size_t nameLength;

    do {
        get_input("What's your name ? ", name, 's', 12);
        nameLength = strlen(name);

        for (size_t i = 0; i < nameLength; ++i) {
            if (!isalpha(name[i]) || nameLength > 12) {
                isValid = 0;
                break;
            }
            isValid = 1;
        }

        if (nameLength == 0 || !isValid) {
            write(1, "Please enter a valid name (letters only, max 12 characters)\n", 60);
        }

    } while (nameLength == 0 || !isValid);

    ptrPlayer->name = (char *)malloc(nameLength + 1);
    strcpy(ptrPlayer->name, name);

    write(1, "Welcome ", 8);
    write(1, ptrPlayer->name, strlen(ptrPlayer->name));
    write(1, " in Supemon World!\n", 19);
}

