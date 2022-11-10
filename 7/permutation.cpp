#include <iostream>
#include <fstream>
using namespace std;

int main() {
	ifstream fin("permutation.inp");
	ofstream fout("permutation.out");

	int test_case;
	fin >> test_case;
	for (int i = 0; i < test_case; i++) {
		int size;
		fin >> size;
		int index = 0;
		int* arr = new int[size];	
		int* arr_bf = new int[size];
		for (int j = 0; j < size; j++) {
			fin >> arr[j]; 
			arr_bf[j] = 0;
		}
			
		for (int j = 0; j < size; j++) {
			for (int k = j+1; k < size; k++) {
				if (arr[j] <= arr[k])
					break;
				else {
					arr_bf[k]++;
				}
			}
		}
		for (int j = size-1; j >= 0; j--) {
			for (int k = j - 1; k >= 0; k--) {
				if (arr[j] <= arr[k])
					break;
				else {
					arr_bf[k]++;
				}
			}
		}

		for (int j = 0; j < size; j++) {
			fout << arr_bf[j] << " ";
		}
		fout << '\n';
		
		delete[]arr_bf;
		delete[]arr;
	}

	fin.close();
	fout.close();
}
