// Phillip May
// CIS 1202 800
// May 5, 2024


#include <iostream>
using namespace std;

// Custom exception classes
class invalidCharacterException : public exception {
public:
    const char* what() const noexcept override {
        return "Invalid character exception: Start character is not a letter.";
    }
};

class invalidRangeException : public exception {
public:
    const char* what() const noexcept override {
        return "Invalid range exception: Resulting character is not a letter.";
    }
};

// Function prototype
char character(char start, int offset);

int main() {
 
    try {
        cout << "character('a', 1) = " << character('a', 1) << endl;
    }
    catch (exception& e) {
        cout << e.what() << endl;
    }

    try {
        cout << "character('a', -1) = ";
        cout << character('a', -1) << endl;
    }
    catch (exception& e) {
        cout << e.what() << endl;
    }

    try {
        cout << "character('Z', -1) = " << character('Z', -1) << endl;
    }
    catch (exception& e) {
        cout << e.what() << endl;
    }

    try {
        cout << "character('?', 5) = ";
        cout << character('?', 5) << endl;
    }
    catch (exception& e) {
        cout << e.what() << endl;
    }

    try {
        cout << "character('A', 32) = ";
        cout << character('A', 32) << endl;
    }
    catch (exception& e) {
        cout << e.what() << endl;
    }

    return 0;
}

// Check if the start character is a letter
char character(char start, int offset) {
    if (!isalpha(start)) {
        throw invalidCharacterException();
    }

    // Calculate the resulting character
    char result = start + offset;

    // Check if the resulting character is within the same case range
    if ((islower(start) && !islower(result)) || (isupper(start) && !isupper(result))) {
        throw invalidRangeException();
    }

    return result;
}
