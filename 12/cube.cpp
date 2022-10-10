#include <iostream>
using namespace std;
int cube[201][201][201]={0};

void make_cube() {
    for (int i = 1; i <= 200; i++) {
        for (int j = 1; j <= 200; j++) {
            for (int k = 1; k <= 200; k++) {
                if(cube[i][j][k] == 0){
                    if (i == j && j == k) cube[i][j][k] = 1; //초기화
                    else if (j % i == 0 && k % i == 0) {
                        cube[i][j][k] = cube[i][k][j] = cube[j][i][k] = cube[j][k][i] = cube[k][i][j] = cube[j][k][i] = (j / i) * (k / i);
                        continue;
                    }
                    else{
                        int cnt = 1000000;
                        for (int w = 1; w <= i / 2; w++) {
                            int cnt_tmp = cube[w][j][k] + cube[i - w][j][k];
                            if (cnt_tmp < cnt) cnt = cnt_tmp;
                        }    
                        for (int w = 1; w <= j / 2; w++) {
                            int cnt_tmp = cube[i][w][k] + cube[i][j - w][k];
                            if (cnt_tmp < cnt) cnt = cnt_tmp;
                        }
                        for (int w = 1; w <= k / 2; w++) {
                            int cnt_tmp = cube[i][j][w] + cube[i][j][k - w];
                            if (cnt_tmp < cnt) cnt = cnt_tmp;
                        }
                        cube[i][j][k] = cnt;
                    }
                    cube[i][k][j] = cube[j][i][k] = cube[j][k][i] = cube[k][i][j] = cube[j][k][i]=cube[i][j][k];
                }   
            }       
        }                
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    freopen("cube.inp", "r", stdin);
    freopen("cube.out", "w", stdout);
    int test_case; cin >> test_case;
    make_cube();
    while (test_case--) {
        int w, l, h;
        cin >> w >> l >> h;
        cout << cube[w][l][h] << '\n';
    }
}