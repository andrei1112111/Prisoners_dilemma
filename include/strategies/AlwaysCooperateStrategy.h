#pragma once


#include <include/strategies/Strategy.h>


class AlwaysCooperateStrategy final : public Strategy {
public:
    // Cooperate any way
    AlwaysCooperateStrategy();
    ~AlwaysCooperateStrategy() final = default;

    Choice GetMove(const MoveTable &table, const ScoreTable &score_table, int place, int step) final;

    const std::string &GetName() final;

private:
    std::string name = "Always Cooperate";
};
