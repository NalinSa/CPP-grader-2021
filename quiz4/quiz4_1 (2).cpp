#include <iostream>
#include <vector>
using namespace std;
int V,E;
vector<int> Ans(8);
vector<vector<int>> tableWeight;
int totalWeight(){
    
}
bool findDistance(int& far,vector<int> choose){
    if(choose.size()==0){
        for(int i = 0;i<V;i++){
            choose.push_back(i);
            findDistance(far,choose);
            choose.pop_back();
        }
    }
    for(int i = 0;i<V;i++){
        if(tableWeight[lastV][i]>-1&&!choose[i]){
            if(tableWeight[lastV][i])
        }
    }
}
int main(){
    cin >> V >> E;
    int x,w,y;
    tableWeight = vector<vector<int>>(V,vector<int>(V,-1));
    for(int i = 0 ;i<8;i++){
        cin >> x;
        Ans[i] = x;
    }
    for(int i = 0;i<E;i++){
        cin >> w >> x >> y;
        tableWeight[x][y] = w;
        tableWeight[y][x] = w;
    }

}