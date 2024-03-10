#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "../include/display.h"
#include "../include/input.h"
#include "../include/player.h"

void buy(Player *ptrPlayer);
void sell(Player *ptrPlayer);
int ask_quantity_buy(Player *ptrPlayer, int itemID);
int ask_quantity_sell(Player *ptrPlayer, int itemID);

void shop(Player *ptrPlayer) {
    int choice;

    shop_menu();

    do {
        get_input("1, 2 or 3: ", &choice, 'i', 3);

        switch (choice) {
            case 1:
                buy(ptrPlayer);
                break;
            case 2:
                sell(ptrPlayer);
                break;
            case 3:
                main_menu();
                break;
            default:
                write(1, "Please enter a number between 1-3\n", 34);
        }
    } while (choice != 3);
}

void buy(Player *ptrPlayer) {
    int choice;
    
    buy_menu();
    char bufferStr[7];
    write(1, "You have ", 9);
    sprintf(bufferStr, "%d", ptrPlayer->money);
    write(1, bufferStr, strlen(bufferStr));
    write(1, " Supcoins\n", 10);

    do {
        int quantity;
        get_input("1, 2, 3 or 4: ", &choice, 'i', 3);

        switch (choice) {
            case 1:
                quantity = ask_quantity_buy(ptrPlayer, 1);
                ptrPlayer->potions += quantity;
                ptrPlayer->money -= quantity * 100;
                write(1, "You bought ", 11);
                sprintf(bufferStr, "%d", quantity);
                write(1, bufferStr, strlen(bufferStr));
                write(1, " Potions\n", 9);
                break;
            case 2:
                quantity = ask_quantity_buy(ptrPlayer, 2);
                ptrPlayer->super_potions += quantity;
                ptrPlayer->money -= quantity * 300;
                write(1, "You bought ", 11);
                sprintf(bufferStr, "%d", quantity);
                write(1, bufferStr, strlen(bufferStr));
                write(1, " Super Potions\n", 15);
                break;
            case 3:
                quantity = ask_quantity_buy(ptrPlayer, 3);
                ptrPlayer->rare_candy += quantity;
                ptrPlayer->money -= quantity * 700;
                write(1, "You bought ", 11);
                sprintf(bufferStr, "%d", quantity);
                write(1, bufferStr, strlen(bufferStr));
                write(1, " Rare Candies\n", 14);                
                break;
            case 4:
                shop_menu();
                break;
            default:
                write(1, "Please enter a number between 1-4\n", 34);
        }
    } while (choice != 4);
}

void sell(Player *ptrPlayer) {
    int choice;

    sell_menu();
    char bufferStr[7];
    write(1, "You have ", 9);
    sprintf(bufferStr, "%d", ptrPlayer->potions);
    write(1, bufferStr, strlen(bufferStr));
    write(1, " Potions, ", 10);
    write(1, "You have ", 9);
    sprintf(bufferStr, "%d", ptrPlayer->super_potions);
    write(1, bufferStr, strlen(bufferStr));
    write(1, " Super Potions, ", 16);
    write(1, "You have ", 9);
    sprintf(bufferStr, "%d", ptrPlayer->rare_candy);  
    write(1, bufferStr, strlen(bufferStr));
    write(1, " Rare Candies\n", 14);      

    do {
        int quantity;
        get_input("1, 2, 3 or 4: ", &choice, 'i', 3);

        switch (choice) {
            case 1:
                quantity = ask_quantity_sell(ptrPlayer, 1);
                ptrPlayer->potions -= quantity;
                ptrPlayer->money += quantity * 50;
                write(1, "You sold ", 9);
                sprintf(bufferStr, "%d", quantity);
                write(1, bufferStr, strlen(bufferStr));
                write(1, " Potions\n", 9);
                write(1, "For a total of ", 15);
                sprintf(bufferStr, "%d", quantity * 50);
                write(1, bufferStr, strlen(bufferStr));
                write(1, " Supcoins\n", 11);
                break;
            case 2:
                quantity = ask_quantity_sell(ptrPlayer, 2);
                ptrPlayer->super_potions -= quantity;
                ptrPlayer->money += quantity * 150;
                write(1, "You sold ", 9);
                sprintf(bufferStr, "%d", quantity);
                write(1, bufferStr, strlen(bufferStr));
                write(1, " Super Potions\n", 15);
                write(1, "For a total of ", 15);
                sprintf(bufferStr, "%d", quantity * 150);
                write(1, bufferStr, strlen(bufferStr));
                write(1, " Supcoins\n", 11);
                break;
            case 3:
                quantity = ask_quantity_sell(ptrPlayer, 3);
                ptrPlayer->rare_candy -= quantity;
                ptrPlayer->money += quantity * 350;
                write(1, "You sold ", 9);
                sprintf(bufferStr, "%d", quantity);
                write(1, bufferStr, strlen(bufferStr));
                write(1, " Rare Candies\n", 14);
                write(1, "For a total of ", 15);
                sprintf(bufferStr, "%d", quantity * 350);
                write(1, bufferStr, strlen(bufferStr));
                write(1, " Supcoins\n", 11);
                break;
            case 4:
                shop_menu();
                break;
            default:
                write(1, "Please enter a number between 1-4\n", 34);
        }
    } while (choice != 4);
}

int ask_quantity_buy(Player *ptrPlayer, int itemID) {
    short prices[] = {100, 300, 700};
    short quantity;
    get_input("How much items do you want to buy: ", &quantity, 'i', 7);

    if (quantity <= 0) {
        write(1, "Invalid choice. Please enter a positive number.\n", 49);
        return 0;
    } else if (prices[itemID-1] * quantity > ptrPlayer->money) {
        write(1, "You don't have enough Supcoins.\n", 32);
        return 0;
    }

    return quantity;
}

int ask_quantity_sell(Player *ptrPlayer, int itemID) {
    short quantity;
    short playerQuantities[] = {ptrPlayer->potions, ptrPlayer->super_potions, ptrPlayer->rare_candy};
    
    get_input("How much items do you want to sell: ", &quantity, 'i', 7);

    if (quantity <= 0) {
        write(1, "Invalid choice. Please enter a positive number.\n", 49);
	    return 0;
    } else if (playerQuantities[itemID-1] < quantity) {
	    write(1, "You don't have enough of the item\n", 34);
    	return 0;
    }
    
    return quantity;
} 
