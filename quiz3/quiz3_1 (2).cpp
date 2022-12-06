#include <iostream>
#include <vector>
using namespace std;
int n,m,k,finall,kk,aa,bb,cc;
int inf = 2000000;
vector<pair<int,int>> edge;
vector<vector<int>> weight;
vector<int> ds;
void bellman(){
    bool isthesame;
    for(int i = 0;i<n-1;i++){
        isthesame = true;
        for(auto & pp : edge){
            int u = pp.first;
            int v = pp.second;
            if(ds[u]+weight[u][v]<ds[v]){
                ds[v] = ds[u]+weight[u][v];
                isthesame = false;
            }
        }
        if(isthesame) break;
    }
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m >> k;
    cin >> finall;
    weight = vector<vector<int>>(n,vector<int>(n));
    edge = vector<pair<int,int>>(m);
    ds = vector<int>(n,inf);
    for(int i = 0;i<k;i++){
        cin >> kk;
        ds[kk] = 0;
    }
    for(int i = 0;i<m;i++){
        cin >> aa >> bb >> cc;
        edge[i] = make_pair(aa,bb);
        weight[aa][bb] = cc;
    }
    bellman();
    int ans=ds[finall];
    cout << ans;
}