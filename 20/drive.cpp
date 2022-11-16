// #define _CRT_SECURE_NO_DEPRECATE
// #define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int grid[110][110][201][2]; // i~j까지, k번 턴을 돌아서 q는 왼쪽에서 오는지 오른쪽에서 오는지 체크
int grid_down[110][110];
int grid_left[110][110];
int m, n, l, g;
//최소한 길을 안 돌고 추가 연료없는 길을 찾는다.
//왼쪽-> 오른쪽: 0, 위-> 아래: 1
void drive() {
    // 초기값 설정
    //fill(&grid[0][0][0][0], &grid[m][n][200][3], 250);
    memset(grid, 0x3f, sizeof(grid));
    grid[0][0][0][0] = grid[0][0][0][1] = 0; // 시작점에서 사용한 연료는 0이다.
    //for (int i = 0; i < m; i++) {
      //grid[i + 1][0][0][1] = grid[i][0][0][1] + grid_down[i][0];
     //}
     //for (int i = 0; i < n; i++) {
      //   grid[0][i + 1][0][0] = grid[0][i][0][0] + grid_left[0][i];
     //}
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            //int tmp = max(i, j) * 2;
            for (int k = 0; k < 200; k++) {
                //위 아래 값에서 업데이트(턴 존재)
                //if (tmp <= k) break;
                if (j < (n - 1)) {
                    grid[i][j + 1][k][0] = min(grid[i][j + 1][k][0], grid[i][j][k][0] + grid_left[i][j]);
                    grid[i][j + 1][k + 1][0] = min(grid[i][j + 1][k + 1][0], grid[i][j][k][1] + grid_left[i][j]);

                }
                if (i < (m - 1)) {
                    grid[i + 1][j][k][1] = min(grid[i + 1][j][k][1], grid[i][j][k][1] + grid_down[i][j]);
                    grid[i + 1][j][k + 1][1] = min(grid[i + 1][j][k + 1][1], grid[i][j][k][0] + grid_down[i][j]);
                }
            }
        }
    }
    int result = 2500;
    for (int i = 0; i < 200; i++) {
        if (g >= grid[m - 1][n - 1][i][0] || g >= grid[m - 1][n - 1][i][1]) {
            result = min(result, i);
        }
    }
    if (result == 2500) cout << -1 << '\n';
    else cout << (((m - 1) + (n - 1)) * l) + result << '\n';

}
int main() {
    freopen("drive.inp", "r", stdin);
    freopen("drive.out", "w", stdout);
    int testcase;
    cin >> testcase;
    while (testcase--) {
        //m,n은 그리드 크기, l은 주행시간 ,g는 초기 연료
       //모든 칸의 l은 결국 동일, 차이점은 턴을 돌 때의 차이점이다. g는 추가없는 연료
        cin >> m >> n >> l >> g;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n - 1; j++)
                cin >> grid_left[i][j];
        }
        for (int i = 0; i < m - 1; i++) {
            for (int j = 0; j < n; j++) cin >> grid_down[i][j];
        }

        drive();

        memset(grid_left, 0, sizeof(grid_left));
        memset(grid_down, 0, sizeof(grid_down));
    }
}