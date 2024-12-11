cmake_minimum_required(VERSION 3.29)
project(Prisoners_dilemma)


set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#add_compile_options(-Wall -Wextra -pedantic -Werror)

include_directories(./)

enable_testing()


# ========================


set(STRATEGIES_SOURCE_FILES
        src/strategies/AlwaysBetrayStrategy.cpp
        src/strategies/AlwaysCooperateStrategy.cpp
        src/strategies/EnviousMercifulStrategy.cpp
        src/strategies/EnviousStrategy.cpp
        src/strategies/RandomStrategy.cpp
        src/strategies/RevengefulMercifulStrategy.cpp
        src/strategies/RevengefulStrategy.cpp
        src/strategies/StrategyFactory.cpp
        src/strategies/UltimateRandomStrategy.cpp
)

set(COMPETITIONS_SOURCE_FILES
        src/competitions/DetailedCompetition.cpp
        src/competitions/FastCompetition.cpp
        src/competitions/TournamentCompetition.cpp
)

set(PARSER_SOURCE_FILES
        src/parser/Parser.cpp
)

add_library(Strategies STATIC ${STRATEGIES_SOURCE_FILES})
target_include_directories(Strategies PRIVATE include/strategies src/strategies)
set_target_properties(Strategies PROPERTIES LINKER_LANGUAGE CXX)

add_library(Competitions STATIC ${COMPETITIONS_SOURCE_FILES})
target_include_directories(Competitions PRIVATE include/competitions src/competitions)
set_target_properties(Competitions PROPERTIES LINKER_LANGUAGE CXX)

add_library(Parser STATIC ${PARSER_SOURCE_FILES})
target_include_directories(Parser PRIVATE include/competitions src/competitions)
set_target_properties(Parser PROPERTIES LINKER_LANGUAGE CXX)


target_link_libraries(Competitions Strategies)


# ========================


add_subdirectory(test)

add_executable(Prisoners_dilemma main.cpp)

target_link_libraries(Prisoners_dilemma PRIVATE Strategies)
target_link_libraries(Prisoners_dilemma PRIVATE Competitions)
target_link_libraries(Prisoners_dilemma PRIVATE Parser)
