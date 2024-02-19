#include <stdio.h>
#include <unistd.h>


void ask_where_to_go();


void shop() {
    int choice3;
    write(1, "+---------------------------------------+\n" , 43);
    write(1, "|What would you want to buy ?           |\n", 43);
    write(1, "|    1. Potion (+5 HP) -> 100 SC        |\n", 43);
    write(1, "|    2. Super potion (+10 HP) -> 300 SC |\n", 43);
    write(1, "|    3. Rare candy (+1 LVL) -> 700 SC   |\n", 43);
    write(1, "|    4. Leave the shop                  |\n", 43);    
    write(1, "+---------------------------------------+\n" , 43);
    write(1, "1, 2 or 3 : ", 12);
    scanf("%d", &choice3);
    if (choice3 == 1) {
        write(1, "You bought a Potion\n", 21);
    } else if (choice3 == 2) {
        write(1, "You bought a Super potion\n", 27);
    } else if (choice3 == 3) {
        write(1, "You bought a Rare candy\n", 25);
    } else if (choice3 == 4) {
        write(1, "You left the shop\n", 18);
        ask_where_to_go();
    } else {
        write(1, "Invalid choice\n", 16);
    }
}