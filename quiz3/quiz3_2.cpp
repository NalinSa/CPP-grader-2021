#include <iostream>
#include <vector>
using namespace std;
int n , m , k ,a, b,total;
int inf = 2000000;
vector<int> beau;
vector<int> eachDay;
vector<vector<int>> edge;
vector<bool> visited;
void dfs(int v){
    visited[v] = true;
    total -= beau[v];
    for(auto & u : edge[v]){
        if(!visited[u]){
            dfs(u);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    total = 0;
    cin >> n >> m >> k;
    beau = vector<int>(n);
    eachDay = vector<int>(k);
    edge = vector<vector<int>>(n);
    visited = vector<bool>(n,false);
    for(int i = 0 ; i< n ;i++){
        cin >> b;
        beau[i] = b;
        total+=b;
    }
    for(int i = 0 ; i< k ;i++){
        cin >> b;
        eachDay[i] = b;
    }
    for(int i = 0 ; i< m ;i++){
        cin >> a >> b;
        edge[a].push_back(b);
    }
    for(auto & loca : eachDay){
        if(!visited[loca]){
            dfs(loca);
        }
        cout << total << " ";
    }



}