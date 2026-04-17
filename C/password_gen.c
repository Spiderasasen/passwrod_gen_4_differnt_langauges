//
// Created by spide on 4/17/2026.
//

#include "password_gen.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

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

//opening files
char** file_opener(const char* path, int* out_count) {
    FILE* f = fopen(path, "r");
    //if the file can not be opened
    if(!f) {
        printf("error opening the file: %s. Please check the spelling of the file name or if the configuration is correct.", path);
        *out_count = 0;
        return NULL;
    }

    char** lines = NULL;
    int count = 0;
    char buffer[256];

    //opens the file and place it on a section
    while (fgets(buffer,sizeof(buffer),f)) {
        buffer[strlen(buffer)-1] = '\0';

        lines = realloc(lines, sizeof(char*) * (count + 1));
        lines[count] = malloc(strlen(buffer) + 1);
        strcpy(lines[count], buffer);

        count++;
    }

    //closing the file
    fclose(f);
    *out_count = count;
    return lines;
}

//getting a random item


//main password system
void making_password() {
    //seed
    srand(time(NULL));

    //private vars
    int count = 0;
    char** list = NULL;

    //checking what the user got
    switch (password_type) {
        case 'a':
            printf("words only");
            list = file_opener("data/alphabet.txt", &count);
            for (int i = 0; i < count; i++) {
                printf("%s\n", list[i]);
            }
            break;
        case 'b':
            printf("numbers only");
            list = file_opener("data/numbers.txt", &count);
            for (int i = 0; i < count; i++) {
                printf("%s\n", list[i]);
            }
            break;
        case 'c':
            printf("spcial charcaters only");
            break;
        case 'd':
            printf("all options");
            break;
    }
}