#include <iostream>
#include <vector>
using namespace std;

vector<int> visited;
vector<vector<int>> table;
int v,e,x,y;
int component = 0;
void dfs(int u){
    visited[u] = true;
    bool onechild = false;
    for(auto & v : table[u]){
        if(onechild) return;
        if(!visited[v]){
            onechild = true;
            dfs(v);
        }
    }
}
void dfs1(){
    for(int i = 0 ; i < v ; i++){
        if(!visited[i]&&table[i].size()<=1){
            component++;
            dfs(i);
        }
    }
    cout << component;
}
int main(){
    cin >> v >> e;
    visited = vector<int>(v,false);
    table = vector<vector<int>>(v);
    while(e--){
        cin >> x >> y;
        table[x].push_back(y);
        table[y].push_back(x);
    }
    dfs1();
    

}