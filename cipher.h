#ifndef CIPHER_H
#define CIPHER_H
#include <string>
using namespace std;

string encode(const string& plaintext, const string& key);
string decode(const string& ciphertext, const string& key);

#endif // CIPHER_H
