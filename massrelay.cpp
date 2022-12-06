#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
auto cmp = [](const pair<int,pair<int,int>> &lhs, const pair<int,pair<int,int>> &rhs){
    return lhs>rhs;
};
priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,decltype(cmp)> pq(cmp);
int vertex,M,Q,a,b,c,ww,indexx;
int inf = 2000000;
vector<int> parent;
vector<int> height;
vector<int> ans;
int ccc = 0;
vector<int> weight;
int findSet(int x){
    int p = x;
    while(parent[p]!=p){
        p = parent[p];
    }
    return p;
}
void unionSet(int x,int y){
    if(height[x]>height[y]){
        parent[y] = x;
        weight[y] += ww;
        if(weight[y]>ccc){
            ccc = weight[y];
        }
    }
    else{
        parent[x] = y;
        if(height[x]==height[y]){
            height[x]++;
        }
        weight[x] += ww;
        if(weight[x]>ccc){
            ccc = weight[x];
        }
    }
    ans[indexx] = ccc;
    indexx--;
}
int main(){
    cin >> vertex >> M >> Q;
    weight = vector<int>(vertex,0);
    parent = vector<int>(vertex);
    ans = vector<int>(vertex+1);
    height = vector<int>(vertex,0);
    for(int i = 0 ; i < vertex ; i++){
        parent[i] = i;
    }
    while(M--){
        cin >> a >> b >> c;
        pq.push(make_pair(c,make_pair(a,b)));
    }
    indexx = vertex - 1;
    while(!pq.empty()){
        int u = pq.top().second.first;
        int v = pq.top().second.second;
        ww = pq.top().first;
        pq.pop();
        if(findSet(u)!=findSet(v)){
            unionSet(findSet(u),findSet(v));
        }
    }
    while(Q--){
        cin >> a;
        cout << ans[a] << "\n";
    }

}