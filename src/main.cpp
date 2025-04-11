#include "common.hpp"

// Basic Tests

TEST(ExampleTest, BasicFunctionality) {
    ASSERT_FALSE(true);
    EXPECT_STRNE("hello", "world");
}

TEST(ExampleTest, CallMain) {
    const char *args[] = { "main" };
    CALL_ASSIGNMENT_MAIN(args);
}

// Test fixtures

class FixtureExampleTest : public ::testing::Test {
    protected:
    FixtureExampleTest() : someState{42} {}

    int someState;
};

TEST_F(FixtureExampleTest, AnswerToEverything) {
    EXPECT_EQ(someState, 42);
}

// Parameterized tests

class ParamExampleTest : public ::testing::TestWithParam<int> {};

TEST_P(ParamExampleTest, MagicNumber) {
    ASSERT_EQ(GetParam(), 42);
}

INSTANTIATE_TEST_SUITE_P(ExampleInstantiation, ParamExampleTest, ::testing::Values(7, 42, 69));


int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    std::ignore = RUN_ALL_TESTS();
    const int total = ::testing::UnitTest::GetInstance()->total_test_count();
    const int failed = ::testing::UnitTest::GetInstance()->failed_test_count();
    return 100 - (100 * failed / total);
}
