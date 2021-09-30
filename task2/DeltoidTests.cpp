#include <gtest/gtest.h>

#include "Deltoid.hpp"

using curves::Deltoid;

class DeltoidTests : public ::testing::Test {
protected:
    Deltoid d;
};

TEST_F(DeltoidTests, constructors) {
    Deltoid d1;
    ASSERT_DOUBLE_EQ(d1.get(), 0);

    Deltoid d2(10);
    ASSERT_DOUBLE_EQ(d2.get(), 10);

    EXPECT_THROW(Deltoid d3(-10), std::range_error);
}

TEST_F(DeltoidTests, getters_and_setters) {
    ASSERT_DOUBLE_EQ(d.get(), 0);

    d.set(10);
    ASSERT_DOUBLE_EQ(d.get(), 10);

    EXPECT_THROW(d.set(-10), std::range_error);
}

TEST_F(DeltoidTests, tangent_len) {
    ASSERT_DOUBLE_EQ(d.intersect_len(), 0);

    d.set(3);
    ASSERT_DOUBLE_EQ(d.intersect_len(), 4);

    d.set(10);
    ASSERT_DOUBLE_EQ(d.intersect_len(), (4.0 / 3.0) * 10.0);
}

TEST_F(DeltoidTests, curve_len) {
    ASSERT_DOUBLE_EQ(d.len(), 0);

    d.set(3);
    ASSERT_DOUBLE_EQ(d.len(), 16);

    d.set(10);
    ASSERT_DOUBLE_EQ(d.len(), (16.0 / 3.0) * 10.0);
}

TEST_F(DeltoidTests, curve_area) {
    ASSERT_DOUBLE_EQ(d.area(), 0);

    d.set(3);
    ASSERT_DOUBLE_EQ(d.area(), (2.0 / 9.0) * M_PI * 3.0 * 3.0);

    d.set(10);
    ASSERT_DOUBLE_EQ(d.area(), (2.0 / 9.0) * M_PI * 10.0 * 10.0);

}

TEST_F(DeltoidTests, cartesian) {
    ASSERT_EQ(d.equation(), "(x^2 + y^2)^2 + 8 * 0 * x (x^2 - 3 * y^2) + 18 * 0^2 * (x^2 + y^2) - 27 * 0^4 = 0");

    d.set(3);
    ASSERT_EQ(d.equation(), "(x^2 + y^2)^2 + 8 * 1 * x (x^2 - 3 * y^2) + 18 * 1^2 * (x^2 + y^2) - 27 * 1^4 = 0");

    d.set(10);
    ASSERT_EQ(d.equation(), "(x^2 + y^2)^2 + 8 * 3.3 * x (x^2 - 3 * y^2) + 18 * 3.3^2 * (x^2 + y^2) - 27 * 3.3^4 = 0");
}

TEST_F(DeltoidTests, parameter) {
    auto pos = d.xy(40);
    ASSERT_DOUBLE_EQ(pos.first, 0);
    ASSERT_DOUBLE_EQ(pos.second, 0);

    d.set(3);
    pos = d.xy(1);
    ASSERT_DOUBLE_EQ(pos.first, 2 * std::cos(1) + std::cos(2));
    ASSERT_DOUBLE_EQ(pos.second, 2 * std::sin(1) - std::sin(2));

    d.set(10);
    pos = d.xy(0);
    ASSERT_DOUBLE_EQ(pos.first, 2.0 * 10 / 3 * std::cos(0) + 10.0 / 3 * std::cos(0));
    ASSERT_DOUBLE_EQ(pos.second, 2.0 * 10 / 3 * std::sin(0) - 10.0 / 3 * std::sin(0));
}


int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}