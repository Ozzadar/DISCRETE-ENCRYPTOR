#include <iostream>
#include "Encrypter.h"

std::vector<long> StringToVector(const std::string& str) {

    std::vector<long> nums{};

    char ch = ' ';
    size_t pos = str.find( ch );
    size_t initialPos = 0;

    // Decompose statement
    while( pos != std::string::npos ) {
        nums.push_back(atol(str.substr( initialPos, pos - initialPos ).c_str()));
        initialPos = pos + 1;

        pos = str.find( ch, initialPos );
    }

    // Add the last one
    auto theString = str.substr( initialPos, std::min( pos, str.size() ) - initialPos + 1 );

    if (!theString.empty())
        nums.push_back(atol(theString.c_str() ));

    return nums;
}

int main() {
    // Create our encryptor
    auto encrypter = Encrypter(3, 11, 3, 7);
    // First we decrypt two classmates messages:

    // Message one
    std::string message1 = "26 01 27 17 32 19 09 31 21 12 26 32 04 24 26 28 26 05 14 26 31 32 "
                           "01 32 21 05 03 29 21 26 32 19 26 05 14 01 12 32 27 17 01 12 12 26 "
                           "05 13 26 32 08 21 14 32 09 05 27 26 32 13 24 01 28 04 26 31 32 23 "
                           "17 01 14 32 01 32 28 26 05 28 26 32 09 18 32 01 27 27 09 19 04 12 "
                           "03 28 17 19 26 05 14 ";

    auto message1Nums = StringToVector(message1);
    auto decryptedMessage1 = encrypter.Decrypt(message1Nums);

    std::cout << decryptedMessage1 << std::endl;

    // Message two:
    std::string message2 = "03 32 23 03 12 12 32 21 28 26 32 14 17 26 32 12 01 "
                           "23 28 32 09 18 32 12 09 13 03 27 32 01 05 31 32 27 "
                           "24 16 04 14 09 13 24 01 04 17 16 32 14 09 32 19 01 "
                           "11 26 32 04 21 20 20 12 26 28 32 18 09 24 32 31 21 "
                           "05 13 26 09 05 28 32 01 05 31 32 31 24 01 13 09 05 28";

    auto message2Nums = StringToVector(message2);
    auto decryptedMessage = encrypter.Decrypt(message2Nums);

    std::cout << decryptedMessage << std::endl;

    // Then we'll generate our message:=
    std::string myMessage = "If you'd like code for decrypting these messages you can check my github at: https://github.com/ozzadar/DISCRETE-ENCRYPTOR";
    encrypter.EncryptString(myMessage, true);


    std::string myEncryptedMessage = "3 18 32 16 9 21 2 31 32 12 3 11 26 32 27 9 31 26 "
                                     "32 18 9 24 32 31 26 27 24 16 4 14 3 5 13 32 14 17 "
                                     "26 28 26 32 19 26 28 28 1 13 26 28 32 16 9 21 32 27 "
                                     "1 5 32 27 17 26 27 11 32 19 16 32 13 3 14 17 21 8 32 1 "
                                     "14 25 32 17 14 14 4 28 25 6 6 13 3 14 17 21 8 15 27 9 19 "
                                     "6 9 20 20 1 31 1 24 6 31 3 28 27 24 26 14 26 7 26 5 27 24 16 4 14 9 24";

    auto myMessageNums = StringToVector(myEncryptedMessage);
    auto myDecryptedMessage = encrypter.Decrypt(myMessageNums);

    std::cout << myDecryptedMessage << std::endl;
    return 0;
}