//
// Created by spiderasasen on 4/19/26.
//

#include "password_generator.h"
#include <iostream>

using namespace std;

int password_length = 0;
char password_option;

//setters
void genorator::setting_length(int length) {
    password_length = length;
}
void genorator::setting_option(char option) {
    password_option = option;
}

//main section for new password
void genorator::gen_password() {
    switch (password_option) {
        case 'a':
            cout << "letters only" << endl;
            break;
        case 'b':
            cout << "numbers only" << endl;
            break;
        case 'c':
            cout << "special chars only" << endl;
            break;
        case 'd':
            cout << "all sections" << endl;
            break;
    }
}