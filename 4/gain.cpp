#include <fstream>
#include <limits.h>
using namespace std;

int main() {
	ifstream fin("gain.inp");
	ofstream fout("gain.out");
	int t;
	fin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		fin >> n;
		int* arr = new int[n];
		int max1 = INT_MIN, max2 = INT_MIN;
		int min1 = INT_MAX, min2 = INT_MAX;
		for (int j = 0; j < n; j++) {
			fin >> arr[j];
			if (arr[j] > max1) {
				max2 = max1;
				max1 = arr[j];
			}
			else if (arr[j] > max2)
				max2 = arr[j];
			if (arr[j] < min1) {
				min2 = min1;
				min1 = arr[j];
			}
			else if (arr[j] < min2)
				min2 = arr[j];
		}
		fout << (max1 + max2) - (min1 + min2) << endl;
		delete[] arr;
	}
	fin.close();
	fout.close();
}