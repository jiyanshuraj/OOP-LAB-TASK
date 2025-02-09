#include <iostream>
#include <cstring> 
using namespace std;

char* allocateString(const char* input) {
    char* str = new char[strlen(input) + 1]; 
    strcpy(str, input);
    return str;
}

char* concatenateStrings(const char* str1, const char* str2) {
    char* result = new char[strlen(str1) + strlen(str2) + 1];
    strcpy(result, str1);
    strcat(result, str2);
    return result;
}

bool compareStrings(const char* str1, const char* str2) {
    return strcmp(str1, str2) == 0;
}

void deallocateString(char* str) {
    delete[] str;
}

int main() {
    char input1[100], input2[100];

    cout << "Enter the first string: ";
    cin.getline(input1, 100);
    cout << "Enter the second string: ";
    cin.getline(input2, 100);

    char* str1 = allocateString(input1);
    char* str2 = allocateString(input2);

    char* concatenated = concatenateStrings(str1, str2);
    cout << "Concatenated string: " << concatenated << endl;

    if (compareStrings(str1, str2)) {
        cout << "The strings are equal." << endl;
    } else {
        cout << "The strings are not equal." << endl;
    }

    cout << "Length of the first string: " << strlen(str1) << endl;
    cout << "Length of the second string: " << strlen(str2) << endl;

    deallocateString(str1);
    deallocateString(str2);
    deallocateString(concatenated);

    return 0;
}
