#ifndef TIME_H
#define TIME_H

#include <chrono>
using namespace std;
using namespace std::chrono;

class Time
{
private:
    std::chrono::high_resolution_clock::time_point start;
    std::chrono::high_resolution_clock::time_point end;

public:
    Time();

    void stop();

    void printDuration(const std::string &label) const;
};

#endif