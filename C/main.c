#include <stdio.h>

int main() {
    //private vars
    int length_word = 0;
    char password_option;

    //asking the user, how long the password should be
    printf("How long would you like the word to be?\n");
    if ((scanf("%d", &length_word) != 1) || (length_word <= 0)) {
        printf("Invalid input\n");
    }

    //asking the user what type of password they want
    printf("What option would you like?\n"
           "a. Password of letters only\n"
           "b. Password or numbers only\n"
           "c. Password of spical characters\n"
           "d. Password with all\n");
    scanf(" %c", &password_option);
    if (!(password_option == 'a' || password_option == 'b' || password_option == 'c' || password_option == 'd')) {
        printf("Invalid input\n");
    }
}