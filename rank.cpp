#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N,P,win,loss;
vector<vector<int>> pointTo;
vector<vector<int>> isPointedFrom;
vector<int> order;
vector<bool> visited;
vector<pair<int,int>>
void scc(){
    visited = vector<bool>(N,false);
    for(int i = 0;i<N;i++){
        if(!visited[i]){
            dfs1(i);
        }
    }
    visited = vector<bool>(N,false);
    for(int i = order.size()-1;i>=0;i--){
        if(!visited[order[i]]){
            dfs2(order[i]);
        }
    }
}
int main(){
    cin >> N >> P;
    pointTo = vector<vector<int>>(N);
    isPointedFrom = vector<vector<int>>(N);
    while(P--){
        cin >> win >> loss;
        pointTo[win].push_back(loss); 
        isPointedFrom[loss].push_back(win);
    }
}