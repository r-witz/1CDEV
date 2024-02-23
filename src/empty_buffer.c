#include <stdio.h>


void empty_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}