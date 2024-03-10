#include <stdio.h>
#include <unistd.h>
#include <string.h>

#include "../include/display.h"
#include "../include/input.h"
#include "../include/player.h"

void pokecenter(Player *ptrPlayer) {
    pokecenter_menu();
    
    short choice;

    do {
        get_input("1, 2 or 3: ", &choice, 'i', 3);

        switch (choice) {
            case 1:
                for (int i=0; i<6; i++) {
                    if (ptrPlayer->supemons[i] != 0) {
                        ptrPlayer->supemons[i]->hp = ptrPlayer->supemons[i]->max_hp;
                    }
                }
                write(1, "Your Supemons have been healed !\n", 33);
                break;
            case 2:
                for (int i=0; i<6; i++) {
                    if (ptrPlayer->supemons[i] != 0) {
                        char bufferStr[7];
                        write(1, ptrPlayer->supemons[i]->name, strlen(ptrPlayer->supemons[i]->name));
                        write(1, " lvl.", 5);
                        sprintf(bufferStr, "%d", ptrPlayer->supemons[i]->level);
                        write(1, bufferStr, strlen(bufferStr));
                        write(1, "\t(", 2);
                        sprintf(bufferStr, "%d", ptrPlayer->supemons[i]->hp);
                        write(1, bufferStr, strlen(bufferStr));
                        write(1, "/", 1);
                        sprintf(bufferStr, "%d", ptrPlayer->supemons[i]->max_hp);
                        write(1, bufferStr, strlen(bufferStr));
                        write(1, "HP)\n", 4);
                    }
                }
                break;
            case 3:
                main_menu();
                break;
            default:
                write(1, "Please enter a number between 1-3\n", 34);
        }
    } while (choice != 3);
}
