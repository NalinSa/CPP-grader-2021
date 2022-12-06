#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
int n,x;
int vec[10001];
int dp[10001];
int findMost(int idx){
    if(idx<=-1){
        return 0;
    }
    if(dp[idx]>-1) return dp[idx];
    dp[idx] = max(vec[idx]+findMost(idx-3),findMost(idx-1));
    return dp[idx];
}
int main(){
    cin >> n;
    for(int i = 0;i<n;i++){
        cin >> x;
        vec[i] = x;
        dp[i] = -1;
    }
    cout << findMost(n-1);
}