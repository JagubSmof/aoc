// AdventOfCode.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <string>
#include "File.h"
#include "Solution.h"

int day01_solution()
{
    std::string filePath{ "../input.txt" };
    Solution solve{ &filePath };
    solve.solve_puzzle();
    return 0;
}
