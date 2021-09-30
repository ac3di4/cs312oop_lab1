#include <gtest/gtest.h>

#include "Deltoid.hpp"

using curves::Deltoid;

class TestDeltoid : public ::testing::Test {
protected:
    Deltoid d;
protected:
    TestDeltoid() : d(3) {}
};

TEST_F(TestDeltoid, get_set) {
    d.set(5);
    ASSERT_DOUBLE_EQ(d.get(), 5);
    d.set(3);
    ASSERT_DOUBLE_EQ(d.get(), 3);
}

TEST_F(TestDeltoid, tangent_len) {
    ASSERT_DOUBLE_EQ(d.intersect_len(), 4);
}

TEST_F(TestDeltoid, curve_len) {
    ASSERT_DOUBLE_EQ(d.len(), 16);
}

TEST_F(TestDeltoid, curve_area) {
    ASSERT_DOUBLE_EQ(d.area(), 6.2831853071795862);
}

TEST_F(TestDeltoid, cartesian) {
    ASSERT_EQ(d.equation(), "(x^2 + y^2)^2 + 8 * 1 * x (x^2 - 3 * y^2) + 18 * 1^2 * (x^2 + y^2) - 27 * 1^4 = 0");
}

TEST_F(TestDeltoid, parameter) {
    auto pos = std::make_pair<double>(3, 0);
    ASSERT_DOUBLE_EQ(pos.first, 3);
    ASSERT_DOUBLE_EQ(pos.second, 0);
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}