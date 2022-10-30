#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int dp[1005][1005];
int arr[1005];
int card(int i,int j, bool turn) {
    if (i > j) return dp[i][j] = 0;
    if (dp[i][j] != 0) return dp[i][j];
    if (turn) return dp[i][j] = max(card(i + 1, j, false) + arr[i], card(i, j - 1, false) + arr[j]);
    else return dp[i][j] = min(card(i + 1, j, true), card(i, j - 1, true));
}
int main() {
    freopen("card.inp", "r", stdin);
    freopen("card.out","w",stdout);
    int test_case;
    cin >> test_case;

    while (test_case--) {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) cin >> arr[i];

        card(0, n - 1, true);
        cout<<dp[0][n-1]<<'\n';
        memset(dp,0,sizeof(dp));
    }
}