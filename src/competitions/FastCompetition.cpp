#include <include/competitions/FastCompetition.h>


FastCompetition::FastCompetition(const std::array<StrategyEnum, 3> &strategies, ReferenceTable reference_table,
                                 int steps) :
        strategies(
                {
                        StrategyFactory::factory(strategies[0]),
                        StrategyFactory::factory(strategies[1]),
                        StrategyFactory::factory(strategies[2])
                }
        ),
        reference_table(reference_table),
        steps(steps) {}

void FastCompetition::Simulation() {
    for (int step = 0; step < steps; ++step) {
        move_table.push_back(
                {
                        strategies[0]->GetMove(move_table, score_table, 0, step),
                        strategies[1]->GetMove(move_table, score_table, 1, step),
                        strategies[2]->GetMove(move_table, score_table, 2, step)
                }
        );
        const std::array<int, 3> &cur_step_results(
                reference_table
                [move_table[step][0]]
                [move_table[step][1]]
                [move_table[step][2]]
        );
        if (step == 0) {
            score_table.push_back(cur_step_results);
        } else {
            score_table.push_back(
                    {
                            score_table[step - 1][0] + cur_step_results[0],
                            score_table[step - 1][1] + cur_step_results[1],
                            score_table[step - 1][2] + cur_step_results[2]
                    }
            );
        }
    }
    for (int i = 0; i < 3; ++i)
        std::cout << "Strategy " << strategies[i]->GetName()
                  << " get " << score_table[steps - 1][i] << " points." << std::endl;

    std::cout << std::endl;
}

const std::array<int, 3> &FastCompetition::GetResults() {
    return score_table[steps - 1];
}
