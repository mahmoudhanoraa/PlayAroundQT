#include <QCoreApplication>
#include "gtest/gtest.h"
#include <QString>
#include "../The_Snake/snake.h"

double squareroot (const double x){
    return sqrt(x);
}
TEST(SquareRootTest, PositiveNos) {
//    EXPECT_EQ (18.0, squareroot (324.0));
//    EXPECT_EQ (25.4, squareroot (645.16));
//    EXPECT_EQ (50.332, squareroot (2533.310224));
    QString str = "Hello";
    EXPECT_EQ (str.toUpper(), QString("HELLO"));
    Snake s(20, 30);
    EXPECT_EQ (QString("hanora"), s.getLastPos());
}

TEST (SquareRootTest, ZeroAndNegativeNos) {
    ASSERT_EQ (0.0, squareroot (0.0));
//    ASSERT_EQ (-1, squareroot (-22.0));
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
