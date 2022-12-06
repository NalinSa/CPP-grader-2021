#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<vector<int>> w;
vector<vector<int>> d;
int inf = 2000000;
int N ,a,b,x,y,row,column;
auto cmp = [](const pair<int,pair<int,int>> &lhs, const pair<int,pair<int,int>> &rhs){
    return lhs>rhs;
};
void disktra(){
    int minuse = inf;
    d[a][b] = 0;
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>, decltype(cmp)> pq(cmp);
    pq.push(make_pair(0,make_pair(a,b)));
    while(!pq.empty()&&pq.top().first<minuse){
        row = pq.top().second.first;
        column = pq.top().second.second;pq.pop();
        if(row-1<1){
            minuse = min(d[row][column],minuse);
        }
        else{
            if(w[row-1][column]+d[row][column]<d[row-1][column]){
                d[row-1][column] = w[row-1][column]+d[row][column];
                pq.push(make_pair(d[row-1][column],make_pair(row-1,column)));
            }
        }
        if(column-1<1){
            minuse = min(d[row][column],minuse);
        }
        else{
            if(w[row][column-1]+d[row][column]<d[row][column-1]){
                d[row][column-1] = w[row][column-1]+d[row][column];
                pq.push(make_pair(d[row][column-1],make_pair(row,column-1)));
            }
        }
        if(row+1>1000){
            minuse = min(d[row][column],minuse);
        }
        else{
            if(w[row+1][column]+d[row][column]<d[row+1][column]){
                d[row+1][column] = w[row+1][column]+d[row][column];
                pq.push(make_pair(d[row+1][column],make_pair(row+1,column)));
            }
        }
        if(column+1>1000){
            minuse = min(d[row][column],minuse);
        }
        else{
            if(w[row][column+1]+d[row][column]<d[row][column+1]){
                d[row][column+1] = w[row][column+1]+d[row][column];
                pq.push(make_pair(d[row][column+1],make_pair(row,column+1)));
            }
        }
    }

    cout << minuse;

}
int main(){
    cin >> N >> a >> b;
    w = vector<vector<int>>(1001,vector<int>(1001));
    d = vector<vector<int>>(1001,vector<int>(1001,inf));
    while(N--){
        cin >> x >> y;
        w[x][y] = 1;
    }
    disktra();
}