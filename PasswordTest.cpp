/**
 * Unit Tests for Password class
**/

#include <gtest/gtest.h>
#include "Password.h"

// This is a test feature
class PasswordTest : public ::testing::Test
{
	protected:
		// This is a test fixture
		PasswordTest(){} //constructor runs before each test
		virtual ~PasswordTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

// If you add a feature, use TEST_F

TEST(PasswordTest, smoke_test)
{
    ASSERT_TRUE( 1 == 1 );
}
TEST(PasswordTest, single_letter_password)
{
  Password my_password;
	int actual = my_password.count_leading_characters("Z");
	ASSERT_EQ(0,actual);
}

TEST(PasswordTest, spaces_in_password){
	Password my_password;
	int spaces = my_password.count_leading_characters("   ");
	ASSERT_EQ(3,spaces);
}

// TEST(PasswordTest, spaces_at_end_of_password){
// 	Password my_password;
// 	int spaces = my_password.count_leading_characters("abc   ");
// 	ASSERT_EQ(3,spaces);
// }

TEST(PasswordTest, numbers_in_password){
	Password my_password;
	int numbers = my_password.count_leading_characters("123ABC");
	ASSERT_EQ(0,numbers);
}

TEST(PasswordTest, repeating_numbers_in_password){
	Password my_password;
	int repeating_numbers = my_password.count_leading_characters("111");
	ASSERT_EQ(3,repeating_numbers);
}

TEST(PasswordTest, repeating_symbols_in_password){
	Password my_password;
	int symbols = my_password.count_leading_characters("!!?@");
	ASSERT_EQ(2,symbols);
}

TEST(PasswordTest, empty_password){
	Password my_password;
	int empty = my_password.count_leading_characters("");
	ASSERT_EQ(0,empty);
}

TEST(PasswordTest, mixed_case_password){
	Password my_password;
	bool mixed_case = my_password.has_mixed_case("AbCd");
	ASSERT_EQ(true,mixed_case);
}

TEST(PasswordTest, all_upper_case_password){
	Password my_password;
	bool all_upper_case = my_password.has_mixed_case("ABCD");
	ASSERT_EQ(false,all_upper_case);
}

TEST(PasswordTest, all_lower_case_password){
	Password my_password;
	bool all_lower_case = my_password.has_mixed_case("abcd");
	ASSERT_EQ(false,all_lower_case);
}

TEST(PasswordTest, mixed_case_with_symbols_password){
	Password my_password;
	bool mixed_case_with_symbols = my_password.has_mixed_case("AbCd!@#");
	ASSERT_EQ(true,mixed_case_with_symbols);
}

TEST(PasswordTest, mixed_case_with_numbers_password){
	Password my_password;
	bool mixed_case_with_numbers = my_password.has_mixed_case("AbCd123");
	ASSERT_EQ(true,mixed_case_with_numbers);
}

TEST(PasswordTest, mixed_case_with_spaces_password){
	Password my_password;
	bool mixed_case_with_spaces = my_password.has_mixed_case("AbCd  ");
	ASSERT_EQ(true,mixed_case_with_spaces);
}

TEST(PasswordTest, no_mixed_case_with_spaces){
	Password my_password;
	bool no_mixed_case_with_spaces = my_password.has_mixed_case("abcd  ");
	ASSERT_EQ(false,no_mixed_case_with_spaces);
}

TEST(PasswordTest, mixed_case_with_empty_password){
	Password my_password;
	bool mixed_case_with_empty = my_password.has_mixed_case("");
	ASSERT_EQ(false,mixed_case_with_empty);
}

TEST(PasswordTest, mixed_case_space_and_symbols_password){
	Password my_password;
	bool mixed_case_space_and_symbols = my_password.has_mixed_case(" A");
	ASSERT_EQ(false,mixed_case_space_and_symbols);
}

TEST(PasswordTest, mixed_case_with_symbols_and_numbers_password){
	Password my_password;
	bool mixed_case_with_symbols_and_numbers = my_password.has_mixed_case("AbCd!@#123");
	ASSERT_EQ(true,mixed_case_with_symbols_and_numbers);
}