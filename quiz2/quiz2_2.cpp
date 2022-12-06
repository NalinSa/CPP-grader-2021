#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
int n;
int vec[500001];
int cala(int begin,int idx){
    if(idx==begin) return vec[begin];
    return max(vec[idx]+cala(begin,idx-1),vec[idx]);
}
int mss(int begin,int idx){
    if(idx==begin){ 
        return vec[begin];
    }
    int left = mss(begin,idx-1);
    int right = vec[idx];
    int bt = cala(begin,idx-1)+vec[idx];
    return max(left,max(right,bt));
}


int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    int x;
    for(int i = 0;i<n;i++){
        cin >> x;
        vec[i] = x;
    }
    int ans = 0;
    for(int i = 0;i<n-1;i++){
        int left = mss(0,i);
        int right = mss(i+1,n-1);
        int bt = left+right;
        ans = max(ans,max(left,max(right,bt)));
    }
    cout << ans;
}