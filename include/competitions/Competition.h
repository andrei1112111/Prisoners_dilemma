#pragma once


enum CompetitionEnum {
    Tournament,
    Detailed,
    Fast
};


class Competition {
public:
    virtual ~Competition() = default;
    virtual void Simulation() = 0;

};
