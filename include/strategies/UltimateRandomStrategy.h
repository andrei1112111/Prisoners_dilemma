#pragma once


#include "include/strategies/Strategy.h"


class UltimateRandomStrategy final : public Strategy {
public:
    // Emulates a random strategy
    UltimateRandomStrategy();
    ~UltimateRandomStrategy() final = default;

    Choice GetMove(const MoveTable &table, const ScoreTable &score_table, int place, int step) final;

    const std::string &GetName() final;

private:
    std::string name = "Ultimate Random";
};
