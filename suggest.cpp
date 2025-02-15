#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

int determinantMod26(vector<vector<int>> key) {
    int det = (key[0][0] * key[1][1] - key[0][1] * key[1][0]) % 26;
    if (det < 0) det += 26; // Ensure non-negative determinant
    return det;
}

// Check if a key phrase forms a valid key
bool isValidKey(string keyPhrase) {
    if (keyPhrase.length() < 4) return false;

    // Convert key phrase to uppercase and remove non-alphabetic characters
    keyPhrase.erase(remove_if(keyPhrase.begin(), keyPhrase.end(), [](char c) { return !isalpha(c); }), keyPhrase.end());
    transform(keyPhrase.begin(), keyPhrase.end(), keyPhrase.begin(), ::toupper);

    // Extract first four letters as key matrix
    vector<vector<int>> key = {
        { keyPhrase[0] - 'A', keyPhrase[1] - 'A' },
        { keyPhrase[2] - 'A', keyPhrase[3] - 'A' }
    };

    return gcd(determinantMod26(key), 26) == 1;
}

// Function to generate valid 4-letter keys from a given phrase
vector<string> findValidKeys(string phrase) {
    vector<string> validKeys;

    // Convert phrase to uppercase and remove non-alphabetic characters
    phrase.erase(remove_if(phrase.begin(), phrase.end(), [](char c) { return !isalpha(c); }), phrase.end());
    transform(phrase.begin(), phrase.end(), phrase.begin(), ::toupper);

    // Extract all possible four-letter substrings and check validity
    for (size_t i = 0; i <= phrase.length() - 4; i++) {
        string keyCandidate = phrase.substr(i, 4);
        if (isValidKey(keyCandidate)) {
            validKeys.push_back(keyCandidate);
        }
    }

    return validKeys;
}

int main() {
    string phrase;
    getline(cin, phrase);

    vector<string> validKeys = findValidKeys(phrase);

    if (!validKeys.empty()) {
        cout << "Valid key phrases for Hill Cipher:\n";
        for (const string& key : validKeys) {
            cout << "- " << key << endl;
        }
    } else {
        cout << "No valid key phrases found. Try a different phrase." << endl;
    }

    return 0;
}
