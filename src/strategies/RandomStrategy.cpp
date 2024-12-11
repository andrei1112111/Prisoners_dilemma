#include <include/strategies/RandomStrategy.h>


RandomStrategy::RandomStrategy() = default;


Choice RandomStrategy::GetMove(const MoveTable &table, const ScoreTable &score_table, int place, int step) {
    return static_cast<Choice>(rand() % 2);
}


const std::string &RandomStrategy::GetName() {
    return name;
}
