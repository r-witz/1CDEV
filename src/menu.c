#include <stdio.h>
#include <unistd.h>

void execute_choice(int choice2);

void ask_where_to_go() {
    int choice2;
    write(1, "+----------------------------+\n" , 32);
    write(1, "|Where do you want to go?    |\n", 32);
    write(1, "|    1. Into the Wild        |\n", 32);
    write(1, "|    2. In the Shop          |\n", 32);
    write(1, "|    3. In the Supemon Center|\n", 32);
    write(1, "|    4. Leave the game       |\n", 32);
    write(1, "+----------------------------+\n" , 32);
    write(1, "1, 2, 3, or 4 : ", 15);
    scanf("%d", &choice2);
    printf("You chose %d\n", choice2);
    execute_choice(choice2);
}
