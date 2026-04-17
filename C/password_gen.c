//
// Created by spide on 4/17/2026.
//

#include "password_gen.h"

//private vars
int password_length = 0;
char password_type;

//getting the options the user selected
void setting_length(int length) { //setting the length of the password
    password_length = length;
}

void password_options(char option) {
    password_type = option;
}