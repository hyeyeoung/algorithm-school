#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int dp[510];
int arr[510];
int sum(int index, int start, int end){//합치기 함수
    int sum = 0;
    for(int i = start;i<=end;i++){
        if(arr[index] > arr[i]) sum += arr[index] - arr[i];
        else sum += arr[i] - arr[index];
    }
    return sum;
}
int bin(int i, int j, int count){ //i는 왼쪽 j는 오른쪽 마지막 인덱스 count는 횟수 변수
    if(count == 1) if((i+j)%2 == 0) return dp[(i+j)/2] = sum((i+j)/2, i,j);
    return bin(i,((i+j)/2),count--);
    return bin(((i+j)/2)+1,j,count--);
}
int main(){
    freopen("bin.inp","r",stdin);
    // freopen("bin.out","w",stdout);

    int testcase;
    cin>>testcase;

    while(testcase--){
        int n, m;
        cin>>n>>m;
        for(int i = 0; i<n; i++)cin>>arr[i]; // 배열 값 입력.
        sort(arr,arr+n); // x좌표 정렬
        bin(0,n-1,m);
        
        for(int i =0;i<n;i++) cout<<dp[i]<<" "; // 출력 for문
    }//while-testcase
}//main