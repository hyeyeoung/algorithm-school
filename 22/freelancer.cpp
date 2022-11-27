#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
struct free
{
    int gain;
    int time;
};

int n, I;
int grid[1001][1001];
struct free job[1001];

void freelancer(){ //i번째 인덱스, j번째 인덱스
    memset(grid,0,sizeof(grid));

}

int main(){
    freopen("freelancer.inp","r",stdin);
    // freopen("freelancer.out","w",stdout);W
    
    cin>>n>>I;
    for(int i = 0;i<n;i++) cin>>job[i].gain >> job[i].time;
    
}