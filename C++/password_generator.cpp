//
// Created by spiderasasen on 4/19/26.
//

#include "password_generator.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <random>

using namespace std;

int password_length = 0;
char password_option;
string password;

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
            if (!isspace(c)) {
                items.push_back(c);
            }
        }
        fio.close();
    }
    return items;
}

//appends a char to a letter
string genorator::new_password(string password_type, int length, const vector<char>& items) {
    static random_device rd;
    static mt19937 gen(rd());
    uniform_int_distribution<> dist(0, items.size() - 1);

    for (int i = 0; i < length; i++) {

        password_type.push_back(items[dist(gen)]);
    }
    return password_type;
}

//main section for new password
void genorator::gen_password() {
    switch (password_option) {
        case 'a': {
            cout << "letters only" << endl;
            //opens the file
            vector<char> items = open_files("data/alphabet.txt");

            //appends to the password vector
            password = new_password(password, password_length, items);

            cout << "Your Password: " << password << endl;

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