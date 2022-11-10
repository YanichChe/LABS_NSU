#ifndef TASK2_MATRIX_H
#define TASK2_MATRIX_H

#include <cstdlib>
#include <exception>
#include <vector>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <array>
#include "strategy.h"

const int PLAYERS_NUMBER  = 3;

class NotFoundFileException : public std::invalid_argument
{
public:
    explicit NotFoundFileException(const std::string &fileName);
};

class Matrix
{
public:
    Matrix(){};
    Matrix(std::string fileName);
    std::array<std::array<int, PLAYERS_NUMBER>, 8> GetMatrix();
    std::array<int, PLAYERS_NUMBER> GetRow(std::array<Move, PLAYERS_NUMBER> votes);

private:
    std::array<std::array<int, PLAYERS_NUMBER>, 8> matrix;
};

#endif // TASK2_MATRIX_H
