#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <string>

using namespace std;
using matrix = vector<vector<int>>;

int det(matrix a);
int gcd(int a, int b);
int modInverse(int a, int m);
matrix toMatrix(string s, bool key = true, int part = -1);
matrix multiply(matrix a, matrix b);
matrix inverse(matrix a);
string parse(string s);

#endif // MATRIX_H
