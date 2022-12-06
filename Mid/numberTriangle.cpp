#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
int vec[101][101];
int dp[101][101];
int n;
int cala(int row,int column){
    if(row==n) return 0;
    if(dp[row][column]>-1) return dp[row][column];
    dp[row][column] = max(cala(row+1,column)+vec[row+1][column],cala(row+1,column+1)+vec[row+1][column+1]);
    return dp[row][column];
}
int main(){
    int x;
    cin >> n;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=i;j++){
            cin >> x;
            vec[i][j] = x;
            dp[i][j] = -1;
        }
    }
    cout << vec[1][1] + cala(1,1);
}