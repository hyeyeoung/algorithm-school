#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int Max(int a, int b, int c) { //매개변수 3개의 값 비교
	if (a >= b && a >= c) return a;
	else if (b > a && b >= c) return b;
	else if (c > a && c > b) return c;
}
int Max_4(int a, int b, int c, int d) { //매개변수 4개의 값 비교
	if (a >= b && a >= c && a >= d) return a;
	else if (b > a && b >= c && b >= d) return b;
	else if (c > a && c > b && c >= d) return c;
	else if (d > a && d > b && d > c) return d;
}
void find_max(vector<int>& arr, vector<int>& max_, int n) {
	max_[1] = arr[1];
	max_[2] = arr[2];
	max_[3] = arr[3];
	max_[4] = max(arr[4] + max_[2], arr[4] + max_[1]);
	if (n >= 5) {
		for (int i = 5; i <= n; i++) {
			if (i == 5) max_[i] = Max(arr[i] + max_[i - 2], arr[i] + max_[i - 3], arr[i] + max_[i - 4]);
			else if (i == 6) max_[i] = Max(arr[i] + arr[i - 2] + max_[i - 5], arr[i] + max_[i - 3], arr[i] + max_[i - 4]);
			else if(i>6) max_[i] = Max_4(max_[i - 5] + arr[i - 2] + arr[i], max_[i - 6] + arr[i - 2] + arr[i], max_[i - 3] + arr[i], max_[i - 4] + arr[i]);
		}
	}
}
int main() {
	freopen("card.inp", "r", stdin);
	freopen("card.out", "w", stdout);
	int test_case;
	cin >> test_case;
	while (test_case--) {
		int n;	cin >> n;
		vector<int> arr(n + 1, 0);  vector<int> max_(n + 1, 0);
		int index = 1;
		while (n >= index) {
			cin >> arr[index];
			index++;
		}
		find_max(arr, max_, n);
		cout << max_[n] << '\n';
	}
}