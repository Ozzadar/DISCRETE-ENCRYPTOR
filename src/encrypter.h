//
// Created by Paul Mauviel on 2022-02-25.
//

#ifndef TESTCPP_ENCRYPTER_H
#define TESTCPP_ENCRYPTER_H

#include <cassert>
#include <array>
#include <cctype>
#include <vector>
#include <string>

class Encrypter {
public:
    Encrypter(long p, long q, long e, long d);

    [[nodiscard]] std::vector<long> EncryptString(const std::string& message, bool print = false) const;
    [[nodiscard]] std::string Decrypt(const std::vector<long>& message) const;

private:
    long _p {0};
    long _q {0};
    long _e {0};
    long _d {0};

    // STATIC FUNCTIONS
public:
    static inline long ConvertCharacter(char character) {
        char uppChar = toupper(character);

        auto it = std::find(ACCEPTABLE_CHARACTERS.begin(), ACCEPTABLE_CHARACTERS.end(), uppChar);

        if (it != ACCEPTABLE_CHARACTERS.end())
        {
            return std::distance(ACCEPTABLE_CHARACTERS.begin(), it) + 1;
        }

        assert(false && "Character is not valid for encryption.");
    }

    static inline char ConvertNumber(long number) {
        assert(number <= ACCEPTABLE_CHARACTERS.size() && "Not a valid number");
        long index = number - 1;

        return ACCEPTABLE_CHARACTERS[index];
    }

    static inline std::vector<long> ConvertStringToNumbers(const std::string& theString) {
        std::vector<long> numberVector {};

        for (auto ch : theString) {
            numberVector.push_back(ConvertCharacter(ch));
        }

        return numberVector;
    };

    static inline std::string ConvertNumbersToString(const std::vector<long>& numbers) {
        std::string theString {};

        for (auto num : numbers) {
            theString += ConvertNumber(num);
        }

        return theString;
    };

private:
    static constexpr std::array<char, 32> ACCEPTABLE_CHARACTERS {
        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V',
        'W', 'X', 'Y', 'Z', '.', '-', '\'', '/', ':', ' '
    };


};


#endif //TESTCPP_ENCRYPTER_H
