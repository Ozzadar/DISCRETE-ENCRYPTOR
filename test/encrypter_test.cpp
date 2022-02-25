//
// Created by Paul Mauviel on 2022-02-25.
//

#include "gtest/gtest.h"
#include "encrypter.h"
#include <string>

constexpr auto SUITE_NAME = "Encrypter Tests";

TEST(SUITE_NAME, properly_converts_string_to_integers) {
    std::vector<long> expected  {1, 32, 3, 1, 2};
    std::string theString {"A CAB"};

    EXPECT_EQ(Encrypter::ConvertStringToNumbers(theString), expected);
}

TEST(SUITE_NAME, properly_applies_toUpper) {
    std::vector<long> expected  {1, 32, 3, 1, 2};
    std::string theString {"a cab"};

    EXPECT_EQ(Encrypter::ConvertStringToNumbers(theString), expected);
}

TEST(SUITE_NAME, properly_converts_numbers_to_string) {
    std::vector<long> nums  {1, 32, 3, 1, 2};
    std::string expected {"A CAB"};

    EXPECT_EQ(Encrypter::ConvertNumbersToString(nums), expected);
}

TEST(SUITE_NAME, does_not_convert_unnaccepted_numbers) {
    std::vector<long> nums  {1, 32, 3, 33, 2};
    std::string expected {"A CAB"};

    EXPECT_DEATH(Encrypter::ConvertNumbersToString(nums), "Not a valid number");
}

TEST(SUITE_NAME, does_not_convert_unnaccepted_characters) {
    std::vector<long> expected  {1, 32, 3, 1, 2};
    std::string theString {"A CAB??"};

    EXPECT_DEATH(Encrypter::ConvertStringToNumbers(theString), "Character is not valid for encryption.");
}

TEST(SUITE_NAME, properly_encrypts_string) {
    std::string theString {"A CAB"};
    std::vector<long> expected {1, 32, 27, 1, 8};

    auto encryptor = Encrypter(3, 11, 3,7);
    auto encrypted = encryptor.EncryptString(theString, true);
    EXPECT_EQ(encrypted, expected);
}

TEST(SUITE_NAME, properly_decrypts_string) {
    std::vector<long> encryptedMessage {1, 32, 27, 1, 8};
    std::string expected {"A CAB"};

    auto encryptor = Encrypter(3, 11, 3,7);
    auto encrypted = encryptor.Decrypt(encryptedMessage);
    EXPECT_EQ(encrypted, expected);
}