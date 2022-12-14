#include "detailed.h"

DetailedMode::DetailedMode(gameData::GameData *gameData) : Mode(gameData) {}

void DetailedMode::printCurrentSums(const std::array<strategy::Move, matrix::PLAYERS_NUMBER> results)
{
    std::array<int, matrix::PLAYERS_NUMBER> pointsArray = *matrix.getRow(results);

    std::cout << std::setw(20) << std::left << "NAME"
              << std::setw(20) << std::left << "CHOICE"
              << std::setw(20) << std::left << "POINTS"
              << std::setw(20) << std::left << "TOTAL SUM" << std::endl;

    for (int i = 0; i < matrix::PLAYERS_NUMBER; i++)
    {
        std::cout << std::setw(20) << std::left << strategyNames[i]
                  << std::setw(20) << std::left << static_cast<strategy::Move>(strategy::Move(results[i]))
                  << std::setw(20) << std::left << pointsArray[i]
                  << std::setw(20) << std::left << totalSums[i] << std::endl;
    }
}

std::array<int, matrix::PLAYERS_NUMBER> DetailedMode::start()
{
    while (true)
    {
        std::string input;
        std::cin >> input;

        if (input == QUIT)
        {
            break;
        }
        else if (input == STEP)
        {
            std::array<strategy::Move, matrix::PLAYERS_NUMBER> results = getVotes();
            updateStrategies(results);
            updateTotalSums(results);

            printCurrentSums(results);
        }
    }
}