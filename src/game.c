#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

void ask_where_to_go();
void fight();
void shop();

void ask_name(char *name) {

    char buffer[100];

    write(1, "Hello ! What's your name? ", 26);
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = '\0';
    strncpy(name, buffer, sizeof(buffer));
    printf("Hello, %s !\n ", name);
    write(1, "Welcome in Supemon World!\n", 26);
}

void execute_choice(int choice2) {
    if (choice2 == 1) {
        write(1, "BAGARRE\n", 8);
        fight();
    } else if (choice2 == 2) {
        write(1, "BOUTIQUE\n", 9);
        shop();
    } else if (choice2 == 3) {
        write(1, "POKECENTER\n", 11);
    } else if (choice2 == 4) {
        write(1, "GOODBYE\n", 8);
        exit(0);
    } else {
        write(1, "INCORRECT\n", 10);
        ask_where_to_go();
    }
}