#ifndef TASK3_CONVERTER_H
#define TASK3_CONVERTER_H

#include <cstdlib>
#include <vector>
#include <array>
#include <stdexcept>
#include "wav.h"

namespace converter {

    class WrongTime: public std::invalid_argument{
    public:
        WrongTime(const int time) : std::invalid_argument(std::to_string(time)+ " is wrong time format"){};
    };

    class Converter {
    public:
        virtual ~Converter() = default;

        virtual void convert(std::vector<wav::SampleBuffer> &current_samples,
                             const std::vector<wav::SampleVector> original_samples) = 0;
    };
}
#endif //TASK3_CONVERTER_H
