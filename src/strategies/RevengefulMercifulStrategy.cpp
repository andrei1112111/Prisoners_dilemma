#include <include/strategies/RevengefulMercifulStrategy.h>


RevengefulMercifulStrategy::RevengefulMercifulStrategy() = default;


Choice RevengefulMercifulStrategy::GetMove(const MoveTable &table, const ScoreTable &score_table, int place, int step) {
    if (step == 0) {
        return Cooperate;
    }

    switch (place) {
        case 0:
            if (table[step - 1][1] == Betray && table[step - 1][2] == Betray) {
                return Betray;
            } else {
                return Cooperate;
            }

        case 1:
            if (table[step - 1][0] == Betray && table[step - 1][2] == Betray) {
                return Betray;
            } else {
                return Cooperate;
            }

        case 2:
            if (table[step - 1][0] == Betray && table[step - 1][1] == Betray) {
                return Betray;
            } else {
                return Cooperate;
            }

        default:
            return Betray;
    }
}


const std::string &RevengefulMercifulStrategy::GetName() {
    return name;
}
