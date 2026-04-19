#include <iostream>
#include <limits>

using namespace std;

int main() {

    //private vars
    int password_length = 0;
    char password_option;

    //loop to check if the input is really a number
    cout<< "enter a password length:" << endl;
    while (!(cin >> password_length)) {
        cout<< "enter a password length:" << endl;
        cin.clear();
        cin.ignore(numeric_limits< streamsize>::max(), '\n');
    }

    cout << "number entered: " << password_length << endl;

    return 0;
}