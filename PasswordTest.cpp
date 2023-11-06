/**
 * Unit Tests for Password class
 **/

#include "Password.h"
#include <gtest/gtest.h>

class LeadingCharactersTest : public ::testing::Test {
protected:
    LeadingCharactersTest() {}          // constructor runs before each test
    virtual ~LeadingCharactersTest() {} // destructor cleans up after tests
    virtual void SetUp() {}    // sets up before each test (after constructor)
    virtual void TearDown() {} // clean up after each test, (before destructor)
};

TEST(PasswordTest, single_letter_password) {
    Password my_password;
    int actual = my_password.count_leading_characters("Z");
    ASSERT_EQ(1, actual);
}

TEST(PasswordTest, multi_letter_then_more_password) {
    Password pwd;
    int actual = pwd.count_leading_characters("ZZZZpassword");
    ASSERT_EQ(actual, 4);
}

TEST(PasswordTest, two_letter) {
    Password pwd;
    int actual = pwd.count_leading_characters("ZZ");
    ASSERT_EQ(actual, 2);
}

TEST(PasswordTest, three_letter) {
    Password pwd;
    int actual = pwd.count_leading_characters("ZZZ");
    ASSERT_EQ(actual, 3);
}

TEST(PasswordTest, three_letter_gap_three_letter) {
    Password pwd;
    int actual = pwd.count_leading_characters("ZZZaZZZ");
    ASSERT_EQ(actual, 3);
}

TEST(PasswordTest, three_letter_at_end) {
    Password pwd;
    int actual = pwd.count_leading_characters("aZZZ");
    ASSERT_EQ(actual, 1);
}

TEST(PasswordTest, empty_string) {
    Password pwd;
    int actual = pwd.count_leading_characters("");
    ASSERT_EQ(actual, 0);
}

class HasMixedCaseTest : public ::testing::Test {
protected:
    HasMixedCaseTest() {}          // constructor runs before each test
    virtual ~HasMixedCaseTest() {} // destructor cleans up after tests
    virtual void SetUp() {}    // sets up before each test (after constructor)
    virtual void TearDown() {} // clean up after each test, (before destructor)
};

TEST(HasMixedCaseTest, empty_password) {
    Password pwd;
    ASSERT_EQ(pwd.has_mixed_case(""), false);
}

TEST(HasMixedCaseTest, only_lowercase) {
    Password pwd;
    ASSERT_EQ(pwd.has_mixed_case("abcdefghijklmnopqrstuvxyz"), false);
}

TEST(HasMixedCaseTest, only_uppercase) {
    Password pwd;
    ASSERT_EQ(pwd.has_mixed_case("ABCDEFGHIJKLMNOPQRSTUVXYZ"), false);
}

TEST(HasMixedCaseTest, simple_mixed_case_start_of_range) {
    Password pwd;
    ASSERT_EQ(pwd.has_mixed_case("aA"), true);
}

TEST(HasMixedCaseTest, simple_mixed_case_end_of_range) {
    Password pwd;
    ASSERT_EQ(pwd.has_mixed_case("zZ"), true);
}
