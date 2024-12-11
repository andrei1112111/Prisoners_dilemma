#pragma once


#include <include/strategies/Strategy.h>


class RevengefulMercifulStrategy final : public Strategy{
    // Betrays if both strategies betrayed at the previous step
public:
    RevengefulMercifulStrategy();
    ~RevengefulMercifulStrategy() final = default;

    Choice GetMove(const MoveTable &table, const ScoreTable &score_table, int place, int step) final;

    const std::string &GetName() final;

private:
    std::string name = "Revengeful Merciful";
};
