#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;
vector<int> contain;
vector<bool> visited;
vector<vector<int>> edges;
int countt(int vertice,int k){
    int count = 1;
    queue<int> que;
    que.push(vertice);
    contain[vertice] = 0;
    visited[vertice] = true;
    while(!que.empty()){
        int u = que.front();que.pop();
        for(auto& v : edges[u]){
            if(!visited[v]){
                contain[v] = contain[u] +1;
                visited[v] = true;
                count++;
                if(contain[v]<k){
                    que.push(v);
                }
            }
        }
    }
    return count;
}
int main(){
    int n,e,k,v1,v2;
    cin >> n >> e >> k;
    edges.resize(n);
    while(e--){
        cin >> v1 >> v2;
        edges[v1].push_back(v2);
        edges[v2].push_back(v1);
    }
    int max = 0;
    int person = -1;
    for(int i = 0;i<n;i++){
        visited = vector<bool>(n,false);
        contain = vector<int>(n,-1);
        int x = countt(i,k);
        if(x>max){
            max  = x;
            person = i;
        }
    }
    cout << max;
}