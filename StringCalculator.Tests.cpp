#include <gtest/gtest.h>
#include "StringCalculator.h"  // Ensure this is the correct path to your header file

TEST(StringCalculatorSumStringTests, ExpectZeroForEmptyInput) {
    int expectedresult = 0;
    const char* input = "";
    int result = sumString(input);
    ASSERT_EQ(result, expectedresult);
}

TEST(StringCalculatorSumStringTests, ExpectZeroForSingleZero) {
    int expectedresult = 0;
    const char* input = "0";
    int result = sumString(input);
    ASSERT_EQ(result, expectedresult);
}

TEST(StringCalculatorSumStringTests, ExpectSumForTwoNumbers) {
    int expectedresult = 3;
    const char* input = "1,2";
    int result = sumString(input);
    ASSERT_EQ(result, expectedresult);
}

TEST(StringCalculatorSumStringTests, ExpectSumWithNewlineDelimiter) {
    int expectedresult = 6;
    const char* input = "1\n2,3";
    int result = sumString(input);
    ASSERT_EQ(result, expectedresult);
}

TEST(StringCalculatorSumStringTests, IgnoreNumbersGreaterThan1000) {
    int expectedresult = 1;
    const char* input = "1,1001";
    int result = sumString(input);
    ASSERT_EQ(result, expectedresult);
}

TEST(StringCalculatorSumStringTests, ExpectSumWithCustomDelimiter) {
    int expectedresult = 3;
    const char* input = "//;\n1;2";
    int result = sumString(input);
    ASSERT_EQ(result, expectedresult);
}

TEST(StringCalculatorSumStringTests, ExpectSumWithCustomDelimiterAtStart) {
    int expectedresult = 2;
    const char* input = "\n2";
    int result = sumString(input);
    ASSERT_EQ(result, expectedresult);
}

TEST(StringCalculatorSumStringTests, ExpectSumWithDelimiterofAnyLength) {
    int expectedresult = 15;
    const char* input = "//[*]\n12***3";
    int result = sumString(input);
    ASSERT_EQ(result, expectedresult);
}

TEST(ExceptionHandlingTest, NegativeNumberException) {
    const char* input = "-1,2,3";
    ASSERT_THROW(sumString(input), std::runtime_error);
}
TEST(StringCalculatorSumStringTests, ExpectSumWithMultipleCustomDelimiters) {
    int expectedresult = 6;
    const char* input = "//[***][%%%]\n1***2%%%3";
    int result = sumString(input);
    ASSERT_EQ(result, expectedresult);
}

TEST(StringCalculatorSumStringTests, ExpectZeroForMultipleZeros) {
    int expectedresult = 0;
    const char* input = "0,0,0";
    int result = sumString(input);
    ASSERT_EQ(result, expectedresult);
}

TEST(StringCalculatorSumStringTests, ExpectSumForSingleNumber) {
    int expectedresult = 5;
    const char* input = "5";
    int result = sumString(input);
    ASSERT_EQ(result, expectedresult);
}

TEST(StringCalculatorSumStringTests, ExpectSumForNumbersWithMixedDelimiters) {
    int expectedresult = 10;
    const char* input = "1,2\n3,4";
    int result = sumString(input);
    ASSERT_EQ(result, expectedresult);
}

TEST(StringCalculatorSumStringTests, ExpectSumForNegativeAndPositiveNumbers) {
    int expectedresult = 0;  // The test should fail due to an exception
    const char* input = "-1,-2,3";
    ASSERT_THROW(sumString(input), std::runtime_error);
}
