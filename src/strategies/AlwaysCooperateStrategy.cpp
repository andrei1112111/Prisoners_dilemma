#include "include/strategies/AlwaysCooperateStrategy.h"


AlwaysCooperateStrategy::AlwaysCooperateStrategy() = default;


Choice AlwaysCooperateStrategy::GetMove(const MoveTable &table, const ScoreTable &score_table, int place, int step) {
    return Cooperate;
}


const std::string &AlwaysCooperateStrategy::GetName() {
    return name;
}
