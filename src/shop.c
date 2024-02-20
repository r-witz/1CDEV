#include <stdio.h>
#include <stdlib.h>


void ask_where_to_go();


void shop() {
    int choice3;
    char quantity[999];
    printf("+---------------------------------------+\n");
    printf("|What would you want to buy ?           |\n");
    printf("|    1. Potion (+5 HP) -> 100 SC        |\n");
    printf("|    2. Super potion (+10 HP) -> 300 SC |\n");
    printf("|    3. Rare candy (+1 LVL) -> 700 SC   |\n");
    printf("|    4. Leave the shop                  |\n");    
    printf("+---------------------------------------+\n");
    printf("1, 2 or 3 : ");
    scanf("%d", &choice3);
    if (choice3 == 1) {
        printf("How many do you want to buy ? ");
        scanf("%s", quantity);
        printf("You bought %s Potions\n", quantity);
    } else if (choice3 == 2) {
        printf("How many do you want to buy ? ");
        scanf("%s", quantity);
        printf("You bought %s Super Potions\n", quantity);
    } else if (choice3 == 3) {
        printf("How many do you want to buy ? ");
        scanf("%s", quantity);
        printf("You bought %s Rare Candy\n", quantity);
    } else if (choice3 == 4) {
        printf("You left the shop\n");
        ask_where_to_go();
    } else {
        printf("Invalid choice\n");
    }
}