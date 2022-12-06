#include <iostream>
using namespace std;
int n,k;
bool boo[501][501];
int dp[501][501];
int divide(int idx,int remain){
    if(idx<=0){
        if(remain==0){
            return 1;
        }
        else return 0;
    }
    int total = 0;
    if(boo[idx][remain]) return dp[idx][remain];
    for(int i = k;i>remain;i--){
        total = ((total%1997)+(divide(idx-1,remain)%1997))%1997;
    }
    if(remain>0){
        total = ((total%1997)+(divide(idx-1,remain-1)%1997))%1997;
    }
    boo[idx][remain] = true;
    dp[idx][remain] = total;
    return total;
}


int main(){
    cin >> n >> k;
    cout << divide(n,k);
}