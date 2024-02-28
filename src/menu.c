#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#include "../include/player.h"
#include "../include/game.h"
#include "../include/starter.h"

Player* execute_game_load(const char *choice);
void execute_choice(const char *choice2, Player *ptrPlayer);
void empty_buffer();
void fight(Player *ptrPlayer);
void shop(Player *ptrPlayer);
void pokecenter(Player *ptrPlayer);

void welcome() {
    write(1, "=========================================\n", 42);
    write(1, "   ___\n", 7);
    write(1, "  / __] _ _  ___  ___  _ _ _  ___  _ _\n", 40);
    write(1, "  \\__ \\| | || . \\/ ._]| ' ' |/ . \\| ' |\n", 40);
    write(1, "  [___/ \\__||  _/\\___.|_|_|_|\\___/|_|_|\n", 40);
    write(1, "            |_|\n\n", 17);
    write(1, "=========================================\n\n", 43);
}

Player* ask_new_game() {
    char choice[2];
    char buffer[100];
    write(1, "+----------------------------+\n", 32);
    write(1, "|  What do you want to do ?  |\n", 32);
    write(1, "|        1. New Game         |\n", 32);
    write(1, "|        2. Load Game        |\n", 32);
    write(1, "+----------------------------+\n", 32);

    do {
        write(1, "1 or 2 : ", 9);
        fgets(buffer, sizeof(buffer), stdin);
        buffer[strcspn(buffer, "\n")] = '\0';
        strncpy(choice, buffer, sizeof(choice));

        if (strcmp(choice, "1") != 0 && strcmp(choice, "2") != 0) {
            write(1, "Please enter a valid number.\n", 29);
            continue;
        }
    } while(strcmp(choice, "1") != 0 && strcmp(choice, "2") != 0);
    
    return execute_game_load(choice);
}

Player* execute_game_load(const char *choice) {
    if (strcmp(choice, "1") == 0) {
        Player *ptrPlayer = createPlayer();
        ask_name(ptrPlayer);
        ask_supemon(ptrPlayer);
        return ptrPlayer;
    } else if (strcmp(choice, "2") == 0) {
        return loadPlayer("backup/player.json");
    } else {
        return NULL;
    }
    empty_buffer();
}

void ask_where_to_go(Player *ptrPlayer) {
    char choice2[2];
    char buffer[100];

    write(1, "+----------------------------+\n", 32);
    write(1, "|Where do you want to go?    |\n", 32);
    write(1, "|    1. Into the Wild        |\n", 32);
    write(1, "|    2. In the Shop          |\n", 32);
    write(1, "|    3. In the Supemon Center|\n", 32);
    write(1, "|    4. Leave the game       |\n", 32);
    write(1, "+----------------------------+\n", 32);
    write(1, "1, 2, 3, or 4 : ", 15);
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = '\0';
    strncpy(choice2, buffer, sizeof(choice2)); 
    execute_choice(choice2, ptrPlayer);
}

void execute_choice(const char *choice2, Player *ptrPlayer) {
    if (strcmp(choice2, "1") == 0) {
        fight(ptrPlayer);
    } else if (strcmp(choice2, "2") == 0) {
        shop(ptrPlayer);
    } else if (strcmp(choice2, "3") == 0) {
        pokecenter(ptrPlayer);
    } else if (strcmp(choice2, "4") == 0) {
        write(1, "GOODBYE\n", 8);
        exit(0);
    } else {
        write(1, "INCORRECT\n", 10);
        ask_where_to_go(ptrPlayer);
    }
    empty_buffer();
}