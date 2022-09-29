#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;
void check_path(int row, int col, vector<vector<int>> &grid) { //-1을 채우기 
	for (int i = 0; i < row; i++) {
		if (grid[i][0] == -1) {
			for (int j = i; j < row; j++)
				grid[j][0] = -1;
			break;
		}
	}
	for (int i = 0; i < col; i++) {
		if (grid[0][i] == -1) {
			for (int j = i; j < col; j++)
				grid[0][j] = -1;
			break;
		}
	}
	for (int i = 1; i < row;i++) {
		for (int j = 1; j < col;j++) {
			if (grid[i - 1][j] == -1 && grid[i][j - 1] == -1 && grid[i][j] != -1) grid[i][j] = -1;
		}
	}
}
void find_min(int row, int col, vector<vector<int>>& grid,vector<vector<int>>& path) { //최소값찾기 함수
	path[0][0] = grid[0][0]; //제일 첫 항은 원래 값의 0,0
	for (int i = 1; i < row; i++) { //j=0일 때,
		if (grid[i][0] != -1)  path[i][0] = grid[i][0] + path[i - 1][0];
	}
	for (int i = 1; i < col; i++) { //i =0일때
		if (grid[0][i] != -1)  path[0][i] = grid[0][i] + path[0][i-1];
	}
	for (int i = 1; i < row; i++) {
		for (int j = 1; j < col; j++) {
			if (grid[i][j] != -1) {
				if (grid[i - 1][j] == -1 || grid[i][j - 1] == -1) {
					if (grid[i - 1][j] == -1) path[i][j] = path[i][j - 1] + grid[i][j];
					else if (grid[i][j - 1] == -1)  path[i][j] = path[i - 1][j] + grid[i][j];
				}
				else  path[i][j] = min(path[i - 1][j], path[i][j - 1]) + grid[i][j];
			}
		}
	}
}
void find_path(int row, int col, vector<vector<int>>& path, vector<vector<int>>& result, vector<vector<int>>& grid) {
	result[row - 1][col - 1] = 1;
	for (int i = row - 1; i >= 0; i--) {
		for (int j = col-1; j >= 0; j--) {
			if (result[i][j] == 1) {
				if (i != 0 && j != 0) {//첫번째 경우 i와 j가 모두 0이 아닌 경우
					if (path[i - 1][j] == path[i][j - 1]) result[i - 1][j] = 1;
					else {
						if (path[i][j] - grid[i][j] == path[i - 1][j]) result[i - 1][j] = 1;
						else if (path[i][j] - grid[i][j] == path[i][j - 1]) result[i][j - 1] = 1;
					}
				}
				else if (i != 0 && j == 0) result[i - 1][j] = 1;
				else if (i == 0 && j != 0) result[i][j - 1] = 1;
				if (i == 0 && j == 0) result[i][j] = 1;
			}
		}
	}
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (result[i][j] == 1)
				cout << "(" << i << " " << j << ")\n";
		}
	}
}
int main() {
	freopen("gridpath.inp", "r", stdin);
	freopen("gridpath.out", "w", stdout);
	int row, col;
	cin >> row >> col;
	vector<vector<int>>grid(row,vector<int>(col,0)); vector<int> grid1;	grid.push_back(grid1); //경로가 있는지 없는지 체크
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++)
			cin >> grid[i][j];
	}	
	check_path(row, col, grid);
	if (grid[row - 1][col - 1] == -1) cout << "No path.";
	else {
		vector<vector<int>>path(row, vector<int>(col, 0));    vector<int> path1;
		vector<vector<int>>result(row, vector<int>(col, 0));  vector<int> result1;
		path.push_back(path1);  result.push_back(result1);
		find_min(row, col, grid, path);
		cout << path[row - 1][col - 1] << endl;
		find_path(row, col, path, result,grid);	
	}	
}