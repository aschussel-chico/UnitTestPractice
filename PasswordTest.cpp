/**
 * Unit Tests for Password class
**/

#include <gtest/gtest.h>
#include "Password.h"

class PasswordTest : public ::testing::Test
{
	protected:
		PasswordTest(){} //constructor runs before each test
		virtual ~PasswordTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

TEST(PasswordTest, single_letter_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("Z");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, mixed_case_upper_and_lower)
{
	Password my_password;
	ASSERT_TRUE(my_password.has_mixed_case("Hello"));
}

TEST(PasswordTest, mixed_case_all_lower)
{
	Password my_password;
	ASSERT_FALSE(my_password.has_mixed_case("hello"));
}

TEST(PasswordTest, mixed_case_all_upper)
{
	Password my_password;
	ASSERT_FALSE(my_password.has_mixed_case("HELLO"));
}

TEST(PasswordTest, mixed_case_no_letters)
{
	Password my_password;
	ASSERT_FALSE(my_password.has_mixed_case("1234!@#$"));
}

TEST(PasswordTest, mixed_case_with_digits_and_symbols)
{
	Password my_password;
	ASSERT_TRUE(my_password.has_mixed_case("p@ssW0rd!"));
}