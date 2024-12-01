#include "Solution.h"

// Created a whole class for a single solution :)
// I think further solutions should just be in their own files
// Naming this class "Solution" should have been the giveaway that this was a bad idea

Solution::Solution(std::string* p_filePath)
	:filePath(p_filePath)
{
	inputReader.open_file(filePath);
}

int count_occurances(std::vector<int> right, int n)
{
	int occurances{ 0 };
	for (auto const num : right)
	{
		if (num == n)
			occurances++;
	}

	return occurances;
}

// this is disgustingly long and I don't like it either
// test line
void Solution::solve_puzzle()
{
	linesFromFile = inputReader.read_lines_from_file();

	for (auto const line : linesFromFile)
	{
		std::string left_number{};
		std::string right_number{};
		bool add_to_left{ true };

		for (int i = 0; i < line.length(); ++i)
		{
			if (line[i] == ' ' && left_number != "")
			{
				left.push_back(std::stoi(left_number)); // we are done with left_number
				left_number = ""; // prevents multiple capture of left_number
				add_to_left = false;
			}
			else if (add_to_left == true)
			{
				left_number.push_back(line[i]);
			}
			else if (add_to_left == false && line[i] != ' ')
			{
				right_number.push_back(line[i]);
			}
		}
		right.push_back(std::stoi(right_number));
		right_number = "";
	}

	// sort vectors ascending
	std::sort(left.begin(), left.end());
	std::sort(right.begin(), right.end());

	int total{ 0 };

	for(int i = 0; i < left.size(); ++i)
	{	
		int distance{ 0 };

		// check which is larger so the distance will always be positive
		if (left[i] > right[i])
		{
			distance = left[i] - right[i];
		}
		else if (left[i] < right[i])
		{
			distance = right[i] - left[i];
		}

		total += distance;
	}

	// display solution 1
	std::cout << total << std::endl;

	total = 0; // reset total

	for (auto num : left)
	{
		int occurances = count_occurances(right, num);
		total += num * occurances;
	}

	// display solution 2
	std::cout << total << std::endl;

	//inputReader.display_all_lines(linesFromFile); // make sure input is correct
}

Solution::~Solution()
{

}