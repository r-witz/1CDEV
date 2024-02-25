#include <stdio.h>
#include <unistd.h>
#include <string.h>

#include "../include/player.h"

void empty_buffer();


Supemon *getSupemonByID(int id);

int ask_supemon() {
    Player player;
    char choice[2];
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

        if (strcmp(choice, "1") == 0) {
            (&player)->supemons[0] = getSupemonByID(1);
            printf("You chose %s\n", (&player)->supemons[0]->name);
        } else if (strcmp(choice, "2") == 0) {
            (&player)->supemons[1] = getSupemonByID(2);
        } else if (strcmp(choice, "3") == 0) {
            (&player)->supemons[2] = getSupemonByID(3);
        } else {
            write(1, "INCORRECT\n", 10);
        }
       } while (strcmp(choice, "1") != 0 && strcmp(choice, "2") != 0 && strcmp(choice, "3") != 0);
    return 0;
}