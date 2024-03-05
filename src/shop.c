#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "../include/player.h"

void ask_where_to_go();
void buy(Player *ptrPlayer);
void sell();
int ask_quantity_buy(Player *ptrPlayer, int itemID);
int ask_quantity_sell(Player *ptrPlayer, int itemID);
void empty_buffer();

void shop(Player *ptrPlayer) {
    char choice[2];

    do {
        write(1,"+------------------------------+\n", 34);
        write(1,"| What would you want to do ?  |\n", 34);
        write(1,"|    1. Buy something          |\n", 34);
        write(1,"|    2. Sell something         |\n", 34);
        write(1,"|    3. Leave the shop         |\n", 34);
        write(1,"+------------------------------+\n", 34);

        write(1,"1, 2 or 3 : ", 12);
        fgets(choice, sizeof(choice), stdin);
        choice[strcspn(choice, "\n")] = '\0';

	empty_buffer();

        if (strcmp(choice, "1") == 0) {
            buy(ptrPlayer);
	    break;
        } else if (strcmp(choice, "2") == 0) {
            sell(ptrPlayer);
	    break;
        } else if (strcmp(choice, "3") == 0) {
            ask_where_to_go();
	    break;
        } else {
	    write(1, "INCORRECT\n", 10);
        }
    }   while (strcmp(choice, "1") != 0 && strcmp(choice, "2") != 0 && strcmp(choice, "3") != 0);
}

void buy(Player *ptrPlayer) {
    char choice[2];

    do {
	write(1,"+------------------------------+\n", 34);
	write(1,"|  What do you want to buy ?   |\n", 34);
	write(1,"|    1. Potion       (100$)    |\n", 34);
	write(1,"|    2. Super Potion (300$)    |\n", 34);
	write(1,"|    3. Rare Candy   (700$)    |\n", 34);
	write(1,"|    4. Exit Menu              |\n", 34);
	write(1,"+------------------------------+\n", 34);
	
	write(1, "1, 2, 3 or 4 : ", 16);
	fgets(choice, sizeof(choice), stdin); 
	choice[strcspn(choice, "\n")] = '\0';

	empty_buffer();

	if (strcmp(choice, "1") == 0) {
	    int quantity = ask_quantity_buy(ptrPlayer, 1);
	    ptrPlayer->potions += quantity;
	    ptrPlayer->money -= quantity*100;
	} else if (strcmp(choice, "2") == 0) {
            int quantity = ask_quantity_buy(ptrPlayer, 2);
	    ptrPlayer->super_potions += quantity;
	    ptrPlayer->money -= quantity*300;
	} else if (strcmp(choice, "3") == 0) {
            int quantity = ask_quantity_buy(ptrPlayer, 3);
	    ptrPlayer->rare_candy += quantity;
	    ptrPlayer->money -= quantity*700;
	} else if (strcmp(choice, "4") == 0) {
	
	    shop(ptrPlayer);
	} else {
	    write(1, "Incorrect choice, please try again\n", 35);
	}


    } while (strcmp(choice, "4") != 0);
}

void sell(Player *ptrPlayer) {
    char choice[2];

    do {
	write(1,"+------------------------------+\n", 34);
	write(1,"|  What do you want to sell ?  |\n", 34);
	write(1,"|    1. Potion       (50$)     |\n", 34);
	write(1,"|    2. Super Potion (150$)    |\n", 34);
	write(1,"|    3. Rare Candy   (350$)    |\n", 34);
	write(1,"|    4. Exit Menu              |\n", 34);
	write(1,"+------------------------------+\n", 34);
	
	write(1, "1, 2, 3 or 4 : ", 16);
	fgets(choice, sizeof(choice), stdin); 
	choice[strcspn(choice, "\n")] = '\0';

	empty_buffer();

	if (strcmp(choice, "1") == 0) {
	    int quantity = ask_quantity_sell(ptrPlayer, 1);
	    ptrPlayer->potions -= quantity;
	    ptrPlayer->money += quantity*50;
	} else if (strcmp(choice, "2") == 0) {
            int quantity = ask_quantity_sell(ptrPlayer, 2);
	    ptrPlayer->super_potions -= quantity;
	    ptrPlayer->money += quantity*150;
	} else if (strcmp(choice, "3") == 0) {
            int quantity = ask_quantity_sell(ptrPlayer, 3);
	    ptrPlayer->rare_candy -= quantity;
	    ptrPlayer->money += quantity*350;
	} else if (strcmp(choice, "4") == 0) {
	    shop(ptrPlayer);
	} else {
	    write(1, "Incorrect choice, please try again\n", 35);
	}

    } while (strcmp(choice, "4") != 0);

}

int ask_quantity_buy(Player *ptrPlayer, int itemID) {
    int quantity;
    int prices[] = {100, 300, 700};

    write(1, "How much items do you want to buy : ", 36);
    scanf("%d", &quantity);
    empty_buffer();
    
    if (quantity < 0) {
	write(1, "You can't buy negative quantity\n",32);
	quantity = 0;
    } else if (prices[itemID-1]*quantity > ptrPlayer->money) {
	write(1, "You don't have enough Supcoins\n", 31);
    	quantity = 0;
    }
    
    return quantity;
} 

int ask_quantity_sell(Player *ptrPlayer, int itemID) {
    int quantity;
    int playerQuantities[] = {ptrPlayer->potions, ptrPlayer->super_potions, ptrPlayer->rare_candy};

    write(1, "How much items do you want to sell : ", 37);
    scanf("%d", &quantity);
    empty_buffer();
    
    if (quantity < 0) {
	write(1, "You can't sell negative quantity\n",33);
	quantity = 0;
    } else if (playerQuantities[itemID-1] < quantity) {
	write(1, "You don't have enough of the item\n", 34);
    	quantity = 0;
    }
    
    return quantity;
} 
