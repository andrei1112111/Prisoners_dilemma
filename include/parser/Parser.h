#pragma once


#include <vector>
#include <unordered_map>
#include <string>
#include <stdexcept>
#include <fstream>

#include <include/strategies/StrategyFactory.h>
#include <include/competitions/Competition.h>


const std::unordered_map<std::string, CompetitionEnum> MODE{
        {"--mode=detailed",   Detailed},
        {"--mode=fast",       Fast},
        {"--mode=tournament", Tournament}
};

const std::unordered_map<std::string, StrategyEnum> STRATEGIES{
        {"AlwaysBetray",       AlwaysBetrayEnum},
        {"AlwaysCooperate",    AlwaysCooperateEnum},
        {"Random",             RandomEnum},
        {"Envious",            EnviousEnum},
        {"EnviousMerciful",    EnviousMercifulEnum},
        {"Revengeful",         RevengefulEnum},
        {"RevengefulMerciful", RevengefulMercifulEnum},
        {"UltimateRandom",     UltimateRandomEnum}
};

class Parsers {
public:
    const static std::unordered_map<std::string, StrategyEnum> StrategyParser;

    const static std::unordered_map<std::string, CompetitionEnum> ModeParser;

    static std::vector<StrategyEnum> ParseStrategies(const std::vector<std::string> &arguments);

    static CompetitionEnum ParseCompetition(const std::vector<std::string> &arguments);

    static int ParseSteps(const std::vector<std::string> &arguments);

    static ReferenceTable ParseMatrix(const std::vector<std::string> &arguments);
};
