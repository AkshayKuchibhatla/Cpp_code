#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string string_to_upper(string p_string) {
    string output;
    char x;
    for (int i = 0; i < p_string.length(); i++) {
        x = p_string[i];
        output += toupper(p_string[i]);
    }
    return output;
}

string string_to_lower(string p_string) {
    string output;
    char x;
    for (int i = 0; i < p_string.length(); i++) {
        x = p_string[i];
        output += tolower(p_string[i]);
    }
    return output;
}

int main() {
    string text;
    string conversionType;
    cout << "Enter a string... ";
    cin >> text;
    cout << endl;

    while (conversionType != "u" && conversionType != "l") {
        cout << "Change string to upper (u) or to lower (l)?";
        cin >> conversionType;
        cout << endl;
    }

    if (conversionType == "u") {
        cout << string_to_upper(text);
    } else {
        cout << string_to_lower(text);
    }
    return 0;
}