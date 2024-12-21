#pragma once


#include <include/competitions/Competition.h>

#include <include/strategies/StrategyFactory.h>


class DetailedCompetition final : public Competition {
public:
    DetailedCompetition(const std::array<StrategyEnum, 3> &strategies, const ReferenceTable &reference_table);

    ~DetailedCompetition() final = default;

    void Simulation() final;

private:
    std::array<std::unique_ptr<Strategy>, 3> strategies_;
    ReferenceTable reference_table_;

    MoveTable move_table_;
    ScoreTable score_table_;

};
