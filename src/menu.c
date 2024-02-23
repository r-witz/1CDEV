#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>


void execute_choice(const char *choice2);
void empty_buffer();
void fight();
void shop();
void pokecenter();

void ask_where_to_go() {
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
    execute_choice(choice2);
}

void execute_choice(const char *choice2) {
    if (strcmp(choice2, "1") == 0) {
        fight();
    } else if (strcmp(choice2, "2") == 0) {
        shop();
    } else if (strcmp(choice2, "3") == 0) {
        pokecenter();
    } else if (strcmp(choice2, "4") == 0) {
        write(1, "GOODBYE\n", 8);
        exit(0);
    } else {
        write(1, "INCORRECT\n", 10);
        ask_where_to_go();
    }
    empty_buffer();
}