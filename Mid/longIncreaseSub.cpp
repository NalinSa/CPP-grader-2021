#include <iostream>
#include<vector>
#include<map>
using namespace std;
vector<map<int,int>> dp(1000);
vector<map<int,bool>> dpBool(1000);
int longInSub(vector<int>& v,int idx, int before){
    if(idx==v.size()){
        return 0;
    }
    if(dpBool[idx][before]==true){
        return dp[idx][before];
    }
    dpBool[idx][before] = true;
    if(v[idx]>=before){
         int ans = max(1+longInSub(v,idx+1,v[idx]),longInSub(v,idx+1,before));
         dp[idx][before] = ans;
        return ans;
    }
    int ans = longInSub(v,idx+1,before);
    dp[idx][before] = ans;
    return ans;
}

int main(){
    int n,x;
    cin >> n;
    vector<int> vec(n);
    for(int i = 0;i<n;i++){
        cin >> x;
        vec[i] = x;
    }
    int ans = longInSub(vec,0,0);
    cout << ans;
}