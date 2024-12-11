#pragma once


#include <include/strategies/Strategy.h>


class EnviousStrategy final : public Strategy{
    // Betrays if at the previous step at least one strategy has more points
public:
    EnviousStrategy();
    ~EnviousStrategy() final = default;

    Choice GetMove(const MoveTable &table, const ScoreTable &score_table, int place, int step) final;

    const std::string &GetName() final;

private:
    std::string name = "Envious";
};
