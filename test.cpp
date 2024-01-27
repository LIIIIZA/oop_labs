#include <gtest/gtest.h>
#include "check.h"

TEST(test_is_clear, test_1)
{
    ASSERT_TRUE(IsClear("1123"));
}

TEST(test_is_clear, test_2)
{
    ASSERT_TRUE(IsClear("-1123"));
}

TEST(test_is_clear, test_3)
{
    ASSERT_FALSE(IsClear("321"));
}

TEST(test_is_clear, test_4)
{
    ASSERT_FALSE(IsClear("-33211"));
}

TEST(test_is_clear, test_5)
{
    ASSERT_TRUE(IsClear("0"));
}

TEST(test_is_clear, test_6)
{
    ASSERT_TRUE(IsClear("-1"));
}

TEST(test_is_clear, test_7)
{
    ASSERT_TRUE(IsClear("111"));
}

TEST(test_is_clear, test_8)
{
    ASSERT_TRUE(IsClear("-111"));
}

TEST(test_is_clear, test_9)
{
    ASSERT_TRUE(IsClear("0.0"));
}

TEST(test_is_clear, test_10)
{
    ASSERT_TRUE(IsClear("12.33"));
}

TEST(test_is_clear, test_11)
{
    ASSERT_TRUE(IsClear("-12.33"));
}

TEST(test_is_clear, test_12)
{
    ASSERT_FALSE(IsClear("6.456"));
}

TEST(test_is_clear, test_13)
{
    ASSERT_FALSE(IsClear("-6.456"));
}

TEST(test_is_clear, test_14)
{
    ASSERT_TRUE(IsClear("1.1"));
}

TEST(test_is_clear, test_15)
{
    ASSERT_TRUE(IsClear("-1.1"));
}

TEST(test_is_number, test_1)
{
    ASSERT_FALSE(IsNumber("1..234"));
}

TEST(test_is_number, test_2)
{
    ASSERT_FALSE(IsNumber(".123"));
}

TEST(test_is_number, test_3)
{
    ASSERT_FALSE(IsNumber("-.123"));
}

TEST(test_is_number, test_4)
{
    ASSERT_FALSE(IsNumber("3.4.56"));
}

TEST(test_is_number, test_5)
{
    ASSERT_FALSE(IsNumber("-1."));
}

TEST(test_is_number, test_6)
{
    ASSERT_FALSE(IsNumber("-sacd1.234"));
}

TEST(test_is_number, test_7)
{
    ASSERT_FALSE(IsNumber("-"));
}

TEST(test_is_number, test_8)
{
    ASSERT_FALSE(IsNumber("."));
}

TEST(test_is_number, test_9)
{
    ASSERT_FALSE(IsNumber(""));
}

TEST(test_is_number, test_10)
{
    ASSERT_FALSE(IsNumber("-332dssd11"));
}

TEST(test_is_number, test_11)
{
    ASSERT_FALSE(IsNumber("--111"));
}

TEST(test_is_number, test_12)
{
    ASSERT_FALSE(IsNumber("11-1"));
}

TEST(test_is_number, test_13)
{
    ASSERT_FALSE(IsNumber("111-"));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}