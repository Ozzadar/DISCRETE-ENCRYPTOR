//
// Created by Paul Mauviel on 2022-02-25.
//

#include "encrypter.h"
#include <cmath>
#include <iostream>

Encrypter::Encrypter(long p, long q, long e, long d) : _p(p), _q(q), _e(e), _d(d) {}

std::vector<long> Encrypter::EncryptString(const std::string &message, bool print) const {
    // First, convert string to numbers.
    auto nums = ConvertStringToNumbers(message);

    // create a vector of appropriate size to hold encrypted value
    std::vector<long> encrypted {};
    encrypted.resize(nums.size());

    // Encrypt each letter
    for (int i = 0; i < nums.size(); i++) {
        auto num = nums[i];

        encrypted[i] = static_cast<long>(pow(num, _e)) % (_q * _p);
        if (print) {
            std::cout << encrypted[i] << " ";
        }
    }

    if (print) std::cout << std::endl;
    return encrypted;
}

std::string Encrypter::Decrypt(const std::vector<long> &message) const {
    // Create a vector of appropriate size to hold decrypted numbers
    std::vector<long> nums {};
    nums.resize(message.size());

    // Decrypt each letter
    for (int i = 0; i < message.size(); i++) {
        auto eNum = message[i];
        nums[i] = static_cast<long>(pow(eNum, _d)) % (_p * _q);
    }

    return ConvertNumbersToString(nums);
}
