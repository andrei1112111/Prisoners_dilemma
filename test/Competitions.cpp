#include <gtest/gtest.h>

#include <array>
#include <vector>
#include <sstream>
#include <iostream>

#include <include/strategies/StrategyFactory.h>
#include <include/competitions/TournamentCompetition.h>
#include <include/competitions/FastCompetition.h>
#include <include/competitions/DetailedCompetition.h>



ReferenceTable GetMockReferenceTable() {
    ReferenceTable refTable;
    refTable[Cooperate][Cooperate][Cooperate] = {3, 3, 3};
    refTable[Cooperate][Cooperate][Betray] = {0, 5, 5};
    refTable[Cooperate][Betray][Cooperate] = {5, 0, 5};
    refTable[Cooperate][Betray][Betray] = {1, 1, 1};
    refTable[Betray][Cooperate][Cooperate] = {5, 0, 5};
    refTable[Betray][Cooperate][Betray] = {1, 1, 1};
    refTable[Betray][Betray][Cooperate] = {0, 5, 5};
    refTable[Betray][Betray][Betray] = {3, 3, 3};
    return refTable;
}



class TournamentCompetitionTest : public ::testing::Test {
protected:
    void SetUp() override {
        strategies_ = {AlwaysBetrayEnum, AlwaysCooperateEnum, RandomEnum};
        reference_table_ = GetMockReferenceTable();
        competition_ = std::make_unique<TournamentCompetition>(strategies_, reference_table_, 10);
    }

    std::vector<StrategyEnum> strategies_;
    ReferenceTable reference_table_ {};
    std::unique_ptr<TournamentCompetition> competition_;
};

TEST_F(TournamentCompetitionTest, TournamentSimulationWorks) {
    std::stringstream output;
    std::streambuf* old_cout = std::cout.rdbuf(output.rdbuf());

    std::stringstream input("dummy_input\n");
    std::streambuf* old_cin = std::cin.rdbuf(input.rdbuf());

    competition_->Simulation();

    std::string result = output.str();
    EXPECT_NE(result.find("Strategy"), std::string::npos);
    EXPECT_NE(result.find("get"), std::string::npos);

    std::cout.rdbuf(old_cout);
    std::cin.rdbuf(old_cin);
}



class FastCompetitionTest : public ::testing::Test {
protected:
    void SetUp() override {
        strategies_ = {AlwaysBetrayEnum, AlwaysCooperateEnum, RandomEnum};
        reference_table_ = GetMockReferenceTable();
        competition_ = std::make_unique<FastCompetition>(strategies_, reference_table_, 10);
    }

    std::array<StrategyEnum, 3> strategies_ {};
    ReferenceTable reference_table_{};
    std::unique_ptr<FastCompetition> competition_;
};

TEST_F(FastCompetitionTest, FastCompetitionSimulationWorks) {
    competition_->Simulation();

    const auto &results = competition_->GetResults();

    EXPECT_EQ(results[0], 30);
    EXPECT_EQ(results[1], 5);
    EXPECT_EQ(results[2], 30);
}



class DetailedCompetitionTest : public ::testing::Test {
protected:
    void SetUp() override {
        strategies_ = {AlwaysBetrayEnum, AlwaysCooperateEnum, RandomEnum};
        reference_table_ = GetMockReferenceTable();
        competition_ = std::make_unique<DetailedCompetition>(strategies_, reference_table_);
    }

    std::array<StrategyEnum, 3> strategies_ {};
    ReferenceTable reference_table_ {};
    std::unique_ptr<DetailedCompetition> competition_;
};


TEST_F(DetailedCompetitionTest, DetailedCompetitionSimulationWorks) {
    std::stringstream output;
    std::streambuf* old_cout = std::cout.rdbuf(output.rdbuf());

    std::stringstream input("quit\n");
    std::streambuf* old_cin = std::cin.rdbuf(input.rdbuf());

    competition_->Simulation();

    std::string result = output.str();
    EXPECT_NE(result.find("Раунд"), std::string::npos);
    EXPECT_NE(result.find("cooperated."), std::string::npos);

    std::cout.rdbuf(old_cout);
    std::cin.rdbuf(old_cin);
}


TEST_F(DetailedCompetitionTest, QuitDetailedCompetition) {
    std::istringstream input("quit\n");
    std::streambuf* old_cin = std::cin.rdbuf(input.rdbuf());

    competition_->Simulation();

    std::cin.rdbuf(old_cin);
}
