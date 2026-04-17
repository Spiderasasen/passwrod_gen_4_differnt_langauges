//
// Created by spide on 4/17/2026.
//

#include "password_gen.h"
#include <stdio.h>

//private vars
int password_length = 0;
char password_type;
char* password;

//getting the options the user selected
void setting_length(int length) { //setting the length of the password
    password_length = length;
}

void password_options(char option) { //setting the option that the user got
    password_type = option;
}

//main password system
void making_password() {
    switch (password_type) {
        case 'a':
            printf("words only");
            break;
        case 'b':
            printf("numbers only");
            break;
        case 'c':
            printf("spcial charcaters only");
            break;
        case 'd':
            printf("all options");
            break;
    }
}