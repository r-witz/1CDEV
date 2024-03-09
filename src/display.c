#include <stdio.h> 

void welcome() {
    write(1, "=========================================\n", 42);
    write(1, "   ___\n", 7);
    write(1, "  / __] _ _  ___  ___  _ _ _  ___  _ _\n", 40);
    write(1, "  \\__ \\| | || . \\/ ._]| ' ' |/ . \\| ' |\n", 40);
    write(1, "  [___/ \\__||  _/\\___.|_|_|_|\\___/|_|_|\n", 40);
    write(1, "            |_|\n\n", 17);
    write(1, "=========================================\n\n", 43);
}

void main_menu() {
    write(1, "+------------------------------+\n", 34);
    write(1, "|  Where do you want to go ?   |\n", 34);
    write(1, "|    1. Into the Wild          |\n", 34);
    write(1, "|    2. In the Shop            |\n", 34);
    write(1, "|    3. In the Supemon Center  |\n", 34);
    write(1, "|    4. Leave the game         |\n", 34);
    write(1, "+------------------------------+\n", 34);
}

void fight_menu() {
    write(1, "+------------------------------+\n", 34);
    write(1, "|  What will you do ?          |\n", 34);
    write(1, "|    1. Move                   |\n", 34);
    write(1, "|    2. Change Supemon         |\n", 34);
    write(1, "|    3. Use item               |\n", 34);
    write(1, "|    4. Capture                |\n", 34);
    write(1, "|    5. Run away               |\n", 34);
    write(1, "+------------------------------+\n", 34);
}

void shop_menu() {
    write(1, "+------------------------------+\n", 34);
    write(1, "|  What would you want to do   |\n", 34);
    write(1, "|    1. Buy something          |\n", 34);
    write(1, "|    2. Sell something         |\n", 34);
    write(1, "|    3. Leave the shop         |\n", 34);
    write(1, "+------------------------------+\n", 34);
}

void buy_menu() {
	  write(1, "+------------------------------+\n", 34);
	  write(1, "|  What do you want to buy ?   |\n", 34);
	  write(1, "|    1. Potion       (100$)    |\n", 34);
	  write(1, "|    2. Super Potion (300$)    |\n", 34);
	  write(1, "|    3. Rare Candy   (700$)    |\n", 34);
	  write(1, "|    4. Exit Menu              |\n", 34);
	  write(1, "+------------------------------+\n", 34);
}

void sell_menu() {
	  write(1, "+------------------------------+\n", 34);
	  write(1, "|  What do you want to sell ?  |\n", 34);
	  write(1, "|    1. Potion       (50$)     |\n", 34);
	  write(1, "|    2. Super Potion (150$)    |\n", 34);
	  write(1, "|    3. Rare Candy   (350$)    |\n", 34);
	  write(1, "|    4. Exit Menu              |\n", 34);
	  write(1, "+------------------------------+\n", 34);
}

void pokecenter_menu() {
    write(1, "+------------------------------+\n", 34);
    write(1, "|  What do you want to do ?    |\n", 34);
    write(1, "|    1. Heal Supemons          |\n", 34);
    write(1, "|    2. Show Supemons team     |\n", 34);
    write(1, "|    3. Leave the pokecenter   |\n", 34);
    write(1, "+------------------------------+\n", 34);
}
