#include <include/parser/Parser.h>

#include <stdexcept>
#include <iostream>


std::vector<StrategyEnum> Parsers::ParseStrategies(const std::vector<std::string> &arguments) {
    std::vector<StrategyEnum> result;

    for (const auto & argument : arguments) {
        if (STRATEGIES.find(argument) != STRATEGIES.end()) {
            result.push_back(STRATEGIES.at(argument));
        }
    }

    if (result.size() < 3) {
        throw std::runtime_error("Not enough strategies");
    }

    return result;
}


CompetitionEnum Parsers::ParseCompetition(const std::vector<std::string> &arguments) {
    for (const auto & argument : arguments)
        if (MODE.find(argument) != MODE.end()) {
            return MODE.at(argument);
        }

    std::cerr << "Failed to find competition. Set default competition = Detailed" << std::endl;
    return Detailed; // default
}


int Parsers::ParseSteps(const std::vector<std::string> &arguments) {
    for (const auto & argument : arguments) {
        if (argument.starts_with("--steps=")) {
            try {

                return std::stoi(argument.substr(8));
            } catch (std::invalid_argument const& ex) {
                std::cerr << "Invalid steps format. Set default value = 10" << std::endl;

                return 10; // default
            }
        }
    }
    std::cerr << "Failed to find steps. Set default value = 10" << std::endl;

    return 10; // default
}


ReferenceTable Parsers::ParseMatrix(const std::vector<std::string> &arguments) {
    for (const auto & argument : arguments) {
        if (argument.starts_with("--matrix=")) {

            std::ifstream input_stream(argument.substr(9));
            input_stream.exceptions(std::ifstream::failbit | std::ifstream::badbit);

            ReferenceTable matrix;

            try {
                if (!input_stream) {
                    throw std::runtime_error("Matrix file not found");
                }

                std::array<std::array<int, 3>, 8> raw_matrix{};
                for (int y = 0; y < 8; ++y) {
                    for (int x = 0; x < 3; ++x) {
                        if (!(input_stream >> raw_matrix[y][x])) {
                            throw std::runtime_error("Wrong matrix file format");
                        }
                    }
                }

                matrix[Cooperate][Cooperate][Cooperate] = raw_matrix[0];
                matrix[Cooperate][Cooperate][Betray] = raw_matrix[1];
                matrix[Cooperate][Betray][Cooperate] = raw_matrix[2];
                matrix[Betray][Cooperate][Cooperate] = raw_matrix[3];
                matrix[Cooperate][Betray][Betray] = raw_matrix[4];
                matrix[Betray][Cooperate][Betray] = raw_matrix[5];
                matrix[Betray][Betray][Cooperate] = raw_matrix[6];
                matrix[Betray][Betray][Betray] = raw_matrix[7];

                return matrix;

            } catch (const std::ios_base::failure& e) {
                throw std::runtime_error("Failed to read file");
            }
        }
    }

    // default
    ReferenceTable scores;
    scores[Cooperate][Cooperate][Cooperate] = {7, 7, 7};
    scores[Cooperate][Cooperate][Betray] = {3, 3, 9};
    scores[Cooperate][Betray][Cooperate] = {3, 9, 3};
    scores[Betray][Cooperate][Cooperate] = {9, 3, 3};
    scores[Cooperate][Betray][Betray] = {0, 5, 5};
    scores[Betray][Cooperate][Betray] = {5, 0, 5};
    scores[Betray][Betray][Cooperate] = {5, 5, 0};
    scores[Betray][Betray][Betray] = {1, 1, 1};

    return scores;
}
