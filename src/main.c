#include "../include/menu.h"
#include "../include/starter.h"
#include "../include/game.h"

int main()
{
    char name[100];
    ask_name(name);
    int choice = ask_supemon();
    ask_where_to_go();
    return 0;
}