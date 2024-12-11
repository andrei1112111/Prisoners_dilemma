#pragma once


#include <memory>

#include <include/strategies/Strategy.h>

#include <include/strategies/AlwaysBetrayStrategy.h>
#include <include/strategies/AlwaysCooperateStrategy.h>
#include <include/strategies/RandomStrategy.h>
#include <include/strategies/EnviousStrategy.h>
#include <include/strategies/EnviousMercifulStrategy.h>
#include <include/strategies/RevengefulStrategy.h>
#include <include/strategies/RevengefulMercifulStrategy.h>
#include <include/strategies/UltimateRandomStrategy.h>


enum StrategyEnum {
    AlwaysBetrayEnum,
    AlwaysCooperateEnum,
    RandomEnum,
    EnviousEnum,
    EnviousMercifulEnum,
    RevengefulEnum,
    RevengefulMercifulEnum,
    UltimateRandomEnum
};


class StrategyFactory {
public:
    static std::unique_ptr<Strategy> factory(StrategyEnum strategy);
};
