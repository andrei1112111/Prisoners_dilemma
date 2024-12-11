#include <include/strategies/EnviousStrategy.h>


EnviousStrategy::EnviousStrategy() = default;


Choice EnviousStrategy::GetMove(const MoveTable &table, const ScoreTable &score_table, int place, int step) {
    if (step == 0) {
        return Betray;
    }

    switch (place) {
        case 0:
            if (score_table[step - 1][1] > score_table[step - 1][0] || score_table[step - 1][2] > score_table[step - 1][0]) {
                return Betray;
            } else {
                return Cooperate;
            }
        case 1:
            if (score_table[step - 1][0] > score_table[step - 1][1] || score_table[step - 1][2] > score_table[step - 1][1]) {
                return Betray;
            } else {
                return Cooperate;
            }
        case 2:
            if (score_table[step - 1][0] > score_table[step - 1][2] || score_table[step - 1][1] > score_table[step - 1][2]) {
                return Betray;
            } else {
                return Cooperate;
            }
        default:
            return Betray;
    }
}


const std::string &EnviousStrategy::GetName() {
    return name;
}
