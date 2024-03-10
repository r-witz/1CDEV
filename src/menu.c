#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "../include/display.h"
#include "../include/input.h"
#include "../include/player.h"
#include "../include/starter.h"
#include "../include/battle.h"
#include "../include/shop.h"
#include "../include/pokecenter.h"

void ask_name(Player *ptrPlayer);
void supemon_choose_menu(Player *ptrPlayer);
void leave_game(Player *ptrPlayer);

Player* ask_new_game() {
    int choice;

    write(1, "+------------------------------+\n", 34);
    write(1, "|  What do you want to do ?    |\n", 34);
    write(1, "|    1. New Game               |\n", 34);
    write(1, "|    2. Load Game              |\n", 34);
    write(1, "+------------------------------+\n", 34);
    
    Player *ptrPlayer = NULL;

    do {
      get_input("1 or 2: ", &choice, 'i', 3);

      switch (choice) {
          case 1:
              ptrPlayer = createPlayer();
              ask_name(ptrPlayer);
              ask_supemon(ptrPlayer); 
              break;
          case 2:
              ptrPlayer = loadPlayer("backup/player.json");
              if (ptrPlayer == NULL) {
              write(1, "You have no save, loading a new game...\n", 40);
                  ptrPlayer = createPlayer();
                  ask_name(ptrPlayer); 
                  ask_supemon(ptrPlayer);
              }
              break;
          default:
              write(1, "Please enter a number between 1-2\n", 34);
      }      
    } while(choice != 1 && choice != 2);
    return ptrPlayer;
}

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


void ask_where_to_go(Player *ptrPlayer) {
    main_menu();
    
    short choice;
    short alive_supemon;

    do {
        get_input("1, 2, 3 or 4: ", &choice, 'i', 3);

        switch (choice) {
            case 1:
                for (int i=0; i<6; i++) {
                    alive_supemon = 0;
                    if (ptrPlayer->supemons[i] != 0) {
                        if (ptrPlayer->supemons[i]->hp > 0) {
                            alive_supemon = 1;
                            supemon_choose_menu(ptrPlayer);
                            break;
                        }
                    }
                }
                if (alive_supemon == 0) {
                    write(1, "You have no alive Supemon, please go to the Pokecenter before fighting\n", 71);
                }
                break;
            case 2:
                shop(ptrPlayer);
                break;
            case 3:
                pokecenter(ptrPlayer);
                break;
            case 4:
                leave_game(ptrPlayer);
                break;
            default:
                write(1, "Please enter a number between 1-4\n", 34);
        }
    } while(1);
}

int is_supemon_available(Player *ptrPlayer, int index) {
    if (1 <= index && index <= 6) {
        if (ptrPlayer->supemons[index-1] != NULL) {
            if (ptrPlayer->supemons[index-1]->hp > 0) {
                return 1;
            } else {
                write(1, "Your Supemon is K.O.\n", 21);
                return 0;
            }
        } else {
            write(1, "No supemon at this position in your team\n", 41);
            return 0;
        }
    }
    return 0;
}

void supemon_choose_menu(Player *ptrPlayer) {
    write(1, "Your supemon team :\n", 20);

    for (int i = 0; i < 6; i++) {
        char bufferStr[7];
        sprintf(bufferStr, "%d", i+1);
        write(1, bufferStr, strlen(bufferStr));
        write(1, ". ", 2);
        if (ptrPlayer->supemons[i] != NULL) {
            write(1, ptrPlayer->supemons[i]->name, strlen(ptrPlayer->supemons[i]->name));
            write(1, " lvl.", 5);
            sprintf(bufferStr, "%d", ptrPlayer->supemons[i]->level);
            write(1, bufferStr, strlen(bufferStr));
            write(1, " (", 2);
            sprintf(bufferStr, "%d", ptrPlayer->supemons[i]->hp);
            write(1, bufferStr, strlen(bufferStr));
            write(1, "/", 1);
            sprintf(bufferStr, "%d", ptrPlayer->supemons[i]->max_hp);
            write(1, bufferStr, strlen(bufferStr));
            write(1, "HP)\n", 4);
        } else {
            write(1, "EMPTY\n", 7);
        }
    }

    write(1, "7. Cancel\n", 10);

    short choice;

    do {
        get_input("Which supemon do you want to summon (1-7): ", &choice, 'i', 3);

        switch (choice) {
            case 0:
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
                if (is_supemon_available(ptrPlayer, choice)) {
                    ptrPlayer->items_used = 0;
                    fight(ptrPlayer);
                    return;
                }
                break;
            case 7:
                write(1, "You canceled\n", 13);
                main_menu();
                return;
            default:
                write(1, "Please enter a number between 0-6\n", 35);
        }
    } while (1);
}



void leave_game(Player *ptrPlayer) {
    quit_menu();
    
    short choice;

    do {
        get_input("1, 2 or 3: ", &choice, 'i', 3);

        switch (choice) {
            case 1:
                savePlayer("backup/player.json", ptrPlayer);
                write(1, "Game sucessfully saved !\n", 25);
                write(1, "Thank you for playing hope we see you soon again\n", 49);
                for (int i=0; i<0; i++) {write(1, "OK\n", 3);}
                freePlayer(ptrPlayer);
                exit(0);
                break;
            case 2:
                write(1, "Thank you for playing hope we see you soon again\n", 49);
                freePlayer(ptrPlayer);
                exit(0);
                break;
            case 3:
                main_menu();
                break;
            default:
                write(1, "Please enter a number between 1-3\n", 34);
        }
    } while (choice != 3);
}
