#include <include/strategies/AlwaysBetrayStrategy.h>


AlwaysBetrayStrategy::AlwaysBetrayStrategy() = default;


Choice AlwaysBetrayStrategy::GetMove(const MoveTable &table, const ScoreTable &score_table, int place, int step) {
    return Betray;
}


const std::string &AlwaysBetrayStrategy::GetName() {
    return name;
}
