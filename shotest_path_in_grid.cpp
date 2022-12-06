#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;
int rowww,columnnn;
char ch;
vector<vector<char>> table;
vector<vector<int>> ds;
auto cmp = [](const pair<int,pair<int,int>> &lhs,const pair<int,pair<int,int>> &rhs){
    if(lhs.first==rhs.first){
        return lhs.second>rhs.second;
    }
    else{
        return lhs.first>rhs.first;
    }
};
    
void calculateTable(int row,int column){
    //vector<int> vec(row*column,std::numeric_limits<int>::max());
    //vec[0] = 0;
    ds[row][column] = 0;
    std::priority_queue<pair<int,pair<int,int>>, std::vector<pair<int,pair<int,int>>>, decltype(cmp)> pq(cmp);
    pq.push(make_pair(0,make_pair(row,column))); 
    while(!pq.empty()){
        pair<int,int> point = pq.top().second; pq.pop();
        int urow = point.first;
        int ucolumn = point.second;
        if(urow-1>=0&&table[urow-1][ucolumn]!='#'&&ds[urow-1][ucolumn]>ds[urow][ucolumn]+1){
            ds[urow-1][ucolumn] = ds[urow][ucolumn]+1;
             pq.push(make_pair(ds[urow-1][ucolumn],make_pair(urow-1,ucolumn)));
        }
        if(ucolumn-1>=0&&table[urow][ucolumn-1]!='#'&&ds[urow][ucolumn-1]>ds[urow][ucolumn]+1){
            ds[urow][ucolumn-1] = ds[urow][ucolumn]+1;
             pq.push(make_pair(ds[urow][ucolumn-1],make_pair(urow,ucolumn-1)));
        }
        if(urow+1<rowww&&table[urow+1][ucolumn]!='#'&&ds[urow+1][ucolumn]>ds[urow][ucolumn]+1){
            ds[urow+1][ucolumn] = ds[urow][ucolumn]+1;
             pq.push(make_pair(ds[urow+1][ucolumn],make_pair(urow+1,ucolumn)));
        }
        if(ucolumn+1<columnnn&&table[urow][ucolumn+1]!='#'&&ds[urow][ucolumn+1]>ds[urow][ucolumn]+1){
            ds[urow][ucolumn+1] = ds[urow][ucolumn]+1;
             pq.push(make_pair(ds[urow][ucolumn+1],make_pair(urow,ucolumn+1)));
        }
    }


}
int main(){
    cin >> rowww >> columnnn;
    table = vector<vector<char>>(rowww,vector<char>(columnnn,' '));
    ds = vector<vector<int>>(rowww,vector<int>(columnnn,20000000));
    for(int i = 0;i<rowww;i++){
        for(int j = 0;j<columnnn;j++){
            cin >> ch;
            table[i][j] = ch;
        }
    }
    calculateTable(0,0);
    if(ds[rowww-1][columnnn-1]>=20000000){
        cout << -1;
    }
    else{
        cout << ds[rowww-1][columnnn-1];
    }
}