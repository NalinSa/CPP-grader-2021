#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> w;
vector<pair<int,int>> edge;
vector<int> d;
int N,E,s,a,b,c,u,v;
void BellManFord(int s){
    d = vector<int>(N,2000000);
    d[s] = 0;
    for(int i = 0;i<N-1;i++){
        for(auto pa : edge){
            u = pa.first;
            v = pa.second;
            if(d[u]+w[u][v]<d[v]){
                d[v] = d[u]+w[u][v];
            }
        }   
    }
        for(auto pa : edge){
            u = pa.first;
            v = pa.second;
            if(d[u]+w[u][v]<d[v]){
                d.resize(0);
            }
        }   

}
int main(){
    cin >> N >> E >> s;
    w = vector<vector<int>>(N,vector<int>(N));
    for(int i = 0;i<E;i++){
        cin >> a >> b >> c;
        w[a][b] = c;
        edge.push_back(make_pair(a,b));
    }
    BellManFord(s);
    if(d.size()==0){
        cout << -1;
    }
    else{
        for(auto& xx: d){
            cout << xx << " ";
        }
    }
}