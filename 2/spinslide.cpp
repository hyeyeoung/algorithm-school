#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
	ifstream fin("spinslide.inp");
	ofstream fout("spinslide.out");
	int t;
	fin >> t;
	for (int i = 0; i < t; i++) {
		int n;  int tmp;
		fin >> n >> tmp;
		int** arr = new int* [n]; int** tmp_arr = new int* [n];
		for (int j = 0; j < n; j++) {
			arr[j] = new int[n];
			tmp_arr[j] = new int[n];
			for (int k = 0; k < n; k++) {
				char a;
				fin>>a;
				arr[j][k] = a;
				tmp_arr[j][k] = 0;
			}
		}
		for (int j = 0; j < tmp; j++) {
			for (int k = 0; k < n; k++) {
				for (int c = 0; c < n; c++) {
					tmp_arr[k][c] = arr[n - c - 1][k]; //������
				}
			}
			for (int p = 0; p < n; p++) {
				int check = 0;
				int index = n - 1;
				while (true) {
					if (check == n || index <= 0)
						break;
					if (tmp_arr[index][p] == 46) {
						for (int q = index; q > 0; q--) {
							tmp_arr[q][p] = tmp_arr[q - 1][p];
						}
						tmp_arr[0][p] = 46;
						check++;
					}
					else {
						check++;
						index--;
					}
				}
			}
			for (int p = 0; p < n; p++) {
				for (int q = 0; q < n; q++) {
					arr[p][q] = tmp_arr[p][q];
				}
			}
		}
		fout << "Case #"<<i+1<<":" << endl;
		for (int a = 0; a < n; a++) {
			for (int b = 0; b < n; b++)
				fout << (char)tmp_arr[a][b];
			fout << endl;
		}
		fout << endl;
		for (int j = 0; j < n; j++) {
			delete[]tmp_arr[j];
			delete[]arr[j];
		}
		delete[]tmp_arr;
		delete[]arr;
	}
	fin.close();
	fout.close();
}