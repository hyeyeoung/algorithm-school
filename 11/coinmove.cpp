#include<fstream>
#include<algorithm>
#include<cstring>
#include<iostream>
#include <vector>
using namespace std;

int p, k, s;
vector<vector<int>> board(1000001, vector<int>(8,0));

void coinmove() {
    for (int i = 1; i <= s; i++) {
        if (i % p != 0||i==s) {
            for (int j = 1; j <= k; j++) { 
                if (i - j >= 0) { 
                    if ((i - j) != 0 && (i - j) % p == 0)
                        board[i][j] = 0;
                    else
                        board[i][j] = 1;
                    for (int v = 0; v <= k; v++) {
                        if (v != j) {
                            if (board[i-j][v])
                                board[i][j] = 0;
                        }
                    }

                }
            }
        }
    }
}

int number() {
    for (int i = 1; i <= k; i++) {
        if (board[s][i]) {
            return s - i;
        }
    }
    return -1; //승리할 수 없는 경우
}

int main() {

    ifstream fin("coinmove.inp");
    ofstream fout("coinmove.out");

    int test_case;
    fin >> test_case;
    int test_cnt = 0;
    while (test_case>test_cnt) {
        fin >> p >> k >> s;
        coinmove();
        fout << number() << '\n';
        fin.ignore();
        test_cnt++;
    }

    fin.close();
    fout.close();
}