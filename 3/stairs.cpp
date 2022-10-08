#include <fstream>
using namespace std;

int main() {

	ifstream fin("stairs.inp");
	ofstream fout("stairs.out");
	int t;
	fin >> t;

	for (int i = 0; i < t; i++) {
		int m, f, n; 
		fin >> m >> f >> n;
		if (n % (m - 1) != 0) {
			fout << n / (m - 1) + 1 << endl;
		}
		else {
			fout << n / (m - 1) << endl;
		}
	}

	fin.close();
	fout.close();
}