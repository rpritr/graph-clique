#include "time.h"
#include <iostream>
using namespace std;

Time::Time()
{
    start = std::chrono::high_resolution_clock::now();
}

void Time::stop()
{
    end = std::chrono::high_resolution_clock::now();
}

void Time::printDuration(const std::string &label = "Trajanje") const
{
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    std::cout << label << ": " << duration << " ms" << std::endl;
}