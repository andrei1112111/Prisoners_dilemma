#pragma once


#include <array>
#include <iostream>

#include <include/competitions/Competition.h>

#include <include/strategies/Strategy.h>
#include <include/strategies/StrategyFactory.h>


class FastCompetition final : public Competition {
public:
    FastCompetition(const std::array<StrategyEnum, 3> &strategies, ReferenceTable reference_table, int steps);
    ~FastCompetition() final = default;

    void Simulation() final;

    const std::array<int, 3> &GetResults();

private:
    std::array<std::unique_ptr<Strategy>, 3> strategies;
    ReferenceTable reference_table;
    int steps;

    MoveTable move_table;
    ScoreTable score_table;

};
