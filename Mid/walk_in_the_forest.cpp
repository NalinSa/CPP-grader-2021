#include <iostream>
#include <vector>
using namespace std;
int forest[501][501];
int dp[501][501];
int findForest(int row ,int column){
    if(row==1&&column==1){
        return forest[1][1];
    }
    if(row<1||column<1){
        return 0;
    }
    if(dp[row][column]>0) return dp[row][column];
    int one = findForest(row,column-1);
    one = (one==0)? 0 : one+forest[row][column];
    //cout << "one" << one << endl;
    int two = findForest(row-1,column);
    two = (two==0)? 0 : two+forest[row][column];
     //cout << "two" << two << endl;
    int three = findForest(row-1,column-1);
    three = (three==0)? 0 : three+forest[row][column]*2;
    //cout << "three" << three << endl;
    int most = max(one,two);
    most = max(most,three);
    dp[row][column] = most;
    return most;
}
int main(){
    int n,m,x;
    cin >> n >>m;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            cin >> x;
            forest[i][j] = x;
        }
    }
    cout << findForest(n,m);
}