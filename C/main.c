#include <stdio.h>

int main() {
    //asking the user, how long the password should be
    int length_word = 0;
    printf("How long would you like the word to be?\n");
    if ((scanf("%d", &length_word) != 1) || (length_word <= 0)) {
        printf("Invalid input\n");
    }
}