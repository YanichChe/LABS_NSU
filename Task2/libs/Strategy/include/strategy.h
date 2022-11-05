#ifndef STRATEGY_H
#define STRATEGY_H

#include <stdlib.h>
#include <vector>
#include <string>
#include <array>
#include <vector>

enum Move
{
    D = 1,
    C = 0
};

class Strategy
{
public:
    virtual ~Strategy() = default;
    virtual Move Algoritm() = 0;
    virtual void UpdateStrategyData(std::array<Move, 2> results){};
};

#endif
