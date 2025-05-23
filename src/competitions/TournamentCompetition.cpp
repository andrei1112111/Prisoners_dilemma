#include <include/strategies/StrategyFactory.h>
#include <include/competitions/TournamentCompetition.h>
#include <include/competitions/FastCompetition.h>

#include <iostream>


TournamentCompetition::TournamentCompetition(std::vector<StrategyEnum> strategies, ReferenceTable reference_table,
                                             int steps)
        :
        strategies_(std::move(strategies)),
        reference_table_(reference_table),
        steps_(steps),
        total_scores_(strategies_.size(), 0) {}

void TournamentCompetition::Simulation() {
    for (int strategy0 = 0; strategy0 < strategies_.size() - 2; ++strategy0) {

        for (int strategy1 = strategy0 + 1; strategy1 < strategies_.size() - 1; ++strategy1) {

            for (int strategy2 = strategy1 + 1; strategy2 < strategies_.size(); ++strategy2) {

                FastCompetition competition(
                        {
                                strategies_[strategy0],
                                strategies_[strategy1],
                                strategies_[strategy2]
                        }, reference_table_, steps_
                );
                competition.Simulation();
                total_scores_[strategy0] += competition.GetResults()[0];
                total_scores_[strategy1] += competition.GetResults()[1];
                total_scores_[strategy2] += competition.GetResults()[2];
            }
        }
    }
    std::cin.get();
}
