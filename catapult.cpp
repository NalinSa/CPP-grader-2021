#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n,m,x;
vector<vector<int>> direct;
vector<vector<int>> from;
vector<int> ans;
vector<bool> visited;
vector<int> order;
int counted = 0;

void dfs1(int u){
    visited[u] = true;
    //cout<< "dfs11" << endl;
    for(auto v : direct[u]){
        if(!visited[v]){
            dfs1(v);
        }
    }
    order.push_back(u);
    //cout<< "fisnish1" << endl;
    
}

void dfs2(int u){
    //cout<< "dfs2" << endl;
    visited[u] = true;
    counted++; 
    for(auto v : from[u]){
        if(!visited[v]){
            dfs2(v);
        }
    }    
}
void scc(){
    visited = vector<bool>(n,false);
    for(int i = 0;i<n;i++){
        if(!visited[i]){
            dfs1(i);
        }
    }
    visited = vector<bool>(n,false);
    //cout << order.size()-1;
    for(int j = order.size()-1;j>=0;j--){
        if(!visited[order[j]]){
            dfs2(order[j]);
            ans.push_back(counted);
            counted = 0;
            
        }
    }
}
int main(){
    cin >> n;
    direct = vector<vector<int>>(n);
    from = vector<vector<int>>(n);
    for(int i = 0;i<n;i++){
        cin >> m;
        for(int j = 0;j<m;j++){
            cin >> x;
            direct[i].push_back(x);
            from[x].push_back(i);
        }
    }
    scc();

    sort(ans.begin(),ans.end());

    for(auto & x : ans){
        cout << x << " ";
    }
}