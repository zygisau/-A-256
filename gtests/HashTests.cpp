#include "gtest/gtest.h"

class HashTests : public ::testing::Test {
protected:
    int a;
    void SetUp() override {
        a = 8;
    }
    void TearDown() override {
        // dynamically allocated memory released here
    }
public:
	HashTests() {
		a = 8;
	}
};


TEST_F(HashTests, Equal8) {
    EXPECT_EQ(8, a);
}
