#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#include <iomanip>
using namespace std;

vector <vector<char>> arr;
string result_B;

void B( int row_start, int row_end, int col_start, int col_end) { //B���� D ���� �� �� �� �� ����, D��� ���� ���� ����
   //�Ű�����, �迭, ������ ���� ��, �� ��, ������ ���� ��, �� ��
	if (row_start == row_end || col_start == col_end)
		return;

	int count_one = 0;
	for (int row_tmp = row_start; row_tmp < row_end; row_tmp++) {
		for (int col_tmp = col_start; col_tmp < col_end; col_tmp++) {
			if (arr[row_tmp][col_tmp] == '1') {
				count_one++;
			}
		}
	}

	if (count_one == (row_end - row_start) * (col_end - col_start)) { //ī��Ʈ�� ������ ĭ�� ������ �����ϸ� cout 1
		cout << "1";
	}
	else if (count_one == 0) { //ī��Ʈ�� ������ 0���� 0���
		cout << "0";
	}
	else {
		printf("D");
		int new_rend, new_cend;
		if (row_end % 2 == 0)//¦��
			new_rend = row_end / 2;
		else
			new_rend = (row_end / 2) + 1;

		if (col_end % 2 == 0)
			new_cend = col_end / 2;
		else
			new_cend = (col_end / 2) + 1;

		//cout << new_rend << " " << new_cend;
		B(row_start, new_rend, col_start, new_cend); //1��
		B(new_rend, row_end, col_start, new_cend); //2
		B(new_rend, row_end, new_cend, col_end); //4
		B(row_start, new_rend, new_cend, col_end); //3 
		
		
	}

}

int main() {
	freopen("0.inp", "r", stdin);
	freopen("bitmap.out", "w", stdout);

	char bit;
	while (true) {
		cin >> bit;
		if (bit == '#')
			break;
		cin.ignore();
		int a, b;
		cin >> a >> b;
	
		if (bit == 'B') {
			cout << "B" << " " << a << " "<<b << "\n";
			string l;
			arr.resize(a, vector<char>(b));
			while (l.size() < a * b) {
				string tmp;
				getline(cin, tmp);
				l += tmp;
			}
			for (int i = 0; i < a; i++) {
				for (int j = 0; j < b; j++) {
					arr[i][j] = l[i * b + j];
				}
			}
			B(0, a, 0, b);
		}

	}

}