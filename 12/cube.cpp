#include <iostream>
using namespace std;
int cube[201][201][201]{-1};

int cut(){

}

void make_cube(){
    cube[1][1][1] = 1;
    for(int i = 0;i<201;i++){
        cube[i][i][i] = 1;
    }
}

int main(){
    freopen("cube.inp","r",stdin);
    freopen("cube.out","w",stdout);
    int test_case; cin>>test_case;
    
    make_cube();

    while(test_case--){
        int w,l,h;
        cin>>w>>l>>h;
    }
}