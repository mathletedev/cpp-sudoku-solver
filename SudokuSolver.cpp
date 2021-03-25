#include <bits/stdc++.h>
using namespace std;

tuple<int, int> findEmpty(int grid[9][9]) {
	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j) {
			if (grid[i][j] == 0) {
				return make_tuple(i, j);
			}
		}
	}

	return make_tuple(-1, -1);
}

bool checkValid(int grid[9][9], int i, int j, int val) {
	for (int k = 0; k < 9; ++k) {
		if (grid[i][k] == val || grid[k][j] == val) {
			return false;
		}
	}

	int boxI = 3 * floor(i / 3), boxJ = 3 * floor(j / 3);
	for (int n = boxI; n < boxI + 3; ++n) {
		for (int m = boxJ; m < boxJ + 3; ++m) {
			if (grid[n][m] == val) {
				return false;
			}
		}
	}

	return true;
}

void printGrid(int grid[9][9]) {
	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j) {
			cout << grid[i][j] << " ";
		}
		cout << endl;
	}
}

bool solveSudoku(int grid[9][9]) {
	int i, j;
	tie(i, j) = findEmpty(grid);

	if (i == -1) {
		printGrid(grid);
		return true;
	}

	for (int k = 1; k <= 9; ++k) {
		if (checkValid(grid, i, j, k)) {
			grid[i][j] = k;
			if (solveSudoku(grid)) {
				return true;
			}
			grid[i][j] = 0;
		}
	}

	return false;
}


int main() {
	int grid[9][9];

	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j) {
			cin >> grid[i][j];
		}
	}
	
	cout << endl;
	solveSudoku(grid);
}
