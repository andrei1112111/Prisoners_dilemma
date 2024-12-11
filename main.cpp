#include <iostream>

#include <include/strategies/StrategyFactory.h>

#include <include/competitions/Competition.h>
#include <include/competitions/DetailedCompetition.h>
#include <include/competitions/FastCompetition.h>
#include <include/competitions/TournamentCompetition.h>

#include <include/parser/Parser.h>


int main(const int argc, const char *argv[]) {
    if (argc < 3) {
        std::cerr << "Not enough arguments!" << std::endl;
        return 1;
    }

    std::vector<std::string> arguments;

    std::vector<StrategyEnum> strategies_vec;

    CompetitionEnum mode;

    ReferenceTable matrix;

    std::unique_ptr<Competition> competition;

    int steps;

    for (int i = 1; i < argc; ++i) {
        arguments.emplace_back(argv[i]);
    }

    try {
        strategies_vec = Parsers::ParseStrategies(arguments);
        mode = Parsers::ParseCompetition(arguments);
        steps = Parsers::ParseSteps(arguments);
        matrix = Parsers::ParseMatrix(arguments);
    }
    catch (std::exception &exc) {
        std::cerr << "Failed to parse arguments: " << exc.what() << std::endl;
        return -1;
    }

    std::array<StrategyEnum, 3> strategies_arr{strategies_vec[0], strategies_vec[1], strategies_vec[2]};

    switch (mode) {
        case Detailed:
            DetailedCompetition(strategies_arr, matrix).Simulation();
            break;

        case Fast:
            FastCompetition(strategies_arr, matrix, steps).Simulation();
            break;

        case Tournament:
            TournamentCompetition(strategies_vec, matrix, steps).Simulation();
            break;
    }

    return 0;
}
