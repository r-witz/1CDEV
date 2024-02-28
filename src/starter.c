#include <stdio.h>
#include <unistd.h>
#include <string.h>

#include "../include/starter.h"

void empty_buffer();
Supemon *getSupemonByID(int id);

int ask_supemon(Player *ptrPlayer) {
    char choice[3];
    char buffer[100];

    do {
        write(1, "+---------------------+\n" , 24);
        write(1, "|Choose your Supemon: |\n", 24);
        write(1, "|    1. Supmander     |\n", 24);
        write(1, "|    2. Supasaur      |\n", 24);
        write(1, "|    3. Supirtle      |\n", 24);
        write(1, "+---------------------+\n" , 24);
        write(1, "1, 2 or 3 : ", 12);

        fgets(buffer, sizeof(buffer), stdin);
        buffer[strcspn(buffer, "\n")] = '\0';
        strncpy(choice, buffer, sizeof(choice));
        choice[sizeof(choice) - 1] = '\0';

        ptrPlayer->supemons[0] =    strcmp(choice, "1") == 0 ? getSupemonByID(1) :
                                    strcmp(choice, "2") == 0 ? getSupemonByID(2) :
                                    strcmp(choice, "3") == 0 ? getSupemonByID(3) : NULL;

        if (ptrPlayer->supemons[0] == NULL) {
            write(1, "INCORRECT\n", 10);
        }
    } while (strcmp(choice, "1") != 0 && strcmp(choice, "2") != 0 && strcmp(choice, "3") != 0);
    printf("You chose %s\n", ptrPlayer->supemons[0]->name);
    return 0;
}