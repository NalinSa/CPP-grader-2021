#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<int> d;
vector<int> weight;
vector<vector<int>> edge;
vector<int> virus;
int inf = 2000000;
int n,m,k,vi,x,y;
auto cmp = [](const pair<int,int> &lhs,const pair<int,int> &rhs){
    return lhs>rhs;
};
void dijkstraHeap(int u){
    priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(cmp)> pq(cmp);
    if(weight[u]<d[u]) {d[u] = weight[u];
        pq.push(make_pair(d[u],u));
    }
    while(!pq.empty()){
        //cout << pq.top().first << " and " << pq.top().second << endl;
        int thetop = pq.top().second; pq.pop();
        for(auto & v : edge[thetop]){
            if(d[v]>d[thetop]+weight[v]){
                d[v] = d[thetop]+weight[v]; pq.push(make_pair(d[v],v));
            }
        }
    }

    
}
void jonhson(){
    for(auto xx : virus){
       // cout << "diiiii----------" << endl;
        dijkstraHeap(xx);
    }
    int max = -1;
    for(auto& i : d){
        if(i>max) max = i;
    }
    cout << max;
}
int main(){
    cin >> n >> m >> k;
    weight = vector<int>(n);
    virus = vector<int>(k);
    edge = vector<vector<int>>(n);
    d = vector<int>(n,inf);
    for(int i = 0;i<k;i++){
        cin >> vi;
        virus[i] = vi;
    }
    for(int i = 0 ; i < n ; i++){
        cin >> vi;
        weight[i] = vi;
    }
    while(m--){
        cin >> x >> y;
        edge[x].push_back(y);
        edge[y].push_back(x);
    }
    jonhson();

}