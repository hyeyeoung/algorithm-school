#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
struct job{
    int time;
    int gain;
    bool check = false;
};
job arr[1000];
int check[1000];
int n, I;
int free(int index, int sum){
    if(sum >= I || index == n) return sum;
    for(int i = index + 1;i<=n;i++) free(i, sum+arr[i].gain);
}

int main(){
    freopen("freelancer.inp","r",stdin);
    // freopen("freelancer.out","w",stdout);
    cin>>n>>I;
    // 수입의 총합이 i를 넘으면서 최소 시간
    for(int i = 0;i<n;i++) cin>>arr[i].gain >>arr[i].time;
    cout<<free(0,0);
    memset(arr,0,sizeof(arr));
}