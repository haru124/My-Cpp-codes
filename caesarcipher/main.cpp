#include <iostream>
#include <string>
using namespace std;

std::string encryptCaesarCipher(const std::string& plaintext, int rotation) {
    std::string ciphertext = "";

    for (char ch : plaintext) {
        if (isalpha(ch)) {
            char base = islower(ch) ? 'a' : 'A';
            ciphertext += static_cast<char>((ch - base + rotation) % 26 + base);
        } else {
            // Keep non-alphabetic characters unchanged
            ciphertext += ch;
        }
    }

    return ciphertext;
}

int main() {
    std::string plaintext;
    int rotation = 4;
    char g;
    cin>>g;
    g+=4;
    cout<<g;

    std::cout << "Enter plaintext: ";
    std::getline(std::cin, plaintext);

    std::string ciphertext = encryptCaesarCipher(plaintext, rotation);

    std::cout << "Ciphertext: " << ciphertext << std::endl;

    return 0;
}
