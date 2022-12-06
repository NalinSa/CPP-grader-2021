#include <iostream>
#include <vector>
#include <stack>
using namespace std;
vector<vector<int>> edges;
vector<bool> visited;
vector<int> p;
bool dfs(int u){
    visited[u] = true;
    for(auto &v :edges[u]){
        //cout << "this is v = " << v << endl; 
        if(visited[v]){
            //cout<< "visited[v] " << p[v] << " and " << u; 
            if(p[u]!=v) return true;
        }
        else{
            p[v] = u;
            if(dfs(v)) return true;         
        }
    }
    //cout << "return false" << endl;
    return false;
}
bool isCycle(){
    for(int i = 0;i<visited.size();i++){
        //cout << "loop one" << endl;
        if(!visited[i]){
           // cout << "In if" << endl;
            if(dfs(i)) return true;
        }
    }
    return false;
}

int main(){
    int t,n,e,v1,v2;
    cin >> t;
    while(t--){
        cin >> n >> e;
        edges = vector<vector<int>>(n);
        p = vector<int>(n,-1);
        while(e--){
            cin >> v1 >> v2;
            edges[v1].push_back(v2);
            edges[v2].push_back(v1);
        }
        visited = vector<bool>(n,false);
        if(isCycle()) {
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
}