#include <iostream>
#include <cstring>
using namespace std;
int k,m,n;
struct node{
    int right; int down; int check; int min[200]; int count[200];
};
node grid[101][101];
void path(){
    int k_count = 0;
    //값 초기화
    for(int i = 1;i<n;i++){ //가로줄 
        if(grid[0][i].check == 1) break;
        else{
            if(i!= 0) grid[0][i].count[0] = 1;
        }
    }
    for(int i = 1;i<m;i++){//세로줄
        if(grid[i][0].check == 1) break;
        else{
            if(i!=0) grid[i][0].count[0] = 1;
        }
    }

    for(int i =0; i<m;i++){
        cout<<grid[i][0].count[0]<<" ";
    }
    cout<<endl;
    for(int i =0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j].check){ //x에 들릴 경우

            }
            else{ //x에 들리지 않을 경우
            
            }
        }
    }
}

int main(){
    freopen("path.inp","r",stdin);
    freopen("path.out","w",stdout);
    int test_case;
    cin>>test_case;
    int count_case=1;
    while(test_case--){
        memset(grid,0,sizeof(node)*200);
        cin>>m>>n>>k;
        for(int i =0;i<k;i++) {
            int x,y;
            cin>>x>>y;
            grid[x][y].check =1;
        }
        for(int i = 0;i<m;i++){
            for(int j =0;j<n-1;j++){
                cin>>grid[i][j].right;
            }
        }
        for(int i =0;i<m-1;i++){
            for(int j = 0;j<n;j++){
                cin>>grid[j][i].down;
            }
        } //값 받아오기
        path();
        cout<<"Test Case No:"<<count_case<<'\n';
        count_case++;
    }//while
}