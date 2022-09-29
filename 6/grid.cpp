#include <fstream>
using namespace std;
int main() {
	
	ifstream fin("grid.inp");
	ofstream fout("grid.out");
	
	int test_case;
	fin >> test_case;
	for (int i = 0; i < test_case; i++) {
		int n, m, k;
		fin >> n >> m >> k;
		int* arr = new int[k];
		int* tmp = new int[k];
		int total = 0;
		
		for (int j = 0; j < k; j++) {
			fin >> arr[j]; //arr = 물감의 양
			total += arr[j];
		}
		int count = 0;
		bool flaga = false, flagb = false;
		for (int j = 0; j < k; j++) {
			tmp[j] = arr[j] / m;
			if (tmp[j] >= 2) {
				count += tmp[j];
			}
		}
		if (count < n) {
			count = 0;
			for (int j = 0; j < k; j++) {
				tmp[j] = arr[j] / n;
				if (tmp[j] >= 2) {
					count += tmp[j];
				}
			}
			if (count < m)
				fout << "No\n";
			else {
				fout << "Yes\n";
			}
		}
		else {
			fout << "Yes\n";
		}
		
		delete[]tmp;
		delete[]arr;
	}
	fin.close();
	fout.close();
}