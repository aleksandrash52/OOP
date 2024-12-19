#include <gtest/gtest.h>
#include "forward_list.h"
#include "memory_resource.h"

TEST(FowardListTest, IntList) {
    FixedBlockMemoryResource memoryResource(1024);
    ForwardList<int> intList(&memoryResource);

    intList.push_front(1);
    intList.push_front(2);
    intList.push_front(3);

    auto it = intList.begin();
    EXPECT_EQ(*it, 3);
    ++it;
    EXPECT_EQ(*it, 2);
    ++it;
    EXPECT_EQ(*it, 1);
    ++it;
    EXPECT_EQ(it, intList.end());
}

TEST(FowardListTest, ComplexList) {
    struct ComplexType {
        int a;
        double b;
    };

    FixedBlockMemoryResource memoryResource(1024);
    ForwardList<ComplexType> complexList(&memoryResource);

    complexList.push_front({1, 2.5});
    complexList.push_front({2, 3.5});
    complexList.push_front({3, 4.5});

    auto it = complexList.begin();
    EXPECT_EQ(it->a, 3);
    EXPECT_EQ(it->b, 4.5);
    ++it;
    EXPECT_EQ(it->a, 2);
    EXPECT_EQ(it->b, 3.5);
    ++it;
    EXPECT_EQ(it->a, 1);
    EXPECT_EQ(it->b, 2.5);
    ++it;
    EXPECT_EQ(it, complexList.end());
}
