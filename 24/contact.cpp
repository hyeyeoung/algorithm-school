#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int INF = 3000000;
int main(){
    freopen("1.inp","r",stdin);
    // freopen("contact.out","w",stdout);
    int testcase;
    cin>>testcase;
    while(testcase--){
        int n, m, k_num; // n=정점의 갯수, m=간선의 갯수, 질문의 갯수k? 
        cin>>n>>m>>k_num; // k = 두 요원의 초기값 갯수
        int index, j, w;
        for(int i = 1;i<=m;i++){ // 1부터 시작하는 그리드 작성
            cin>>index>>j>>w;
            //city[index][j] = w;
        }
    }
}