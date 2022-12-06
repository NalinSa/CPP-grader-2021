#include <iostream>
#include <vector>
using namespace std;
int N,M,X;
vector<vector<int>> mustBeFinish;
vector<int> order;
vector<bool> visited;
void dfs(int u){
    visited[u] = true;
    for(auto v : mustBeFinish[u]){
        if(!visited[v]){
            dfs(v);
        }
    }
    order.push_back(u);
}
void dfs1(){
    for(int i = 0;i<N;i++){
        if(!visited[i]){
            dfs(i);
        }
    }
}
int main(){
    cin >> N;
    mustBeFinish = vector<vector<int>>(N);
    visited = vector<bool>(N,false);
    for(int i = 0;i<N;i++){
        cin >> M;
        for(int j = 0; j<M;j++){
            cin >> X;
            mustBeFinish[X].push_back(i);
        }
    }
    dfs1();
    for(int i = order.size()-1;i>=0;i--){
        cout << order[i] << " ";
    }
}