#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
using namespace std;

struct user {
    string username;
    string password;
};

user *users[100];
int userIndex = 0;

void registration() {
    // First, we allocate memory for the new user 
    struct user* temp = (struct user*) malloc(sizeof(struct user));
    user** arrayPtr = users; // Create a pointer to the list
    // Assign allocated memory to the current empty index in the list:
    *(arrayPtr + userIndex) = temp; 
    
}

void firstQuestion() {
    while (true) {
        string response;
        cout << "Type \"r\" to register, type \"l\" to login:";
        cin >> response;
        if (response == "r") {
            // registration();
        } else if (response == "l") {
            // login();
        }
    }
}

int main() {
    firstQuestion();
    int x = 5;
    cout << long(&x);
    return 0;
}
