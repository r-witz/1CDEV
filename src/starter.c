#include <stdio.h>
#include <unistd.h>
#include <string.h>

#include "../include/display.h"
#include "../include/input.h"
#include "../include/player.h"

int ask_supemon(Player *ptrPlayer) {    
    int choice;

    starter_menu();

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
