#include <stdio.h>
#include <unistd.h>
#include <string.h>

#include "../include/player.h"

void ask_name(char *name) {
    Player player;
    char buffer[100];

    write(1, "Hello ! What's your name? ", 26);
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = '\0';
    strncpy(name, buffer, sizeof(buffer));
    (&player)->name = name;
    write(1, "Welcome in Supemon World ! ", 28);
    write(1, name, strlen(name));
    write(1, "\n", 1); 
}
    
