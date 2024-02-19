#include <stdio.h>
#include <unistd.h>

void ask_where_to_go();

void pokecenter() {
    int choice;
    write(1, "+----------------------------+\n" , 32);
    write(1, "|What do you want to do?     |\n", 32);
    write(1, "|    1. Heal Supemons        |\n", 32);
    write(1, "|    2. Leave the pokecenter |\n", 32);
    write(1, "+----------------------------+\n" , 32);
    write(1, "1 or 2 : ", 10);
    scanf("%d", &choice);
    printf("You chose %d\n", choice);
    if (choice == 1) {
        printf("You healed your supemons\n");
    }
    else if (choice == 2) {
        ask_where_to_go();
    }
    else {
        printf("Invalid choice\n");
    }
}