#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int bin[510]; // 최소값 저장 배열
int arr[510]{ 0 }; // 값을 받아오는 배열
bool check[510]{ 0 }; //f로 초기화된 불배열
int n, m; //n은 집의 갯수, m은 분리수거 통의 갯수

// 계산기 함수(쓰레기 통의 위치를 제외한 나머지 배열 덧셈)
int total_calc(int min) { //index = 쓰레기 통의 위치
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (!check[i]) sum += bin[i]; // check가 false면 쓰레기통은 배치되지 않았다는 의미
        if (sum > min) break;
    }
    return sum;
}
// 빼기 함수
int miuns_cal(int min) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (check[i]) {
            for (int j = 0; j < n; j++) {
                if (!check[j]) {
                    int tmp = bin[j];
                    if (bin[j] >= (arr[i] - arr[j]) || bin[j] >= (arr[j] - arr[i])) {
                        if (arr[i] > arr[j]) bin[j] = arr[i] - arr[j];
                        else bin[j] = arr[j] - arr[i];
                        //bin[j] = max(arr[i] - arr[j], arr[j] - arr[i]);
                    }
                    else {
                        if (tmp != bin[j]) sum -= tmp; // 값이 변화되었다면?
                    }
                    sum += bin[j];
                } // 쓰레기 통이 없을 때, 연산
                else if(j>=i && check[j]) break;
            }
            if (min < sum) return -1;
        }// i 번째가 쓸레기통일때
    }// i반복
    return sum;
}
int bins() {
    int min = 51000;
    do { //조합 반복문 사용
        fill_n(bin, n, 51000);
        int tmp = miuns_cal(min);
        if (tmp != -1) {
            // if (min > tmp) min = tmp;
            min = tmp;
        }
    } while (prev_permutation(check, check + n)); // 첫번째 
    return min;
}
int main() {
    freopen("1.inp", "r", stdin);
    //freopen("bin.out", "w", stdout);
    int testcase;
    cin >> testcase;
    while (testcase--) {
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            cin >> arr[i]; // 배열 값 입력.
            if (i < m) check[i] = 1;
        }
        sort(arr, arr + n);
        cout << bins() << "\n";
    }//while-testcase
}//main