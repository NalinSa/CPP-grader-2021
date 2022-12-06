#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<vector<int>> table;
vector<int> ds;
vector<int> d;
vector<bool> visited;
int N,num,u;

auto cmp = [](const pair<int,int>& lhs,const pair<int,int>& rhs){
    if(lhs.first==rhs.first){
        return lhs.second > rhs.second;
    }
    else{
        return lhs.first > rhs.first;
    }
};
void Prim(){
    ds = vector<int>(N,2000000);
    d = vector<int>(N,2000000);
    visited = vector<bool>(N,false);
    d[0] = 0;
    //priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(cmp)> pq(cmp);
    //pq.push(make_pair(0,0));
    for(int i = 0;i<N;i++){
        int u = 0;
        int min = 2000000;
        for(int j = 0 ; j<N;j++){
            if(ds[j]<min){
                min = ds[j];
                u = j;
            }
        }
        visited[u] = true;
        ds[u] = 2000000;
        for(int v = 0;v<N;v++){
            if(!visited[v]&&table[u][v]<ds[v]){
                d[v] = ds[v] = table[u][v];
                
            }
        }

    }
}
    
int main(){
    cin >> N;
    table = vector<vector<int>>(N,vector<int>(N));
    for(int i = 0;i<N;i++){
        for(int j = i+1; j<N;j++){
            cin >> num;
            table[i][j] = num;
            table[j][i] = num;
        }
    }
    Prim();
    int countt = 0;
    for(auto&x : d){
        //cout << x << "Ha\n";
        countt+=x; 
    }
    cout << countt;
}