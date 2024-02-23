#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void ask_where_to_go();
void buy();
void sell();

void shop() {
    char choice3[2];
    char buffer[100];

    do {
        write(1,"+---------------------------------------+\n", 42);
        write(1,"|What would you want to do ?            |\n", 42);
        write(1,"|    1. Buy something                   |\n", 42);
        write(1,"|    2. Sell something                  |\n", 42);
        write(1,"|    3. Leave the shop                  |\n", 42);
        write(1,"+---------------------------------------+\n", 42);
        write(1,"1, 2 or 3 : ", 12);

        fgets(buffer, sizeof(buffer), stdin);
        buffer[strcspn(buffer, "\n")] = '\0';
        strncpy(choice3, buffer, sizeof(choice3));

        if (strcmp(choice3, "1") == 0) {
            buy();
        } else if (strcmp(choice3, "2") == 0) {
            sell();
        } else if (strcmp(choice3, "3") == 0) {
            write(1, "GOODBYE\n", 8);
            ask_where_to_go();
        } else {
            write(1, "INCORRECT\n", 10);
        }
    }   while (strcmp(choice3, "1") != 0 && strcmp(choice3, "2") != 0 && strcmp(choice3, "3") != 0);
}

