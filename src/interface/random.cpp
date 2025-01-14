#include "random.hpp"

#if defined(__linux__) || defined(_WIN32) || defined(_WIN64) || defined(__APPLE__)

#include <cstdint>
#include <cstdlib>

int16_t random(const int16_t start, const int16_t end)
{
    return (rand() % (end - start));
}

#endif /* #if defined(__linux__) || defined(_WIN32) || defined(_WIN64) || defined(__APPLE__) */