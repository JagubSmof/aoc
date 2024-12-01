#pragma once
#include <string>
#include <vector>
#include <algorithm>
#include "File.h"

class Solution
{
public:
	Solution(std::string* p_filePath);
	void solve_puzzle();
	~Solution();

private:
	File inputReader;
	std::string* filePath;
	std::vector<std::string> linesFromFile;
	std::vector<int> left;
	std::vector<int> right;
};

