#include "cipher.h"
#include "matrix.h"

string encode(const string& plaintext, const string& key) {
    matrix keyMatrix = toMatrix(key);
    string parsedText = parse(plaintext);
    string ciphertext;

    for (int i = 0; i < parsedText.size() / 3; i++) {
        matrix textMatrix = toMatrix(parsedText, false, i);
        matrix resultMatrix = multiply(keyMatrix, textMatrix);
        for (int j = 0; j < 3; j++) {
            ciphertext += (resultMatrix[j][0] % 26) + 'A';
        }
    }

    return ciphertext;
}

string decode(const string& ciphertext, const string& key) {
    matrix keyMatrix = toMatrix(key);
    matrix invKeyMatrix = inverse(keyMatrix);
    string parsedText = parse(ciphertext);
    string plaintext;

    for (int i = 0; i < parsedText.size() / 3; i++) {
        matrix textMatrix = toMatrix(parsedText, false, i);
        matrix resultMatrix = multiply(invKeyMatrix, textMatrix);
        for (int j = 0; j < 3; j++) {
            plaintext += (resultMatrix[j][0] % 26) + 'A';
        }
    }

    return plaintext;
}
