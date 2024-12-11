#include <include/strategies/UltimateRandomStrategy.h>
#include <include/strategies/StrategyFactory.h>


UltimateRandomStrategy::UltimateRandomStrategy() = default;


Choice UltimateRandomStrategy::GetMove(const MoveTable &table, const ScoreTable &score_table, int place, int step) {
    auto strategy = StrategyFactory::factory(static_cast<StrategyEnum>(rand() % (UltimateRandomEnum - 1)));
    return strategy->GetMove(table, score_table, place, step);
}


const std::string &UltimateRandomStrategy::GetName() {
    return name;
}
