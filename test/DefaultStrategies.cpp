#include <gtest/gtest.h>

#include <include/strategies/AlwaysBetrayStrategy.h>
#include <include/strategies/AlwaysCooperateStrategy.h>
#include <include/strategies/EnviousStrategy.h>
#include <include/strategies/RevengefulStrategy.h>
#include <include/strategies/RevengefulMercifulStrategy.h>
#include <include/strategies/RandomStrategy.h>
#include <include/strategies/UltimateRandomStrategy.h>


class StrategyTest : public ::testing::Test {
protected:
    MoveTable table;
    ScoreTable score_table;

    void SetUp() override {
        table = {{Cooperate, Betray, Cooperate}, {Betray, Cooperate, Betray}, {Cooperate, Cooperate, Betray}};
        score_table = {{3, 0, 3}, {0, 3, 1}, {3, 1, 0}};
    }
};


TEST_F(StrategyTest, AlwaysBetrayStrategy) {
    AlwaysBetrayStrategy strategy;
    EXPECT_EQ(strategy.GetMove(table, score_table, 0, 0), Betray);
    EXPECT_EQ(strategy.GetMove(table, score_table, 1, 0), Betray);
    EXPECT_EQ(strategy.GetMove(table, score_table, 2, 0), Betray);
}


TEST_F(StrategyTest, AlwaysCooperateStrategy) {
    AlwaysCooperateStrategy strategy;
    EXPECT_EQ(strategy.GetMove(table, score_table, 0, 0), Cooperate);
    EXPECT_EQ(strategy.GetMove(table, score_table, 1, 0), Cooperate);
    EXPECT_EQ(strategy.GetMove(table, score_table, 2, 0), Cooperate);
}


TEST_F(StrategyTest, EnviousStrategy) {
    EnviousStrategy strategy;

    // Always betray
    EXPECT_EQ(strategy.GetMove(table, score_table, 0, 0), Betray);
    EXPECT_EQ(strategy.GetMove(table, score_table, 1, 0), Betray);
    EXPECT_EQ(strategy.GetMove(table, score_table, 2, 0), Betray);

    // Decisions based on score_table
    EXPECT_EQ(strategy.GetMove(table, score_table, 0, 1), Cooperate);
    EXPECT_EQ(strategy.GetMove(table, score_table, 1, 1), Betray);
    EXPECT_EQ(strategy.GetMove(table, score_table, 2, 1), Cooperate);
}


TEST_F(StrategyTest, RevengefulStrategy) {
    RevengefulStrategy strategy;

    // Should cooperate
    EXPECT_EQ(strategy.GetMove(table, score_table, 0, 0), Cooperate);

    // Based on previous moves in table
    EXPECT_EQ(strategy.GetMove(table, score_table, 0, 1), Betray);     // Based on table[0][1]
    EXPECT_EQ(strategy.GetMove(table, score_table, 1, 1), Cooperate);  // Based on table[1][0]
    EXPECT_EQ(strategy.GetMove(table, score_table, 2, 1), Betray);     // Based on table[2][0]
}


TEST_F(StrategyTest, RevengefulMercifulStrategy) {
    RevengefulMercifulStrategy strategy;

    // Should cooperate
    EXPECT_EQ(strategy.GetMove(table, score_table, 0, 0), Cooperate);

    // Based on table and rules
    EXPECT_EQ(strategy.GetMove(table, score_table, 0, 1), Cooperate);  // Based on table[0][1] and table[0][2]
    EXPECT_EQ(strategy.GetMove(table, score_table, 1, 1), Cooperate);  // Based on table[1][0] and table[1][2]
    EXPECT_EQ(strategy.GetMove(table, score_table, 2, 1), Cooperate);     // Based on table[2][0] and table[2][1]
}


TEST_F(StrategyTest, RandomStrategy) {
    RandomStrategy strategy;

    // Randomly
    for (int i = 0; i < 100; i++) {
        Choice move = strategy.GetMove(table, score_table, 0, 0);
        EXPECT_TRUE(move == Cooperate || move == Betray);
    }
}


TEST_F(StrategyTest, UltimateRandomStrategy) {
    UltimateRandomStrategy strategy;

    // Since this strategy randomly picks one of the strategies, we can only check that it is valid
    for (int i = 0; i < 100; i++) {
        Choice move = strategy.GetMove(table, score_table, 0, 0);
        EXPECT_TRUE(move == Cooperate || move == Betray);
    }
}
