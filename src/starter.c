#include <stdio.h>
#include <unistd.h>
#include <string.h>

#include "../include/starter.h"

Supemon *getSupemonByID(int id);
void get_input(char *prompt, void *output, char type, const int BUFFER_SIZE);

int ask_supemon(Player *ptrPlayer) {    
    int choice;

    write(1, "+------------------------------+\n", 33);
    write(1, "|  Choose your Supemon :       |\n", 33);
    write(1, "|    1. Supmander              |\n", 33);
    write(1, "|    2. Supasaur               |\n", 33);
    write(1, "|    3. Supirtle               |\n", 33);
    write(1, "+------------------------------+\n", 33);

    do {
        get_input("1, 2 or 3: ", &choice, 'i', 3);

        ptrPlayer->supemons[0] =  choice == 1 ? getSupemonByID(1) :
                                  choice == 2 ? getSupemonByID(2) :
                                  choice == 3 ? getSupemonByID(3) : NULL;

        if (ptrPlayer->supemons[0] == NULL) {
            write(1, "Please enter a number between 1-3\n", 34);
            continue;
        } else {
            break;
        }
    } while (1); 

    printf("You chose %s\n", ptrPlayer->supemons[0]->name);
    return 0;
}
