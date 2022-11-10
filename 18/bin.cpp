#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <cstring>
#include <iomanip>
using namespace std;

int bin[510][510]; // 1,2 : 값의 차이, 첫번째 쓰레기통의 위치
int arr[510]{ 0 };
int n, m; //n은 집의 갯수, m은 분리수거 통의 갯수
//배열에 저장된 값을 가져오는 것. 


int main() {
    freopen("bin.inp", "r", stdin);
    // freopen("bin.out", "w", stdout);
    int testcase;
    cin >> testcase;
    while (testcase--) {
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            cin >> arr[i]; // 배열 값 입력.
            //if (i < m) check[i] = 1;
        }
        sort(arr, arr + n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (arr[i] > arr[j]) bin[i][j] = bin[j][i] = arr[i] - arr[j];
                else bin[i][j] = bin[j][i] = arr[j] - arr[i];
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                cout <<right <<setw(5) << bin[i][j] << " ";
            cout << endl;
        }
        memset(arr, 0, sizeof(arr));
        memset(bin, 0, sizeof(bin));
    }//while-testcase
}//main