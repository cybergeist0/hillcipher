# Hill Cipher
The Hill cipher is a polygraphic substitution cipher based on linear algebra. Invented by Lester S. Hill in 1929, it was the first polygraphic cipher in which it was practical (though barely) to operate on more than three symbols at once.
## Key
A key is required to encrypt and decrypt text. The key is a square matrix of size n x n. This alogrithm uses 3x3 matrices to encrypt and decrypt text; therefore, the key must be 9 (3x3) characters long. Additionally, this key must be invertible in modulo 26, meaning that its determinant must be coprime with 26.
## Encryption
Once a key has been established, you can encrypt text using the Hill cipher. To encrypt plaintext, the first word in `c.in` should be `encode`. The word after that is the plaintext (don't use spaces, as they will not matter in this algorithm). The final word in the input is the key.
## Decyption
A similar process is used to decrypt ciphertext. The first word in `c.in` should be `decode`, and the second word should be the cihpertext. The last word should be the key that the text was encrypted with.

All outputs will be in the file `c.out`.