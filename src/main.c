#include "../include/display.h"
#include "../include/player.h"
#include "../include/menu.h"

int main()
{   
    welcome();
    Player *ptrPlayer = ask_new_game();
    ask_where_to_go(ptrPlayer);
    return 0;
}
