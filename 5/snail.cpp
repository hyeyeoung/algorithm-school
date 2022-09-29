#include <fstream>
#include <iostream>
using namespace std;
void grid(int n) { //n = ±×¸®µå ¤¡

}

int main() {
	ifstream fin("snail.inp");
	ofstream fout("snail.out");
	int test_case;
	fin >> test_case;
	for (int i = 0; i < test_case; i++) {
		long long n;
		fin >> n;
		long long a, b;
		fin >> a >> b;
		long long cnt = 1;
		long long num = 4 * (n - 1);
		long long num_ = 1;
		for (double j = 0; j <= n/2  + 1; j++) {
			if (a <= num && a >= num_)
				break;
			else {
				cnt++;
				num_ = num + 1;
				num += 4*n-8*cnt+4;
			}
		}
		cout << cnt << endl;
		long long ax = cnt, ay = cnt;
		long long n_tmp = n - 2 * (cnt - 1);
		long long fi = n_tmp - 1;
		long long se = n_tmp - 2;
		if (a >= num_ && a <= (num_ + n_tmp) - 1) {
			ay += (a - num_);
		}
		else if (a >= num_ + n_tmp - 1 && a <= num_ + n_tmp + fi - 1) {
			if (a != num_ + n_tmp - 1) {
				ay += n_tmp - 1;
				ax += a - (num_ + n_tmp -1);
			}
			
		}
		else if (a >= num_ + n_tmp + fi -1 && a <= num_ + n_tmp + fi + fi - 1) {
			if (a != num_ + n_tmp + fi - 1) {
				ax += n_tmp - 1;
				ay += n_tmp - 1;
				ay -= a - (num_ + n_tmp + fi - 1);
			}
		}
		else if (a >= num_ + n_tmp + fi + fi-1 && a <= num_ + n_tmp + fi + fi + se - 1) {
			if (a != num_ + n_tmp + fi + fi - 1) {
				ax += n_tmp - 1;
				ay += n_tmp - 1;
				ay -= n_tmp - 1;
				ax -= a - (num_ + n_tmp + fi + fi - 1);
			}
			
		}
		cnt = 1;
		num = 4 * (n - 1);
		num_ = 1;
		for (long long j = 0; j <= (n/2) +1; j++) {
			if (b <= num && b >= num_)
				break;
			else {
				cnt++;
				num_ = num + 1;
				num += 4 * n - 8 * cnt + 4;
			}
		}
		long long bx = cnt, by = cnt;
		n_tmp = n - 2 * (cnt - 1);
		fi = n_tmp - 1;
		se = n_tmp - 2;
		if (b >= num_ && b <= (num_ + n_tmp) - 1) {
			by += (b - num_);
		}
		else if (b >= num_ + n_tmp - 1 && b <= num_ + n_tmp + fi - 1) {
			if (b != num_ + n_tmp - 1) {
				by += n_tmp - 1;
				bx += b - (num_ + n_tmp - 1);
			}

		}
		else if (b >= num_ + n_tmp + fi - 1 && b <= num_ + n_tmp + fi + fi - 1) {
			if (b != num_ + n_tmp + fi - 1) {
				bx += n_tmp - 1;
				by += n_tmp - 1;
				by -= b - (num_ + n_tmp + fi - 1);
			}
		}
		else if (b >= num_ + n_tmp + fi + fi - 1 && b <= num_ + n_tmp + fi + fi + se - 1) {
			if (b != num_ + n_tmp + fi + fi - 1) {
				bx += n_tmp - 1;
				by += n_tmp - 1;
				by -= n_tmp - 1;
				bx -= b - (num_ + n_tmp + fi + fi - 1);
			}

		}
		
		long long x = 0, y = 0;
		if (ax > bx)
			x = ax - bx;
		else
			x = bx - ax;

		if (ay > by)
			y = ay - by;
		else
			y = by - ay;

		if (x == y)
			cout << "YES" << '\n';
		else
			cout << "NO" << '\n';
	}

	fin.close();
	fout.close();
}