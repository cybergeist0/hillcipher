# Hill Cipher
A simple encryption algorithm that utilizes linear algebra to encrypt plaintext.
## Suggestions
Before you attempt to encrypt any given plaintext, you should first pair it with a key of your choice. An optimal key is one that can be used to encrypt and decrypt ciphertext losslessly. To find a list of four-letter keys that have a certainty of working for your plaintext, run the `suggest.cpp` program and pass in your plaintext as an argument (stdin). There exist cases where a plaintext cannot be encrypted due to mathematical contraints.
## Usage
Once the plaintext is garaunteed to work with its respective key, run the `cipher.cpp` program and provide an input in this format:
```
<encrypt/decrypt>
<{plaintext}/{ciphertext}>
<key>
```
Note that you will have to compile the programs before you can run them if you are not using a web-based IDE.
