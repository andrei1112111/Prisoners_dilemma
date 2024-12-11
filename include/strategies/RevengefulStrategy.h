#pragma once


#include <include/strategies/Strategy.h>


class RevengefulStrategy final : public Strategy{
    // Betrays if at least one strategy betrayed at the previous step
public:
    RevengefulStrategy();
    ~RevengefulStrategy() final = default;

    Choice GetMove(const MoveTable &table, const ScoreTable &score_table, int place, int step) final;

    const std::string &GetName() final;

private:
    std::string name = "Revengeful";
};
