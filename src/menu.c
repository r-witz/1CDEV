#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#include "../include/player.h"
#include "../include/game.h"
#include "../include/starter.h"

void get_input(char *prompt, void *output, char type, const int BUFFER_SIZE);
void freePlayer(Player *player);
void main_menu();
void quit_menu();

void fight(Player *ptrPlayer);
void shop(Player *ptrPlayer);
void pokecenter(Player *ptrPlayer);
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

      if (choice == 1) {
        ptrPlayer = createPlayer();
        ask_name(ptrPlayer);
        ask_supemon(ptrPlayer); 
      } else if (choice == 2) {
        ptrPlayer = loadPlayer("backup/player.json");
        if (ptrPlayer == NULL) {
          write(1, "You have no save, loading a new game...\n", 40);
          ptrPlayer = createPlayer();
          ask_name(ptrPlayer); 
          ask_supemon(ptrPlayer);
        }
      } else {
          write(1, "Please enter a number between 1-2\n", 34);
      }
      
    } while(choice != 1 && choice != 2);
    
    return ptrPlayer;
}

void ask_where_to_go(Player *ptrPlayer) {
    main_menu();
    
    short choice;

    do {
        get_input("1, 2, 3 or 4: ", &choice, 'i', 3);

        switch (choice) {
            case 1:
                fight(ptrPlayer);
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
                for (int i=0; i<0; i++) {printf("OK\n");}
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

/*
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
                exit(0);
                break;
            case 2:
                write(1, "Thank you for playing hope we see you soon again\n", 49);
                exit(0);
                break;
            case 3:
                main_menu();
                break;
            default:
                write(1, "Please enter a number between 1-3\n", 34);
        }
    } while (choice != 1 && choice != 2 && choice != 3);
}*/
