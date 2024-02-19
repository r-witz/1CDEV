#include <stdio.h>
#include <unistd.h>

#include "../include/player.h"



int ask_supemon() {
    int choice;
    write(1, "+---------------------+\n" , 24);
    write(1, "|Choose your Supemon: |\n", 24);
    write(1, "|    1. Supmander     |\n", 24);
    write(1, "|    2. Supasaur      |\n", 24);
    write(1, "|    3. Supirtle      |\n", 24);
    write(1, "+---------------------+\n" , 24);
    write(1, "1, 2 or 3 : ", 12);
    scanf("%d", &choice);
    if (choice == 1) {
        write(1, "You chose Supmander\n", 20);
    } else if (choice == 2) {
        write(1, "You chose Supasaur\n", 20);
    } else if (choice == 3) {
        write(1, "You chose Supirtle\n", 20);
    } else {
        write(1, "Invalid choice\n", 16);
    }
    return choice;
}   
