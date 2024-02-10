#include <gtest/gtest.h>
#include "binary.h"

TEST(initialization, test_1)
{
    Binary obj1 {'1','0', '1', '1'};
    Binary obj2("1011");

    ASSERT_TRUE(obj1.equals(obj2));
}

TEST(initialization, test_2)
{
    Binary obj1 {'1', '0', '1', '1'};
    Binary obj2(obj1);
    Binary obj3(std::move(obj1));
    Binary obj4;

    ASSERT_TRUE(obj3.equals(obj2) && obj1.equals(obj4));
}

TEST(initialization, test_3)
{
    ASSERT_ANY_THROW(Binary obj1("123"));
    ASSERT_ANY_THROW(Binary obj2("1101."));
    ASSERT_NO_THROW(Binary obj3(""));
}

TEST(initialization, test_4)
{
    Binary obj1;
    Binary obj2("");
    Binary obj3(std::move(obj1));
    Binary obj4{};

    ASSERT_TRUE(obj1.equals(obj2) && obj2.equals(obj3) && obj3.equals(obj4));
}

TEST(initialization, test_5)
{
    Binary obj1("0000");
    Binary obj2 {'0','0','0'};
    Binary obj3(23, '0');
    Binary obj4("0");
    ASSERT_TRUE(obj1.equals(obj2));
    ASSERT_TRUE(obj2.equals(obj3));
    ASSERT_TRUE(obj3.equals(obj4));
}

TEST(initialization, test_6)
{
    Binary obj1("0010110");
    Binary obj2 {'0','0','0', '1', '0', '1', '1', '0'};
    Binary obj3("10110");
    ASSERT_TRUE(obj1.equals(obj2));
    ASSERT_TRUE(obj2.equals(obj3));
}

TEST(methods, more)
{
    Binary obj1("1011");
    Binary obj2("1010");
    Binary obj3(obj1);
    Binary obj4;
    Binary obj5("100001");

    ASSERT_TRUE(obj1.more(obj2));
    ASSERT_FALSE(obj1.more(obj3));
    ASSERT_FALSE(obj2.more(obj3));
    ASSERT_FALSE(obj4.more(obj1));
    ASSERT_TRUE(obj2.more(obj4));
    ASSERT_TRUE(obj5.more(obj1));
}

TEST(methods, less)
{
    Binary obj1("1001");
    Binary obj2("1000");
    Binary obj3(obj1);
    Binary obj4;
    Binary obj5("10");

    ASSERT_FALSE(obj1.less(obj2));
    ASSERT_TRUE(obj2.less(obj1));
    ASSERT_FALSE(obj1.less(obj3));
    ASSERT_TRUE(obj4.less(obj1));
    ASSERT_FALSE(obj1.less(obj4));   
    ASSERT_FALSE(obj1.less(obj5)); 
    ASSERT_TRUE(obj5.less(obj3));
}

TEST(methods, equal)
{
    Binary obj1("1011");
    Binary obj2("1010");
    Binary obj3(obj1);

    ASSERT_TRUE(obj1.equals(obj3));
    ASSERT_FALSE(obj1.equals(obj2));
    ASSERT_FALSE(obj2.equals(obj1));
}

TEST(methods, add_1)
{
    Binary obj1;
    Binary obj2("101");
    Binary obj3("100111");
    Binary obj4("101100");
    Binary obj5("1010");

    ASSERT_TRUE((obj1.add(obj2)).equals(obj2));
    ASSERT_TRUE((obj2.add(obj1)).equals(obj2));
    ASSERT_TRUE((obj2.add(obj3)).equals(obj4));
    ASSERT_TRUE((obj3.add(obj2)).equals(obj4));
    ASSERT_TRUE((obj2.add(obj2)).equals(obj5));
}

TEST(methods, add_2)
{
    Binary obj1("0");
    Binary obj2("111");

    ASSERT_TRUE((obj1.add(obj2)).equals(obj2));
    ASSERT_TRUE((obj2.add(obj1)).equals(obj2));
}


TEST(methods, remove)
{
    Binary obj1;
    Binary obj2("0");
    Binary obj3("10110");
    Binary obj4("1011");

    ASSERT_ANY_THROW(Binary obj(obj1.remove(obj2)));
    ASSERT_ANY_THROW(Binary obj(obj2.remove(obj3)));
    ASSERT_TRUE((obj3.remove(obj2)).equals(obj3));    
    ASSERT_TRUE((obj3.remove(obj4)).equals(obj4)); 
    ASSERT_TRUE((obj3.remove(obj3)).equals(obj2)); 
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}