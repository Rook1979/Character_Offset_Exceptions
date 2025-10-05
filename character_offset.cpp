// Stephan Ulbrich
// CIS 1202 101
// 10-03-2025

#include <iostream>
#include <stdexcept>
using namespace std;

// Exception for invalid character input
class invalidCharacterException : public exception {
public:
    const char* what() const noexcept override {
        return "Invalid character: must be A-Z or a-z.";
    }
};

// Exception for invalid range result
class invalidRangeException : public exception {
public:
    const char* what() const noexcept override {
        return "Invalid range: result is not a valid letter or crosses case boundary.";
    }
};

// Function to calculate character offset
char character(char start, int offset) {
    if (!isalpha(start)) {
        throw invalidCharacterException();
    }

    char result = start + offset;

    // Check for case consistency and valid letter
    if (!isalpha(result) || (islower(start) != islower(result))) {
        throw invalidRangeException();
    }

    return result;
}

// Function Test Driver
int main() {
    char testCases[][2] = {
        {'a', 1},
        {'a', -1},
        {'Z', -1},
        {'?', 5},
        {'A', 32}
    };

    for (auto& test : testCases) {
        char start = test[0];
        int offset = test[1];
        try {
            char result = character(start, offset);
            cout << "character('" << start << "', " << offset << ") = '" << result << "'" << endl;
        } catch (const invalidCharacterException& e) {
            cout << "character('" << start << "', " << offset << ") threw invalidCharacterException: " << e.what() << endl;
        } catch (const invalidRangeException& e) {
            cout << "character('" << start << "', " << offset << ") threw invalidRangeException: " << e.what() << endl;
        }
    }

    return 0;
}