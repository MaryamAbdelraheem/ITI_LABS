#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

class String {
    char* str;
    int size;
public:
    String(const char* s = "") {
        size = strlen(s);
        str = new char[size + 1];
        strcpy(str, s);
    }

    ~String() {
        delete[] str;
    }

    void print() const {
        cout << str;
    }

    //compersion
    bool operator>(const String& s) const {
        return strlen(str) > strlen(s.str);
    }

    bool operator<(const String& s) const {
        return strlen(str) < strlen(s.str);
    }

    bool operator==(const String& s) const {
        return strlen(str) == strlen(s.str);
    }

    // merge
    String operator+(const String& s) const {
        char* temp = new char[strlen(str) + strlen(s.str) + 1];
        strcpy(temp, str);
        strcat(temp, s.str);
        String result(temp);
        delete[] temp;
        return result;
    }

    // upper lower
    void toUpper() {
        for (int i = 0; i < strlen(str); i++)
            str[i] = toupper(str[i]);
    }

    void toLower() {
        for (int i = 0; i < strlen(str); i++)
            str[i] = tolower(str[i]);
    }
};

int main() {
    String s1("Aly");
    String s2("Ahmed");

    // Concatenation
    String s3 = s1 + s2;
    cout << "Concatenation: ";
    s3.print();
    cout << endl;

    // Comparison based on length
    if (s1 > s2)
        cout << "Aly > Ahmed" << endl;
    else if (s1 < s2)
        cout << "Aly < Ahmed" << endl;
    else
        cout << "Aly = Ahmed" << endl;

    // Equality example
    String s4("Ola");
    if (s1 == s4)
        cout << "Aly and Ola are equal in length" << endl;
    else
        cout << "Aly and Ola are different in length" << endl;

    // Uppercase
    s1.toUpper();
    cout << "Uppercase: ";
    s1.print();
    cout << endl;

    // Lowercase
    s1.toLower();
    cout << "Lowercase: ";
    s1.print();
    cout << endl;

    return 0;
}
