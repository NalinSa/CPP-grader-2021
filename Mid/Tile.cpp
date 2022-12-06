#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int dp[11][10001];
int boolDp[11][10001];
int cal(int idx,int total,vector<int>& tmp){
     cout << total << endl;
    if(idx==-1&&total!=0){
        return 100000;
    }
    else if(idx==-1&&total==0){
        return 0;
    }
    if(boolDp[idx][total]){
        return dp[idx][total];
    }
    int least = (tmp[idx]-1)*(tmp[idx]-1)+cal(idx-1,total-1,tmp);
    int count = 2;
    while(count*count<=total){
        least = min(least,(tmp[idx]-count)*(tmp[idx]-count)+cal(idx-1,total-count*count,tmp));
        count++;
    }
    boolDp[idx][total] = true;
    dp[idx][total] = least;
    return least;
}
int main(){
    int n,m,x;
    cin >> n >> m;
    vector<int> vec(n);
    for(int i =0;i<n;i++){
        cin >>x;
        vec[i] = x;
    }
    int ans = cal(n-1,m,vec);
    if(ans >= 100000){
        cout << "-1";
    }
    else{
        cout << ans;
    }

}