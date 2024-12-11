#pragma once


#include <include/strategies/Strategy.h>


class RandomStrategy final : public Strategy {
    // Betray or Cooperate by random
public:
    RandomStrategy();
    ~RandomStrategy() final = default;

    Choice GetMove(const MoveTable &table, const ScoreTable &score_table, int place, int step) final;

    const std::string &GetName() final;

private:
    std::string name = "Random";
};
