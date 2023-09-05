#include <iostream>
#include <vector>
using namespace std;

class user;

vector<user> users;

class user {
    public:
        string username;
        string password;

        user() {
            username = "";
            password = "";
        }

        user(string u, string p) {
            username = u;
            password = p;
        }
};

void registration() {
    string username;
    string password;
    cout << "Create a username for your account: ";
    cin >> username;
    cout << "Create a password for your account: ";
    cin >> password;
    user *newUser = new user(username, password);
}

void login() {
    // First we print out a couple 
    for (int i = 0; i < 5; i++) { 
        cout << "\n";
    }
    string name;
    string pass;
    cout << "Username: ";
    cin >> name;
    cout << "Password: ";
    cin >> pass;
    cout << name;
    cout << pass;
    unsigned int size = users.size();
    user x;
    for (int i = 0; i < size; i++) {
        x = users[i];
       if (x.username == name && x.password == pass) {
            cout << "Login succesful.";
        }
    }
    cout << "Error: Invalid username or password.\n";
}

void firstQuestion() {
    while (true) {
        string response;
        cout << "Type \"r\" to register, type \"l\" to login:";
        cin >> response;
        if (response == "r") {
            registration();
        } else if (response == "l") {
            login();
        }
    }
}

int main() {
    firstQuestion();
    return 0;
}
