#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <bitset>
using namespace std;

int main() {
	freopen("coin.inp", "r", stdin);
	freopen("coin.out", "w", stdout);

	int test_case;
	cin >> test_case;
	int test_cnt = 0;
	while (test_case > test_cnt) {
		int arr[3]{};
		int arr_tmp[3]{};
		cin >> arr[0] >> arr[1] >> arr[2];
		if (arr[0] == 0 && arr[1] == 0 && arr[2] == 0) {
			cout << "(" << arr[0] << " " << arr[1] << " " << arr[2] << ") : 1\n";
		}
		else {
			arr_tmp[0] = arr[0] % 4; arr_tmp[1] = arr[1] % 4; arr_tmp[2] = arr[2] % 4;
			int count_1 = 0;
			int count_zero = 0;
			for (int i = 0; i < 3; i++) {
				if (arr_tmp[i] == 0)
					count_zero++;
				if (arr_tmp[i] == 1)
					count_1++;
			}
			if (count_zero + count_1 == 3) //1이 0개 0이 3개
			{
				if(count_zero ==3)
					cout << "(" << arr[0] << " " << arr[1] << " " << arr[2] << ") : 1\n";
				else if(count_1 == 2)
					cout << "(" << arr[0] << " " << arr[1] << " " << arr[2] << ") : 1\n";
				else if(count_1 == 1 || count_1== 3)
					cout << "(" << arr[0] << " " << arr[1] << " " << arr[2] << ") : -1\n";
			}
			else {
				if(bitset<4>(arr_tmp[0] ^ arr_tmp[1] ^ arr_tmp[2]) == 0000)
					cout << "(" << arr[0] << " " << arr[1] << " " << arr[2] << ") : -1\n";
				else 
					cout << "(" << arr[0] << " " << arr[1] << " " << arr[2] << ") : 1\n";
			}
				
		}
		
		
		test_cnt++;
	}
	
}

