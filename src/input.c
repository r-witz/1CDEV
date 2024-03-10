#include <stdio.h>
#include <string.h>
#include <unistd.h>

void get_input(char *prompt, void *output, char type, const int BUFFER_SIZE) {
    char buffer[BUFFER_SIZE];
    write(STDOUT_FILENO, prompt, strlen(prompt));
    fgets(buffer, BUFFER_SIZE, stdin);

    // Check for buffer overflow
    if (buffer[strlen(buffer) - 1] != '\n') {
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
    }

    // Remove newline character if present
    if (strlen(buffer) > 0 && buffer[strlen(buffer) - 1] == '\n') {
        buffer[strlen(buffer) - 1] = '\0';
    }

    if (type == 'i') {
        int number;
        int success = sscanf(buffer, "%d", &number);
        *((int*)output) = success == 1 && buffer[1] == '\0' ? number : -1;
    } else if (type == 's') {
        strncpy((char*)output, buffer, BUFFER_SIZE);
    }
}
