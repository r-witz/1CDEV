#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#include "../include/player.h"
void ask_where_to_go();
void empty_buffer();
void shop();
// i//nt Sellquantity();

void sell() {
    char choice5[2];
    char buffer[100];
    write(1,"+---------------------------------------+\n", 42);
    write(1,"|What would you want to sell ?          |\n", 42);
    write(1,"|    1. Potion (+5 HP) -> 50 SC         |\n", 42);
    write(1,"|    2. Super potion (+10 HP) -> 150 SC |\n", 42);
    write(1,"|    3. Rare candy (+1 LVL) -> 350 SC   |\n", 42);
    write(1,"|    4. Leave the shop                  |\n", 42);
    write(1,"+---------------------------------------+\n", 42);
    write(1,"1, 2 or 3 : ", 12);
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = '\0';
    strncpy(choice5, buffer, sizeof(choice5));

    if (strcmp(choice5, "1") == 0) {
        // int quantity = Sellquantity();
        //(&player)->potions = (&player)->potions - quantity;
        //(&player)->money = (&player)->money + 50 * quantity;
        // printf("You have %d potions left\n", (&player)->potions);
        // printf("You have %d SC\n", (&player)->money);
        ask_where_to_go();

    } else if (strcmp(choice5, "2") == 0) {
        //Sellquantity();
    } else if (strcmp(choice5, "3") == 0) {
        //Sellquantity();
    } else if (strcmp(choice5, "4") == 0) {
        write(1, "GOODBYE\n", 8);
        ask_where_to_go();
    } else {
        write(1, "INCORRECT\n", 10);
        shop();
    }
    empty_buffer();
}

// int Sellquantity() {
//     char ItemQuantity[100];
// 
//     write(1, "How many would you like to sell ?\n", 34);
//     write(1, "Quantity : ", 11);
//     fgets(ItemQuantity, sizeof(ItemQuantity), stdin);
//     ItemQuantity[strcspn(ItemQuantity, "\n")] = '\0';
//     strncpy(ItemQuantity, ItemQuantity, sizeof(ItemQuantity));
// 
//     int number = atoi(ItemQuantity);
//     if (number >= 1 && number <= 1000000) {
//         printf("You bought %d items\n", number);
//     } else {
//         write(1, "INCORRECT\n", 10);
//         shop();
//     }
//     return number;
// }