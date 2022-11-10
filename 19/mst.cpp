#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct edge{
    int anode;
    int bnode;
    int weight;
};
bool compare(const edge& e1, const edge& e2){
    if(e1.weight >= e2.weight) return e1.weight >= e2.weight;
    else return e1.weight<e2.weight;
}

void Kur(){

}

int main(){
    freopen("mst.inp","r",stdin);
    // freopen("mst.out","w",stdout);
    int n,m; //n은 v, m은 e
    cin>>n>>m;
    int *k_ = new int[n];
    vector<edge> arr;
    for(int i =0;i<m;i++){
        edge edge;
        cin>>edge.anode>>edge.bnode>>edge.weight;
        arr.push_back(edge);
    }
    sort(arr.begin(),arr.end(),compare);

    for(int i = 0;i<m;i++){
        cout<<arr[i].anode << " "<<arr[i].bnode<<" "<<arr[i].weight<<'\n';
    }
    delete[]k_;
}