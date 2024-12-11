#pragma once


#include <include/strategies/Strategy.h>


class EnviousMercifulStrategy final : public Strategy{
public:
    // Betray any way
    EnviousMercifulStrategy();
    ~EnviousMercifulStrategy() final = default;

    Choice GetMove(const MoveTable &table, const ScoreTable &score_table, int place, int step) final;

    const std::string &GetName() final;

private:
    std::string name = "Envious Merciful";
};
