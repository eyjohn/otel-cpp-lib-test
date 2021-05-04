#include <hello.h>
#include <gmock/gmock.h>
#include <gtest/gtest.h>

using namespace ::testing;

TEST(TestHello, Hello)
{
    hello();
}
