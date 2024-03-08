#include <stdio.h>
#include <unistd.h>
#include <string.h>

#include "../include/starter.h"

void empty_buffer();
Supemon *getSupemonByID(int id);

int ask_supemon(Player *ptrPlayer) {
    char choice[3];

    do {
        write(1, "+---------------------+\n" , 24);
        write(1, "|Choose your Supemon: |\n", 24);
        write(1, "|    1. Supmander     |\n", 24);
        write(1, "|    2. Supasaur      |\n", 24);
        write(1, "|    3. Supirtle      |\n", 24);
        write(1, "+---------------------+\n" , 24);

        write(1, "1, 2 or 3 : ", 12);
        fgets(choice, sizeof(choice), stdin);
        choice[strcspn(choice, "\n")] = '\0';

        empty_buffer();

        ptrPlayer->supemons[0] =    strcmp(choice, "1") == 0 ? getSupemonByID(1) :
                                    strcmp(choice, "2") == 0 ? getSupemonByID(2) :
                                    strcmp(choice, "3") == 0 ? getSupemonByID(3) : NULL;

        if (strcmp(choice, "1") != 0 && strcmp(choice, "2") != 0 && strcmp(choice, "3") != 0){
            write(1, "Please enter a number between 1-3\n", 34);
            continue;
        }
    } while (strcmp(choice, "1") != 0 && strcmp(choice, "2") != 0 && strcmp(choice, "3") != 0);
    printf("You chose %s\n", ptrPlayer->supemons[0]->name);
    return 0;
}