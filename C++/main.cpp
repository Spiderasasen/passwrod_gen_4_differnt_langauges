#include <iostream>
#include <limits>
#include <vector>
#include <string>

using namespace std;

int main() {

    //private vars
    int password_length = 0;
    char password_option;
    vector<string> options = {"a. Password of letters only", "b. Password or numbers only", "c. Password of spical characters", "d. Password with all"};

    //loop to check if the input is really a number
    cout<< "enter a password length:" << endl;
    while (!(cin >> password_length)) {
        cout<< "enter a password length:" << endl;
        cin.clear();
        cin.ignore(numeric_limits< streamsize>::max(), '\n');
    }

    //getting the option of which password type the user wants
    while (true) {
        //making the user select an option
        cout << "Please choose an option:" << endl;
        for (int i = 0; i < options.size(); i++) {
            cout << options[i] << endl;
        }
        cin >> password_option;
        password_option = tolower(password_option);
        if (!(password_option == 'a' || password_option == 'b' || password_option == 'c' || password_option == 'd')) {
            cin.clear();
            continue;
        }
        break;
    }
    cout << "you selected: " << password_option << endl;

    return 0;
}