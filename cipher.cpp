#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

int modInverse(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1) {
            return x;
        }
    }
    return -1; // No modular inverse
}

int determinantMod26(vector<vector<int>> key) {
    int det = (key[0][0] * key[1][1] - key[0][1] * key[1][0]) % 26;
    if (det < 0) det += 26; // non-negative determinant
    return det;
}

vector<vector<int>> inverseMatrixMod26(vector<vector<int>> key) {
    int det = determinantMod26(key);
    int detInv = modInverse(det, 26);

    if (detInv == -1) {
        cerr << "Key matrix is not invertible under mod 26. Please try a different key phrase." << endl;
        return {};
    }

    // Adj matrix
    vector<vector<int>> inverseKey = {
        { key[1][1], -key[0][1] },
        { -key[1][0], key[0][0] }
    };

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            inverseKey[i][j] = (inverseKey[i][j] * detInv) % 26;
            if (inverseKey[i][j] < 0) inverseKey[i][j] += 26;
        }
    }

    return inverseKey;
}

vector<vector<int>> generateKeyMatrix(string keyPhrase) {
    vector<vector<int>> key(2, vector<int>(2));

    // Remove non-alphabetic characters and convert to uppercase
    keyPhrase.erase(remove_if(keyPhrase.begin(), keyPhrase.end(), [](char c) { return !isalpha(c); }), keyPhrase.end());
    transform(keyPhrase.begin(), keyPhrase.end(), keyPhrase.begin(), ::toupper);

    if (keyPhrase.length() < 4) {
        cerr << "Key phrase must contain at least 4 letters." << endl;
        return {};
    }

    // Assign first 4 letters to matrix
    key[0][0] = keyPhrase[0] - 'A';
    key[0][1] = keyPhrase[1] - 'A';
    key[1][0] = keyPhrase[2] - 'A';
    key[1][1] = keyPhrase[3] - 'A';

    if (gcd(determinantMod26(key), 26) != 1) {
        cerr << "Invalid key matrix! Choose another phrase with a key that has gcd(det, 26) = 1." << endl;
        return {};
    }

    return key;
}

string hillEncrypt(string plaintext, vector<vector<int>> key) {
    plaintext.erase(remove_if(plaintext.begin(), plaintext.end(), [](char c) { return !isalpha(c); }), plaintext.end());
    transform(plaintext.begin(), plaintext.end(), plaintext.begin(), ::toupper);

    // Ensure length is even by padding with 'X'
    if (plaintext.length() % 2 != 0) {
        plaintext += 'X';
    }

    string ciphertext = "";
    
    for (size_t i = 0; i < plaintext.length(); i += 2) {
        vector<int> block = {plaintext[i] - 'A', plaintext[i + 1] - 'A'};
        vector<int> encryptedBlock = {
            (key[0][0] * block[0] + key[0][1] * block[1]) % 26,
            (key[1][0] * block[0] + key[1][1] * block[1]) % 26
        };

        ciphertext += (char)(encryptedBlock[0] + 'A');
        ciphertext += (char)(encryptedBlock[1] + 'A');
    }

    return ciphertext;
}

string hillDecrypt(string ciphertext, vector<vector<int>> key) {
    vector<vector<int>> inverseKey = inverseMatrixMod26(key);
    if (inverseKey.empty()) {
        return "Decryption failed - Key matrix is not invertible.";
    }

    string plaintext = "";
    
    for (size_t i = 0; i < ciphertext.length(); i += 2) {
        vector<int> block = {ciphertext[i] - 'A', ciphertext[i + 1] - 'A'};
        vector<int> decryptedBlock = {
            (inverseKey[0][0] * block[0] + inverseKey[0][1] * block[1]) % 26,
            (inverseKey[1][0] * block[0] + inverseKey[1][1] * block[1]) % 26
        };

        plaintext += (char)(decryptedBlock[0] + 'A');
        plaintext += (char)(decryptedBlock[1] + 'A');
    }

    return plaintext;
}

int main() {
    string operation, phrase, keyPhrase;
    cin >> operation;
    cin.ignore();
    getline(cin, phrase);
    getline(cin, keyPhrase);

    vector<vector<int>> key = generateKeyMatrix(keyPhrase);
    if (key.empty()) return 1;

    if (operation == "encrypt") {
        cout << "Ciphertext: " << hillEncrypt(phrase, key) << endl;
    } 
    else if (operation == "decrypt") {
        cout << "Decrypted Text: " << hillDecrypt(phrase, key) << endl;
    } 
    else {
        cerr << "Invalid operation! Use 'encrypt' or 'decrypt'." << endl;
    }

    return 0;
}
