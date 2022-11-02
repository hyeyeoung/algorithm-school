#include <iostream>
#include <cstring>
using namespace std;
int n, k;
int parti[310][310];
int partition(int np, int kp) {
    if (parti[np][kp] != 0) return parti[np][kp];
    else{
        if (kp == 1) return parti[np][kp] = 1;
        if (np == kp) return parti[np][kp] = 1;
        if (np < kp) return parti[np][kp] = 0;
        if (np < 2 || kp < 1) return parti[np][kp] = 0;
        return parti[np][kp] = (partition(np - 1, kp - 1) + partition(np - kp, kp)) % 1000000007;
    }
}
int main() {
    freopen("addingways.inp", "r", stdin);
    freopen("addingways.out","w",stdout);
    
    while (true) {
        cin >> n >> k;
        if (n == 0 && k == 0) break;
        partition(n, k);
        cout << parti[n][k] << '\n';
        memset(parti, 0, sizeof(parti));
    }
}