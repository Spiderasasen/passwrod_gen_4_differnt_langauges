//
// Created by spiderasasen on 4/19/26.
//

#include "password_generator.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

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

vector<char> genorator::open_files(string file) {
    ifstream fio(file);

    vector<char> items;

    if (fio.fail()) {
        cout << "error opening file" << endl;
        return items;
    }
    else {
        char c;
        while (fio.get(c)) {
            items.push_back(c);
        }
        fio.close();
    }
    return items;
}

//main section for new password
void genorator::gen_password() {
    switch (password_option) {
        case 'a': {
            cout << "letters only" << endl;
            vector<char> items = open_files("data/alphabet.txt");
            for (int i = 0; i < items.size(); i++) {
                cout << items[i];
            }
            cout << endl;
            break;
        }
        case 'b': {
            cout << "numbers only" << endl;
            break;
        }
        case 'c': {
            cout << "special chars only" << endl;
            break;
        }
        case 'd': {
            cout << "all sections" << endl;
            break;
        }
    }
}