#define _CRT_SECURE_NO_WARNINGS
#include "matrix.h"
#include "cipher.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
    freopen("c.in", "r", stdin);
    freopen("c.out", "w", stdout);
    string command;
    cin >> command;
    if (command == "encode") {
        string plaintext, key;
        cin >> plaintext >> key;
        cout << encode(plaintext, key) << endl;
    }
    else if (command == "decode") {
        string ciphertext, key;
        cin >> ciphertext >> key;
        cout << decode(ciphertext, key) << endl;
    }

    return 0;
}
