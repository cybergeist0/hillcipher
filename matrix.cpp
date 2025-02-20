#include "matrix.h"
#include <iostream>

int det(matrix a) {
    return a[0][0] * (a[1][1] * a[2][2] - a[1][2] * a[2][1]) -
        a[0][1] * (a[1][0] * a[2][2] - a[1][2] * a[2][0]) +
        a[0][2] * (a[1][0] * a[2][1] - a[1][1] * a[2][0]);
}

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int modInverse(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1) return x;
    }
    return -1;
}

matrix toMatrix(string s, bool key, int part) {
    if (key) {
        if (s.size() == 9) {
            matrix a(3, vector<int>(3, 0));
            for (int i = 0; i < 9; i++) {
                a[i / 3][i % 3] = toupper(s[i]) - 'A';
            }
            return a;
        }
        else {
            cerr << "Invalid key size" << endl;
        }
    }
    else {
        matrix a(3, vector<int>(0));
        string section = s.substr(part * 3, 3);
        for (int i = 0; i < 3; i++) {
            a[i].push_back(toupper(section[i]) - 'A');
        }
        return a;
    }
    return matrix();
}

matrix multiply(matrix a, matrix b) {
    matrix c(a.size(), vector<int>(b[0].size(), 0));
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < b[0].size(); j++) {
            for (int k = 0; k < a[0].size(); k++) {
                c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % 26;
            }
        }
    }
    return c;
}

matrix inverse(matrix a) {
    int d = det(a);
    int m = 26;
    int inv = modInverse(d, m);
    matrix b(3, vector<int>(3, 0));
    b[0][0] = (a[1][1] * a[2][2] - a[1][2] * a[2][1]) * inv;
    b[0][1] = (a[0][2] * a[2][1] - a[0][1] * a[2][2]) * inv;
    b[0][2] = (a[0][1] * a[1][2] - a[0][2] * a[1][1]) * inv;
    b[1][0] = (a[1][2] * a[2][0] - a[1][0] * a[2][2]) * inv;
    b[1][1] = (a[0][0] * a[2][2] - a[0][2] * a[2][0]) * inv;
    b[1][2] = (a[0][2] * a[1][0] - a[0][0] * a[1][2]) * inv;
    b[2][0] = (a[1][0] * a[2][1] - a[1][1] * a[2][0]) * inv;
    b[2][1] = (a[0][1] * a[2][0] - a[0][0] * a[2][1]) * inv;
    b[2][2] = (a[0][0] * a[1][1] - a[0][1] * a[1][0]) * inv;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            b[i][j] = (b[i][j] % m + m) % m;
        }
    }
    return b;
}

string parse(string s) {
    int extraCharsNeeded = (3 - s.size() % 3) % 3;
    for (int i = 0; i < extraCharsNeeded; i++) {
        s += 'X';
    }
    return s;
}
