#include <stdio.h>

void clear_input();

int main() {
    //private vars
    int length_word = 0;
    char password_option;

    while (1) {
        printf("How long would you like the word to be?\n");

        if (scanf("%d", &length_word) != 1 || length_word <= 0) {
            printf("Invalid input, setting the length to 8\n");
            length_word = 8;
            clear_input(); // flush leftover garbage
            break;
        }

        clear_input(); // remove leftover newline
        break;
    }

    //asking the user what type of password they want
    while (1) {
        printf("What option would you like?\n"
               "a. Password of letters only\n"
               "b. Password or numbers only\n"
               "c. Password of spical characters\n"
               "d. Password with all\n");
        scanf(" %c", &password_option);
        if (!(password_option == 'a' || password_option == 'b' || password_option == 'c' || password_option == 'd')) {
            printf("Invalid input\n");
            continue;
        }
        break;
    }
}

void clear_input() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}