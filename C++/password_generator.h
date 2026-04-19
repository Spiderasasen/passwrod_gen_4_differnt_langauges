//
// Created by spiderasasen on 4/19/26.
//

#ifndef PASSWROD_GEN_4_DIFFERNT_LANGAUGES_PASSWORD_GENERATOR_H
#define PASSWROD_GEN_4_DIFFERNT_LANGAUGES_PASSWORD_GENERATOR_H
#include <string>
#include <vector>
#include <istream>

using namespace std;

class genorator {
    private:
    int password_length = 0;
    char password_option;
    vector<char> open_files(string file);
    public:
    void setting_length(int length);
    void setting_option(char option);
    void gen_password();
};

#endif //PASSWROD_GEN_4_DIFFERNT_LANGAUGES_PASSWORD_GENERATOR_H