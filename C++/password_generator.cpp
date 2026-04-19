//
// Created by spiderasasen on 4/19/26.
//

#include "password_generator.h"

int password_length = 0;
char password_option;

//setters
void setting_length(int length) {
    password_length = length;
}

void setting_option(char option) {
    password_option = option;
}