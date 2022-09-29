#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <string>
#include <cstdio>
using namespace std;

vector<vector<char>> inp;
vector<vector<char>> out2;
string out, line;

int getDigit(int n) {
    if (n < 10)return 1;
    if (n < 100)return 2;
    return 3;
}

void caseB(int rowCount, int colCount, int rowStart, int colStart) {
    char com = inp[rowStart][colStart];
    for (int i = rowStart; i < rowStart + rowCount; i++) {
        for (int j = colStart; j < colStart + colCount; j++) {
            if (com != inp[i][j]) {
                out += 'D';

                if (rowCount == 1) {
                    caseB(rowCount, (int)ceil(colCount / 2.0), rowStart, colStart);
                    caseB(rowCount, colCount / 2, rowStart, (int)ceil(colStart + colCount / 2.0));
                }
                else if (colCount == 1) {
                    caseB((int)ceil(rowCount / 2.0), colCount, rowStart, colStart);
                    caseB(rowCount / 2, colCount, rowStart + (int)ceil(rowCount / 2.0), colStart);
                }
                else {
                    caseB((int)ceil(rowCount / 2.0), (int)ceil(colCount / 2.0), rowStart, colStart); //왼쪽 위
                    caseB((int)ceil(rowCount / 2.0), colCount / 2, rowStart, colStart + (int)ceil(colCount / 2.0)); //오른쪽 위
                    caseB(rowCount / 2, (int)ceil(colCount / 2.0), rowStart + (int)ceil(rowCount / 2.0), colStart); //왼쪽 아래
                    caseB(rowCount / 2, colCount / 2, rowStart + (int)ceil(rowCount / 2.0), colStart + (int)ceil(colCount / 2.0)); //오른쪽 아래
                }
                return;
            }
        }
    }

    out += com;
}

void caseD(int rowCount, int colCount, int rowStart, int colStart) {
    char com = cin.get();
    if (com == '\n')com = cin.get();

    if (com == '1' || com == '0') {
        for (int i = rowStart; i < rowStart + rowCount; i++) {
            for (int j = colStart; j < colStart + colCount; j++) {
                out2[i][j] = com;
            }
        }
    }
    else {

        if (rowCount == 1) {
            caseD(rowCount, (int)ceil(colCount / 2.0), rowStart, colStart);
            caseD(rowCount, colCount / 2, rowStart, (int)ceil(colStart + colCount / 2.0));
        }
        else if (colCount == 1) {
            caseD((int)ceil(rowCount / 2.0), colCount, rowStart, colStart);
            caseD(rowCount / 2, colCount, rowStart + (int)ceil(rowCount / 2.0), colStart);
        }
        else {
            caseD((int)ceil(rowCount / 2.0), (int)ceil(colCount / 2.0), rowStart, colStart); //왼쪽 위
            caseD((int)ceil(rowCount / 2.0), colCount / 2, rowStart, colStart + (int)ceil(colCount / 2.0)); //오른쪽 위
            caseD(rowCount / 2, (int)ceil(colCount / 2.0), rowStart + (int)ceil(rowCount / 2.0), colStart); //왼쪽 아래
            caseD(rowCount / 2, colCount / 2, rowStart + (int)ceil(rowCount / 2.0), colStart + (int)ceil(colCount / 2.0)); //오른쪽 아래
        }
        return;
    }

    return;
}

int main() {

    freopen("0.inp", "r", stdin);
    freopen("bitmap.out", "w", stdout);

    char format;

    while (1) {
        cin >> format;
        if (format == '#')break;
        int row, column;
        cin >> row >> column;
        cin.ignore();

        cout << (format == 'B' ? "D" : "B");
        //for (int i = 0; i < 4 - getDigit(row); i++)cout << " ";
        cout << " " << row;
        //for (int i = 0; i < 4 - getDigit(column); i++)cout << " ";
        cout << " " << column << "\n";

        if (format == 'B') {
            string tempLine;
            inp.resize(row, vector<char>(column));
            while (tempLine.size() < row * column) {
                string tmp;
                getline(cin, tmp);
                tempLine += tmp;
            }
            for (int i = 0; i < row; i++) {
                for (int j = 0; j < column; j++) {
                    inp[i][j] = tempLine[i * column + j];
                }
            }
            caseB(row, column, 0, 0);

            int outLen = out.length();
            int cnt = 0;
            for (int i = 0; i < outLen; i++) {
                if (cnt >= 50) {
                    cnt = 0;
                    cout << "\n";
                }
                cout << out[i];
                cnt++;
            }
            cout << "\n";
        }
        else {
            out2.resize(row, vector<char>(column));
            caseD(row, column, 0, 0);
            int cnt = 0;
            for (int i = 0; i < row; i++) {
                for (int j = 0; j < column; j++) {
                    if (cnt >= 50) {
                        cnt = 0;
                        cout << "\n";
                    }
                    cout << out2[i][j];
                    cnt++;
                }
            }
            cout << "\n";
        }
        inp.clear();
        out2.clear();
        out = line = "";
    }

}