#pragma once


#include <include/strategies/Strategy.h>


class AlwaysBetrayStrategy final : public Strategy {
    // Betray any way
public:
    AlwaysBetrayStrategy();
    ~AlwaysBetrayStrategy() final = default;

    Choice GetMove(const MoveTable &table, const ScoreTable &score_table, int place, int step) final;

    const std::string &GetName() final;

private:
    std::string name = "Always Betray";
};
