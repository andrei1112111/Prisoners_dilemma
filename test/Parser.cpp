#include <gtest/gtest.h>

#include <stdexcept>
#include <fstream>
#include <sstream>

#include <include/parser/Parser.h>


class ParserTest : public ::testing::Test {
protected:
    std::vector<std::string> arguments;
};

TEST_F(ParserTest, ParseValidStrategies) {
    arguments = {"AlwaysBetray", "Random", "Envious"};

    std::vector<StrategyEnum> strategies = Parsers::ParseStrategies(arguments);

    EXPECT_EQ(strategies.size(), 3);
    EXPECT_EQ(strategies[0], AlwaysBetrayEnum);
    EXPECT_EQ(strategies[1], RandomEnum);
    EXPECT_EQ(strategies[2], EnviousEnum);
}

TEST_F(ParserTest, ParseStrategiesNotEnoughStrategies) {
    arguments = {"AlwaysBetray", "Random"};

    EXPECT_THROW(Parsers::ParseStrategies(arguments), std::runtime_error);
}

TEST_F(ParserTest, ParseInvalidStrategy) {
    arguments = {"AlwaysBetray", "InvalidStrategy", "Random"};

    ASSERT_THROW(Parsers::ParseStrategies(arguments), std::runtime_error);

    arguments = {"AlwaysBetray", "InvalidStrategy", "Random", "AlwaysBetray"};

    std::vector<StrategyEnum> strategies = Parsers::ParseStrategies(arguments);

    EXPECT_EQ(strategies.size(), 3);
    EXPECT_EQ(strategies[0], AlwaysBetrayEnum);
    EXPECT_EQ(strategies[1], RandomEnum);
    EXPECT_EQ(strategies[2], AlwaysBetrayEnum);
}

TEST_F(ParserTest, ParseCompetitionDetailed) {
    arguments = {"--mode=detailed"};

    CompetitionEnum competition = Parsers::ParseCompetition(arguments);

    EXPECT_EQ(competition, Detailed);
}

TEST_F(ParserTest, ParseCompetitionFast) {
    arguments = {"--mode=fast"};

    CompetitionEnum competition = Parsers::ParseCompetition(arguments);

    EXPECT_EQ(competition, Fast);
}

TEST_F(ParserTest, ParseCompetitionTournament) {
    arguments = {"--mode=tournament"};

    CompetitionEnum competition = Parsers::ParseCompetition(arguments);

    EXPECT_EQ(competition, Tournament);
}

TEST_F(ParserTest, ParseCompetitionDefault) {
    arguments = {"--mode=invalid"};

    CompetitionEnum competition = Parsers::ParseCompetition(arguments);

    EXPECT_EQ(competition, Detailed);
}

TEST_F(ParserTest, ParseStepsValid) {
    arguments = {"--steps=50"};

    int steps = Parsers::ParseSteps(arguments);

    EXPECT_EQ(steps, 50);
}

TEST_F(ParserTest, ParseStepsDefault) {
    arguments = {"--mode=detailed"};

    int steps = Parsers::ParseSteps(arguments);

    EXPECT_EQ(steps, 10);
}

TEST_F(ParserTest, ParseStepsInvalid) {
    arguments = {"--steps=invalid"};

    EXPECT_EQ(Parsers::ParseSteps(arguments), 10);
}

TEST_F(ParserTest, ParseMatrixValid) {
    std::ofstream matrixFile("test_matrix.txt");
    matrixFile << "3 0 3\n0 3 1\n3 1 0\n3 0 3\n0 3 1\n3 1 0\n3 0 3\n0 3 1\n";  // Example 8x3 matrix
    matrixFile.close();

    arguments = {"--matrix=test_matrix.txt"};

    ReferenceTable matrix = Parsers::ParseMatrix(arguments);

    EXPECT_EQ(matrix[Cooperate][Cooperate][Cooperate][0], 3);
    EXPECT_EQ(matrix[Betray][Cooperate][Cooperate][1], 0);

    std::remove("test_matrix.txt");
}

TEST_F(ParserTest, ParseMatrixFileNotFound) {
    arguments = {"--matrix=non_existent_file.txt"};

    EXPECT_THROW(Parsers::ParseMatrix(arguments), std::runtime_error);
}

TEST_F(ParserTest, ParseMatrixInvalidFormat) {
    std::ofstream matrixFile("invalid_matrix.txt");
    matrixFile << "3 0 3\n0 3\n";  // Invalid matrix (too few elements)
    matrixFile.close();

    arguments = {"--matrix=invalid_matrix.txt"};

    EXPECT_THROW(Parsers::ParseMatrix(arguments), std::runtime_error);

    std::remove("invalid_matrix.txt");
}
