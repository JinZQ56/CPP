#include <iostream>
#include <fstream>
#include <algorithm>
#include <chrono>
#include <vector>
#include <map>
#include <string>
#include <cstring>
#include <utility>

// initialize solution number
int ans = 0;

// initialize sudoku vectors
// std::vector<std::vector<int>> sudoku(9, std::vector<int>(9));
std::vector<std::pair<int, std::pair<int, int>>> spaces;

// initialize the flag arrays
bool row[9][9];
bool col[9][9];
bool block[3][3][9];
bool valid = false;

void print_sudoku(std::vector<std::vector<int>> sudoku)
{
	// print sudoku
	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			std::cout << sudoku[i][j] << ' ';
			// std::cout << s[i][j] << ' ';
		}
		std::cout << std::endl;
	}
}

void read_sudoku(std::vector<std::vector<int>>& sudoku, std::string& txt)
{
	std::string path = "..\\sudoku_data\\" + txt;
	// std::vector<std::vector<int>> sudoku(9, std::vector<int>(9));
	// int s[9][9];

	// open file
	std::ifstream file(path);

	//read sudoku
	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			file >> sudoku[i][j];
			// file >> s[i][j];
		}
	}

	// close file
	file.close();

	// print sudoku
	// print_sudoku(sudoku);
}

bool cmp(std::pair<int, std::pair<int, int>>& p1, std::pair<int, std::pair<int, int>>& p2)
{
	return (p1.first < p2.first);
}

void set_spaces(std::vector<std::vector<int>>& sudoku)
{
	spaces.clear();
	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			if (sudoku[i][j] == 0)
			{
				int num = 0;
				for (int digit = 0; digit < 9; ++digit)
				{
					if (!row[i][digit] && !col[j][digit] && !block[i / 3][j / 3][digit])
					{
						++num;
					}
				}
				std::pair<int, int> p(i, j);
				spaces.emplace_back(num, p);
			}
		}
	}
	std::sort(spaces.begin(), spaces.end(), cmp);
}

void dfs(std::vector<std::vector<int>>& sudoku, int pos)
{
	if (pos == spaces.size())
	{
		//valid = true;
		ans = ans + 1;
		return;
	}

	auto p = spaces[pos];
	int i = p.second.first;
	int j = p.second.second;

	// for (int digit = 0; digit < 9 && !valid ; ++digit)
	for (int digit = 0; digit < 9; ++digit)
	{
		if (!row[i][digit] && !col[j][digit] && !block[i / 3][j / 3][digit])
		{
			row[i][digit] = col[j][digit] = block[i / 3][j / 3][digit] = true;
			sudoku[i][j] = digit + 1;
			dfs(sudoku, pos + 1);
			row[i][digit] = col[j][digit] = block[i / 3][j / 3][digit] = false;
		}
	}
}

void solve_sudoku(std::vector<std::vector<int>>& sudoku)
{
	// set false to flag arrays
	memset(row, false, sizeof(row));
	memset(col, false, sizeof(col));
	memset(block, false, sizeof(block));

	// set falg arrays according to sudoku
	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			if (sudoku[i][j] != 0)
			{
				int index = sudoku[i][j] - 1;
				row[i][index] = col[j][index] = true;
				block[i / 3][j / 3][index] = true;
			}
		}
	}

	// set spaces vector according to sudoku
	set_spaces(sudoku);
	while (spaces[0].first == 1)
	{
		int i = spaces[0].second.first;
		int j = spaces[0].second.second;
		for (int digit = 0; digit < 9; ++digit)
		{
			if (!row[i][digit] && !col[j][digit] && !block[i / 3][j / 3][digit])
			{
				row[i][digit] = col[j][digit] = block[i / 3][j / 3][digit] = true;
				sudoku[i][j] = digit + 1;
			}
		}
		set_spaces(sudoku);
	}

	// backtracking
	dfs(sudoku, 0);
}

int main() {
	/* read file */
	std::string txt = "hard++.txt";
	std::vector<std::vector<int>> sudoku(9, std::vector<int>(9));
	read_sudoku(sudoku, txt);

	/* start */
	std::chrono::time_point<std::chrono::system_clock> server_create_time_ = std::chrono::system_clock::now();

	/* solve problem */
	solve_sudoku(sudoku);
	//print_sudoku(sudoku);

	/* end */
	std::cout << "solution_count = " << ans << std::endl;
	auto current_time = std::chrono::system_clock::now();
	std::chrono::duration<double, std::milli> duration_mili = current_time - server_create_time_;
	std::cout << "PrintDuration : duration_mili duration = " << (long)duration_mili.count() << " ms" << std::endl;

	/* print */
	// print result when there is only one solution
	if (ans == 1)
	{
		std::cout << "the only solution is: " << std::endl;
		print_sudoku(sudoku);
	}

}