#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n,m,x;
    cin >> n >> m;
    vector<int> value(n+1);
    vector<int> weight(n+1);
    int dp[n+1][m+1];
    for(int i = 1;i<=n;i++){
        cin >> x;
        value[i] = x;
        
    }
    for(int i = 1;i<=n;i++){
        cin >> x;
        weight[i] = x;
    }
    for(int i = 0 ; i<=n;i++){
        for(int j = 0;j<=m;j++){
            cin >> x;
            dp[i][j] = x;
            //cout << x << " - ";
            
        }
    }
    int remain = m;
    int total = dp[n][m];
    vector<int> choose;
    for(int i = n;i>0;i--){
        //cout << total << " - " << value[i] << "==" << dp[i-1][m-weight[i]]<< endl;
        if(total - value[i]==dp[i-1][remain-weight[i]]){
            
            choose.push_back(i);
            total -= value[i];
            remain -= weight[i];
        }
        if(total == 0){
            break;
        }
    }
    cout << choose.size() << "\n";
    for(auto &val:choose){
        cout << val << " ";
    }
}